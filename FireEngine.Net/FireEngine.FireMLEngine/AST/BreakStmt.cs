using System;
using System.Collections.Generic;
using System.Text;

namespace FireEngine.FireMLEngine.AST
{
    [Serializable]
    public class BreakStmt : Statement
    {
        internal override void Accept(IASTVisitor visitor, params object[] args)
        {
            visitor.Visit(this, args);
        }
    }


}
