//
//  ExprProcessor.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-27.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_ExprProcessor_h
#define BolognieTouch_iOS_ExprProcessor_h

#include "IExprVisitor.h"
#include "RightValue.h"
#include "Expression.h"
#include "LeftValue.h"
#include "LeftValueExpr.h"
#include <string>

namespace FireMLEngine {
    
    class RuntimeKernel;
    class ScopeStack;
    
    class ExprProcessor : public IExprVisitor {
        
    private:
        RuntimeKernel* kernel;
        ScopeStack* scopeStack;
        
        FireMLDataType getAlgoResultType(const RightValue& v1, const RightValue& v2);
        
        /**
         return a pointer to the existing right value. (no deep clone!)
         */
        const RightValue* readRightValue(Expression* expr);
        const RightValue* readRightValue(LeftValue* leftValue);
        
        
        
    public:
        ExprProcessor(RuntimeKernel* kernel);
        std::string evalStr(Expression* expr);
        
        /**
         No deep clone!!
         */
        const RightValue* eval(Expression* expr);
        
        std::string getVarName(LeftValueExpr* expr);
        
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
        virtual void visit(SubExpr* subExpr);
        virtual void visit(RightValueExpr* rightValueExpr);
    };
}

#endif
