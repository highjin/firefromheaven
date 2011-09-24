using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using FireEngine.FireMLEngine.Compiler;
using FireEngine.FireMLEngine;
using FireEngine.FireML.Editor;
using MongoDB.Bson.Serialization;
using MongoDB.Bson.IO;

namespace FireEngine.FireML.Editor
{
    //生成用于iOS的二进制脚本
    class Program
    {
        static void Main(string[] args)
        {
            FileInfo assemblyFileInfo = new FileInfo(args[0]);
            string savePath = args[1];

            DirectoryInfo fireMLDirInfo = assemblyFileInfo.Directory;
            DirectoryInfo contentDirInfo = fireMLDirInfo.Parent;

            List<string> plotFileList = new List<string>();
            List<string> assetFileList = new List<string>();
            foreach (FileInfo fileInfo in fireMLDirInfo.GetFiles("*.*", SearchOption.AllDirectories))
            {
                string ext = fileInfo.Extension;
                if (ext == ".fmlplot")
                {
                    plotFileList.Add(fileInfo.FullName);
                }
                else if (ext == ".fmlasset")
                {
                    assetFileList.Add(fileInfo.FullName);
                }
            }

            string xsdDirPath = fireMLDirInfo.FullName + "\\" + "XSD";

            //FireEngine.XNAContent.ContentManager contentManager = new FireEngine.XNAContent.ContentManager(contentDirInfo.FullName);
            CompilerKernel kernel = new CompilerKernel(plotFileList.ToArray(), assetFileList.ToArray(), xsdDirPath, null /*contentManager*/);
            FireMLRoot result = kernel.CompileFireML();

            Error[] errors = kernel.CheckPoint();

            foreach (Error e in errors)
            {
                Console.WriteLine("{0}\n{1},{2}\n{3}", e.Location.FileName, e.Location.Line, e.Location.Column, e.Message);
                Console.WriteLine();
            }

            if (errors.Length > 0)
            {
                Environment.Exit(-1);
                return;
            }

            /*JsonWriterSettings jsonSettings = new JsonWriterSettings();
            jsonSettings.NewLineChars = "\r\n";
            jsonSettings.OutputMode = JsonOutputMode.JavaScript;
            jsonSettings.Indent = true;
            jsonSettings.IndentChars = "  ";
            StreamWriter streamWriter = new StreamWriter(new FileStream("out.txt", FileMode.Create));
            JsonWriter jsonWriter = new JsonWriter(streamWriter, jsonSettings);
            BsonSerializer.Serialize<FireMLRoot>(jsonWriter, result);
            jsonWriter.Close();*/

            Stream bsonStream = new FileStream(savePath, FileMode.Create);
            BsonBuffer bsonBuffer = new BsonBuffer();
            BsonBinaryWriterSettings bsonSettings = new BsonBinaryWriterSettings();
            BsonBinaryWriter bsonWriter = new BsonBinaryWriter(bsonStream, bsonBuffer, bsonSettings);
            BsonSerializer.Serialize<FireMLRoot>(bsonWriter, result);
            bsonWriter.Close();
        }

        
    }
}
