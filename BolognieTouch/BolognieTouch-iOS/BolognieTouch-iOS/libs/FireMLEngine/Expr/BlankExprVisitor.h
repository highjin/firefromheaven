//
//  BlankExprVisitor.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-25.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_BlankExprVisitor_h
#define BolognieTouch_iOS_BlankExprVisitor_h

#include "IExprVisitor.h"

namespace FireMLEngine {
    class BlankExprVisitor : public IExprVisitor {
        virtual void visit(AddExpr* addExpr);
        virtual void visit(AndExpr* andExpr);
        virtual void visit(AssignExpr* assignExpr);
        virtual void visit(DivExpr* divExpr);
        virtual void visit(EquExpr* equExpr);
        virtual void visit(GreatEquExpr* greatEquExpr);
        virtual void visit(GreatExpr* greatExpr);
        virtual void visit(LeftValueExpr* leftValueExpr);
        virtual void visit(LessEquExpr* lessEquExpr);
        virtual void visit(LessExpr* lessExpr);
        virtual void visit(MulExpr* mulExpr);
        virtual void visit(NegativeExpr* negativeExpr);
        virtual void visit(NeqExpr* neqExpr);
        virtual void visit(NotExpr* notExpr);
        virtual void visit(OrExpr* orExpr);
        virtual void visit(PowExpr* powExpr);
        virtual void visit(RightValueExpr* rightValueExpr);
        virtual void visit(SubExpr* subExpr);
    };
}


#endif
