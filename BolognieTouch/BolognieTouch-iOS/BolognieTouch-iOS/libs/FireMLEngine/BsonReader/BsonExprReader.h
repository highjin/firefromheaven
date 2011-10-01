//
//  BsonExprReader.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-26.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_BsonExprReader_h
#define BolognieTouch_iOS_BsonExprReader_h

#include "BsonReaderMacro.h"
#include "IExprVisitor.h"
#include "Expression.h"
#include "MonoExpr.h"
#include "BinaryExpr.h"
#include "LeftValue.h"
#include <stack>

namespace FireMLEngine {
    class BsonExprReader : public IExprVisitor {
    private:
        std::stack<bson_iterator*> bsonItStack;
        void visitMonoExpr(MonoExpr* monoExpr);
        void visitBinaryExpr(BinaryExpr* binaryExpr);
        
        /**
         read the right value (const) and return a new RightValue object. "it" should be pointed to the RightValue bson object, retrieved by bson_iterator_subiterator (not statement, not array). Caller's responsibility to delete this rightvalue when it is not used anymore. 
         */
        RightValue* readRightValue(bson_iterator* it);
        LeftValue* readLeftValue(bson_iterator* it);
        
    public:
        /**
         Read the expression at it and return a new expression object. "it" should be pointed to the expression bson object, retrieved by bson_iterator_subiterator (not statement, not array). Caller's responsibility to delete this expression when it is not used anymore. 
         */
        Expression* readExpr(bson_iterator* it);
        
        /**
         Explicitly assign _t in case there is no _t in bson. (i.e ReturnDest)
         */
        Expression* readExpr(bson_iterator* it, const char* _t);
        
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
