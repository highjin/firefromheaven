using System;
using System.Collections.Generic;
using System.Text;

namespace FireEngine.FireMLEngine.AST
{
    [Serializable]
    public class IncludeStmt : Statement
    {
        public string SubPlot
        {
            get;
            set;
        }

        internal override void Accept(IASTVisitor visitor, params object[] args)
        {
            visitor.Visit(this, args);
        }
    }
}
