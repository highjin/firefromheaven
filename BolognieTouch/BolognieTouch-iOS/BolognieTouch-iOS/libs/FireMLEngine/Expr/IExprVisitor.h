//
//  IExprVisitor.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-25.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_IExprVisitor_h
#define BolognieTouch_iOS_IExprVisitor_h

#define EXPR_ACCEPT_FUNC    virtual void accept(IExprVisitor* visitor) { \
                                visitor->visit(this); \
                            }

namespace FireMLEngine {
    
    class AddExpr;
    class AndExpr;
    class AssignExpr;
    class DivExpr;
    class EquExpr;
    class GreatEquExpr;
    class GreatExpr;
    class LeftValueExpr;
    class LessEquExpr;
    class LessExpr;
    class MulExpr;
    class NegativeExpr;
    class NeqExpr;
    class NotExpr;
    class OrExpr;
    class PowExpr;
    class RightValueExpr;
    class SubExpr;
    
    class IExprVisitor {
    public:
        virtual void visit(AddExpr* addExpr) = 0;
        virtual void visit(AndExpr* andExpr) = 0;
        virtual void visit(AssignExpr* assignExpr) = 0;
        virtual void visit(DivExpr* divExpr) = 0;
        virtual void visit(EquExpr* equExpr) = 0;
        virtual void visit(GreatEquExpr* greatEquExpr) = 0;
        virtual void visit(GreatExpr* greatExpr) = 0;
        virtual void visit(LeftValueExpr* leftValueExpr) = 0;
        virtual void visit(LessEquExpr* lessEquExpr) = 0;
        virtual void visit(LessExpr* lessExpr) = 0;
        virtual void visit(MulExpr* mulExpr) = 0;
        virtual void visit(NegativeExpr* negativeExpr) = 0;
        virtual void visit(NeqExpr* neqExpr) = 0;
        virtual void visit(NotExpr* notExpr) = 0;
        virtual void visit(OrExpr* orExpr) = 0;
        virtual void visit(PowExpr* powExpr) = 0;
        virtual void visit(RightValueExpr* rightValueExpr) = 0;
        virtual void visit(SubExpr* subExpr) = 0;
    };
}

#endif
