using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using FireEngine.FireMLEngine.AST;
using MongoDB.Bson;

namespace FireEngine.FireMLEngine.Bson
{
    class BsonExporterASTVisitor : IASTVisitor 
    {
        private FireMLRoot fireMLRoot;
        private Stack<BsonDocument> parentStack;
        private BsonDocument bsonRoot;

        public BsonExporterASTVisitor(FireMLRoot root)
        {
            parentStack = new Stack<BsonDocument>();
            fireMLRoot = root;
            fireMLRoot.Accept(this);
        }

        public void Visit(FireMLRoot root, object[] args)
        {
            bsonRoot = new BsonDocument();

            BsonDocument mainPlot = new BsonDocument();
            parentStack.Push(mainPlot);
            //MainPlot
            root.MainPlot.Accept(this);
            parentStack.Pop();
            bsonRoot.Add("mainPlot", mainPlot);

            /*
            //SubPlot
            BsonDocument subPlotMap = new BsonDocument();
            foreach (KeyValuePair<string, PlotDef> plotDefEntry in root.SubPlotMap)
            {
                BsonDocument subPlot = new BsonDocument();

                parentStack.Push(subPlot);
                plotDefEntry.Value.Accept(this);
                parentStack.Pop();

                subPlotMap.Add(plotDefEntry.Key, subPlot);
            }
            bsonRoot.Add("subPlotMap", subPlotMap);

            //FuncDef
            BsonDocument funcDefMap = new BsonDocument();
            foreach (KeyValuePair<string, FunctionDef> funcDefEntry in root.FuncDefMap)
            {
                BsonDocument funcDef = new BsonDocument();

                parentStack.Push(funcDef);
                funcDefEntry.Value.Accept(this);
                parentStack.Pop();

                funcDefMap.Add(funcDefEntry.Key, funcDef);
            }
            bsonRoot.Add("funcDefMap", funcDefMap);
            */

            //ActionLayer
            //Asset

            //No need for NodeMap. Regenerate in runtime
        }

        public void Visit(ActionLayerDef actionLayerDef, object[] args)
        {
            throw new NotImplementedException();
        }

        public void Visit(FunctionDef functionDef, object[] args)
        {
            throw new NotImplementedException();
        }

        public void Visit(PlotDef plotDef, object[] args)
        {
            parentStack.Peek().Add("id", plotDef.ID);

            BsonArray content = new BsonArray();
            foreach (Statement statement in plotDef.Content)
            {
                BsonDocument bsonStatement = new BsonDocument();
                
                parentStack.Push(bsonStatement);
                statement.Accept(this);
                parentStack.Pop();

                content.Add(bsonStatement);
            }
            parentStack.Peek().Add("content", content);
        }

        public void Visit(ContinueStmt continueStmt, object[] args)
        {
            throw new NotImplementedException();
        }

        public void Visit(FunctionCallStmt funcCallStmt, object[] args)
        {
            throw new NotImplementedException();
        }

        public void Visit(MusicStmt musicStmt, object[] args)
        {
            throw new NotImplementedException();
        }

        public void Visit(MusicStopStmt musicStopStmt, object[] args)
        {
            throw new NotImplementedException();
        }

        public void Visit(MusicVolStmt musicVolStmt, object[] args)
        {
            throw new NotImplementedException();
        }

        public void Visit(SwitchStmt switchStmt, object[] args)
        {
            throw new NotImplementedException();
        }

        public void Visit(SelectStmt selectStmt, object[] args)
        {
            throw new NotImplementedException();
        }

        public void Visit(ActorStmt actorStmt, object[] args)
        {
            parentStack.Peek().Add("id", actorStmt.ID)
                .Add("img", new BsonString(actorStmt.Img))
                .Add("asset", new BsonString(actorStmt.Asset))
                .Add("avatar", new BsonString(actorStmt.Avatar))
                .Add("avaAsset", new BsonString(actorStmt.AvaAsset))
                .Add("layer", new BsonString(actorStmt.Layer))
                .Add
        }

        public void Visit(DialogStmt dialogStmt, object[] args)
        {
            throw new NotImplementedException();
        }

        public void Visit(IfStmt ifStmt, object[] args)
        {
            throw new NotImplementedException();
        }

        public void Visit(LoopStmt loopStmt, object[] args)
        {
            throw new NotImplementedException();
        }

        public void Visit(BackgroundStmt backgroundStmt, object[] args)
        {
            parentStack.Peek().Add("id", backgroundStmt.ID)
                .Add("img", new BsonString(backgroundStmt.Img))
                .Add("asset", new BsonString(backgroundStmt.Asset));
        }

        public void Visit(EchoStmt echoStmt, object[] args)
        {
            throw new NotImplementedException();
        }

        public void Visit(IncludeStmt includeStmt, object[] args)
        {
            throw new NotImplementedException();
        }

        public void Visit(BreakStmt breakStmt, object[] args)
        {
            throw new NotImplementedException();
        }

        public void Visit(ExpressionStmt expressionStmt, object[] args)
        {
            throw new NotImplementedException();
        }

        public void Visit(ReturnStmt returnStmt, object[] args)
        {
            throw new NotImplementedException();
        }

        public void Visit(ParameterDef parameterDef, object[] args)
        {
            throw new NotImplementedException();
        }

        public void Visit(SelectOption selectOption, object[] args)
        {
            throw new NotImplementedException();
        }

        public void Visit(SwitchCase switchCase, object[] args)
        {
            throw new NotImplementedException();
        }

        public void Visit(IfBlock ifBlock, object[] args)
        {
            throw new NotImplementedException();
        }

        public void Visit(DataStmt dataStmt, object[] args)
        {
            throw new NotImplementedException();
        }

        public void Visit(AssetDef assetDef, object[] args)
        {
            throw new NotImplementedException();
        }
    }
}
