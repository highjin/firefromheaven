using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using MongoDB.Bson;
using MongoDB.Bson.IO;

namespace FireEngine.Test.BsonTest
{
    class Program
    {
        static void Main(string[] args)
        {
            BsonDocument doc = new BsonDocument();
            doc.Add("str1", "Hello");
            doc.Add("str2", "World!");
            doc.Add("int1", 1);
            doc.Add("float1", 1.5);

            BsonArray array = new BsonArray(new int[] { 1, 2, 3, 4, 5, 6 });
            doc.Add("array1", array);

            doc.WriteTo("result.bin");

            //Console.WriteLine(doc.ToJson());

            BsonDocument res = BsonDocument.ReadFrom("result.bin");
            Console.WriteLine(res.ToJson());
        }
    }
}
