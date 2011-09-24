using System;
using System.Collections.Generic;
using System.Text;
using FireEngine.FireMLEngine.AST;

namespace FireEngine.FireMLEngine
{
    [Serializable]
    public class FireMLRoot
    {
        public PlotDef MainPlot { get; set; }
        public Dictionary<string, PlotDef> SubPlotMap { get; set; }
        public Dictionary<string, FunctionDef> FuncDefMap { get; set; }
        public Dictionary<string, ActionLayerDef> ActionLayerMap { get; set; }
        public Dictionary<string, AssetDef> AssetMap { get; set; }

        //do not serialize
        internal Dictionary<int, ASTNode> NodeMap { get; set; }

        internal FireMLRoot()
        {
            SubPlotMap = new Dictionary<string, PlotDef>();
            FuncDefMap = new Dictionary<string, FunctionDef>();
            ActionLayerMap = new Dictionary<string, ActionLayerDef>();
            NodeMap = new Dictionary<int, ASTNode>();
            AssetMap = new Dictionary<string, AssetDef>();
        }

        internal void Accept(IASTVisitor visitor, params object[] args)
        {
            visitor.Visit(this, args);
        }
    }
}
