//
//  BsonExprReader.cpp
//  BolognieTouch-iOS
//
//  Created by  on 11-9-26.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#include <assert.h>

#include "BsonExprReader.h"
#include "AddExpr.h"
#include "AndExpr.h"
#include "AssignExpr.h"
#include "DivExpr.h"
#include "EquExpr.h"
#include "GreatEquExpr.h"
#include "GreatExpr.h"
#include "LeftValueExpr.h"
#include "LessEquExpr.h"
#include "LessExpr.h"
#include "MulExpr.h"
#include "NegativeExpr.h"
#include "NeqExpr.h"
#include "NotExpr.h"
#include "OrExpr.h"
#include "PowExpr.h"
#include "RightValueExpr.h"
#include "SubExpr.h"

using namespace FireMLEngine;

Expression* BsonExprReader::readExpr(bson_iterator *it) {
    const char* _t = bson_iterator_string(it);  //assuming _t is the first element
    Expression* expr;
    
    if (STR_EQUALS(_t, "AddExpr")) { expr = new AddExpr(); }
    else if (STR_EQUALS(_t, "AndExpr")) { expr = new AndExpr(); }
    else if (STR_EQUALS(_t, "AssignExpr")) { expr = new AssignExpr(); }
    else if (STR_EQUALS(_t, "DivExpr")) { expr = new DivExpr(); }
    else if (STR_EQUALS(_t, "EquExpr")) { expr = new EquExpr(); }
    else if (STR_EQUALS(_t, "GreatEquExpr")) { expr = new GreatEquExpr(); }
    else if (STR_EQUALS(_t, "GreatExpr")) { expr = new GreatExpr(); }
    else if (STR_EQUALS(_t, "LeftValueExpr")) { expr = new LeftValueExpr(); }
    else if (STR_EQUALS(_t, "LessEquExpr")) { expr = new LessEquExpr(); }
    else if (STR_EQUALS(_t, "LessExpr")) { expr = new LessExpr(); }
    else if (STR_EQUALS(_t, "MulExpr")) { expr = new MulExpr(); }
    else if (STR_EQUALS(_t, "NegativeExpr")) { expr = new NegativeExpr(); }
    else if (STR_EQUALS(_t, "NeqExpr")) { expr = new NeqExpr(); }
    else if (STR_EQUALS(_t, "NotExpr")) { expr = new NotExpr(); }
    else if (STR_EQUALS(_t, "OrExpr")) { expr = new OrExpr(); }
    else if (STR_EQUALS(_t, "PowExpr")) { expr = new PowExpr(); }
    else if (STR_EQUALS(_t, "SubExpr")) { expr = new SubExpr(); }
    
    bsonItStack.push(it);
    expr->accept(this);
    bsonItStack.pop();
    
    return expr;
}

void BsonExprReader::visitMonoExpr(MonoExpr* monoExpr) {
    bson_iterator* it = bsonItStack.top();
    
    while (bson_iterator_next(it)) {
        BSON_KEY_AND_TYPE(it);
        if (BSON_KEY_IS("DataType")) {
            monoExpr->dataType = (FireMLDataType)bson_iterator_int(it);
        } else if (BSON_KEY_IS("RightValue")) {
            if (type != BSON_NULL) {
                bson_iterator rightValueIt;
                bson_iterator_subiterator(it, &rightValueIt);
                monoExpr->setRightValue(readRightValue(&rightValueIt));
            }
        } else if (BSON_KEY_IS("Op")) {
            if (type != BSON_NULL) {
                bson_iterator opIt;
                bson_iterator_subiterator(it, &opIt);
                monoExpr->setOp(readExpr(&opIt));
            }
        }
    }
}

void BsonExprReader::visitBinaryExpr(BinaryExpr* binaryExpr) {
    bson_iterator* it = bsonItStack.top();
    
    while (bson_iterator_next(it)) {
        BSON_KEY_AND_TYPE(it);
        if (BSON_KEY_IS("DataType")) {
            binaryExpr->dataType = (FireMLDataType)bson_iterator_int(it);
        } else if (BSON_KEY_IS("RightValue")) {
            if (type != BSON_NULL) {
                bson_iterator rightValueIt;
                bson_iterator_subiterator(it, &rightValueIt);
                binaryExpr->setRightValue(readRightValue(&rightValueIt));
            }
        } else if (BSON_KEY_IS("FirstOp")) {
            if (type != BSON_NULL) {
                bson_iterator opIt;
                bson_iterator_subiterator(it, &opIt);
                binaryExpr->setFirstOp(readExpr(&opIt));
            }
        } else if (BSON_KEY_IS("SecondOp")) {
            if (type != BSON_NULL) {
                bson_iterator opIt;
                bson_iterator_subiterator(it, &opIt);
                binaryExpr->setSecondOp(readExpr(&opIt));
            }            
        }
    }   
}

RightValue* BsonExprReader::readRightValue(bson_iterator *it) {
    const char* _t = bson_iterator_string(it);
    bson_iterator_next(it); //assuming value is the next element
    
    if (STR_EQUALS(_t, "IntConst")) {
        IntConst* intConst = new IntConst();
        intConst->value = bson_iterator_int(it);
        return intConst;
    } else if (STR_EQUALS(_t, "FloatConst")) {
        FloatConst* floatConst = new FloatConst();
        floatConst->value = (float)bson_iterator_double(it);
        return floatConst;
    } else if (STR_EQUALS(_t, "StringConst")) {
        StringConst* strConst = new StringConst();
        strConst->value = bson_iterator_string(it);
        return strConst;
    } else {
        assert(0);
        return NULL;
    }
}

void BsonExprReader::visit(AddExpr* addExpr) { }
void BsonExprReader::visit(AndExpr* andExpr) { }
void BsonExprReader::visit(AssignExpr* assignExpr) { }
void BsonExprReader::visit(DivExpr* divExpr) { }
void BsonExprReader::visit(EquExpr* equExpr) { }
void BsonExprReader::visit(GreatEquExpr* greatEquExpr) { }
void BsonExprReader::visit(GreatExpr* greatExpr) { }
void BsonExprReader::visit(LeftValueExpr* leftValueExpr) { }
void BsonExprReader::visit(LessEquExpr* lessEquExpr) { }
void BsonExprReader::visit(LessExpr* lessExpr) { }
void BsonExprReader::visit(MulExpr* mulExpr) { }
void BsonExprReader::visit(NegativeExpr* negativeExpr) { }
void BsonExprReader::visit(NeqExpr* neqExpr) { }
void BsonExprReader::visit(NotExpr* notExpr) { }
void BsonExprReader::visit(OrExpr* orExpr) { }
void BsonExprReader::visit(PowExpr* powExpr) { }
void BsonExprReader::visit(RightValueExpr* rightValueExpr) { }
void BsonExprReader::visit(SubExpr* subExpr) { }