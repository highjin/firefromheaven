//
//  ExprProcessor.cpp
//  BolognieTouch-iOS
//
//  Created by  on 11-9-27.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#include <math.h>

#include "ExprProcessor.h"

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
#include "FireMLDataType.h"

#include "RuntimeKernel.h"
using namespace FireMLEngine;
using namespace std;

ExprProcessor::ExprProcessor(RuntimeKernel* kernel) : kernel(kernel), scopeStack(&(kernel->getRuntimeData()->getScopeStack())) { }

const RightValue* ExprProcessor::readRightValue(Expression* expr) {
    if (expr->getExpressionType() == LeftValueExprType) {
        return readRightValue(((LeftValueExpr*)expr)->getLeftValue());
    } else if (expr->getExpressionType() == RightValueExprType) {
        return (((RightValueExpr*)expr)->getRightValue());
    }
    
    assert(0);  //never reach here
    return NULL;
}

const RightValue* ExprProcessor::readRightValue(LeftValue* leftValue) {
    if (leftValue->getLeftValueType() == VarRefType) {
        VarRef* var = (VarRef*)leftValue;
        const RightValue* result = scopeStack->getValue(var->varName);
        if (result == NULL) {
            assert(0);  //variable not found
        } else {
            return result;
        }
    }
    
    assert(0);  //never reach here
    return NULL;
}

const RightValue* ExprProcessor::eval(Expression* expr) {
    expr->accept(this);
    return readRightValue(expr);
}

std::string ExprProcessor::evalStr(Expression* expr) {
    return eval(expr)->toString();
}

std::string ExprProcessor::getVarName(LeftValueExpr* expr) {
    if (expr == NULL || expr->getLeftValue() == NULL) {
        return "";
    }
    
    LeftValue* leftValue = expr->getLeftValue();
    if (leftValue->getLeftValueType() == VarRefType) {
        return ((VarRef*)leftValue)->varName;
    }
    
    assert(0);  //never reach here
    return "";
}

FireMLDataType ExprProcessor::getAlgoResultType(const RightValue& v1, const RightValue& v2) {
    if (v1.getDataType() == Bool || v2.getDataType() == Bool || v1.getDataType() == String || v2.getDataType() == String) {
        assert(0);  //type error
        return Error;
    } else if (v1.getDataType() == Float || v2.getDataType() == Float) {
        return Float;
    } else if (v1.getDataType() == Int && v2.getDataType() == Int) {
        return Int;
    } else {
        assert(0);  //type error
        return Error;
    }
}

void ExprProcessor::visit(AddExpr* addExpr) {
    addExpr->getFirstOp()->accept(this);
    addExpr->getSecondOp()->accept(this);
    
    const RightValue* v1 = readRightValue(addExpr->getFirstOp());
    const RightValue* v2 = readRightValue(addExpr->getSecondOp());
    
    if (v1->getDataType() == String || v2->getDataType() == String) {
        StringConst result;
        result.value = v1->toString() + v2->toString();
        addExpr->setRightValue(&result);    //result will be cloned
    } else {
        FireMLDataType dataType = getAlgoResultType(*v1, *v2);
        if (dataType == Int) {
            IntConst result;
            result.value = v1->toInt() + v2->toInt();
            addExpr->setRightValue(&result);
        } else if (dataType == Float) {
            FloatConst result;
            result.value = v1->toFloat() + v2->toFloat();
            addExpr->setRightValue(&result);
        } else {
            assert(0);  //type error
        }
    }
}
void ExprProcessor::visit(AndExpr* andExpr) { }

void ExprProcessor::visit(AssignExpr* assignExpr) {
    assignExpr->getLeftExpr()->accept(this);
    assignExpr->getRightExpr()->accept(this);
    
    const RightValue* v = readRightValue(assignExpr->getRightExpr());
    assignExpr->setRightValue(v);
    
    if (assignExpr->getLeftExpr()->getLeftValue()->getLeftValueType() == VarRefType) {
        VarRef* varRef = (VarRef*)assignExpr->getLeftExpr()->getLeftValue();
        scopeStack->setValue(varRef->varName, *v);
    } else {
        assert(0);  //never reach here
    }
}

void ExprProcessor::visit(DivExpr* divExpr) {
    divExpr->getFirstOp()->accept(this);
    divExpr->getSecondOp()->accept(this);
    
    const RightValue* v1 = readRightValue(divExpr->getFirstOp());
    const RightValue* v2 = readRightValue(divExpr->getSecondOp());
    
    FireMLDataType dataType = getAlgoResultType(*v1, *v2);
    if (dataType == Int) {
        
        if (v2->toInt() == 0) {
            assert(0);  //divided by zero
        }
        
        IntConst result;
        result.value = v1->toInt() / v2->toInt();
        divExpr->setRightValue(&result);
        
    } else if (dataType == Float) {
        
        if (v2->toFloat() == 0) {
            assert(0);  //divided by zero
        }
        
        FloatConst result;
        result.value = v1->toFloat() / v2->toFloat();
        divExpr->setRightValue(&result);
        
    } else {
        assert(0);  //type error
    }
}

void ExprProcessor::visit(EquExpr* equExpr) { }
void ExprProcessor::visit(GreatEquExpr* greatEquExpr) { }
void ExprProcessor::visit(GreatExpr* greatExpr) { }

void ExprProcessor::visit(LeftValueExpr* leftValueExpr) { 
    
}


void ExprProcessor::visit(LessEquExpr* lessEquExpr) { }
void ExprProcessor::visit(LessExpr* lessExpr) { }

void ExprProcessor::visit(MulExpr* mulExpr) {
    mulExpr->getFirstOp()->accept(this);
    mulExpr->getSecondOp()->accept(this);
    
    const RightValue* v1 = readRightValue(mulExpr->getFirstOp());
    const RightValue* v2 = readRightValue(mulExpr->getSecondOp());
    
    FireMLDataType dataType = getAlgoResultType(*v1, *v2);
    if (dataType == Int) {
        IntConst result;
        result.value = v1->toInt() * v2->toInt();
        mulExpr->setRightValue(&result);
    } else if (dataType == Float) {
        FloatConst result;
        result.value = v1->toFloat() * v2->toFloat();
        mulExpr->setRightValue(&result);
    } else {
        assert(0);  //type error
    }
}

void ExprProcessor::visit(NegativeExpr* negativeExpr) {
    negativeExpr->getOp()->accept(this);
    const RightValue* v = readRightValue(negativeExpr->getOp());
    
    if (v->getDataType() == Int) {
        IntConst result;
        result.value = -(v->toInt());
        negativeExpr->setRightValue(&result);
    } else if (v->getDataType() == Float) {
        FloatConst result;
        result.value = -(v->toFloat());
        negativeExpr->setRightValue(&result);
    } else {
        assert(0);  //type error
    }
}


void ExprProcessor::visit(NeqExpr* neqExpr) { }
void ExprProcessor::visit(NotExpr* notExpr) { }
void ExprProcessor::visit(OrExpr* orExpr) { }
void ExprProcessor::visit(PowExpr* powExpr) {
    powExpr->getFirstOp()->accept(this);
    powExpr->getSecondOp()->accept(this);
    
    const RightValue* v1 = readRightValue(powExpr->getFirstOp());
    const RightValue* v2 = readRightValue(powExpr->getSecondOp());
    
    FireMLDataType dataType = getAlgoResultType(*v1, *v2);
    if (dataType == Int) {
        IntConst result;
        result.value = (int)(pow(v1->toInt(), v2->toInt()) + 0.5);
        powExpr->setRightValue(&result);
    } else if (dataType == Float) {
        FloatConst result;
        result.value = (float)(powf(v1->toFloat(), v2->toFloat()));
        powExpr->setRightValue(&result);
    } else {
        assert(0);  //type error
    }
}

void ExprProcessor::visit(SubExpr* subExpr) {
    subExpr->getFirstOp()->accept(this);
    subExpr->getSecondOp()->accept(this);
    
    const RightValue* v1 = readRightValue(subExpr->getFirstOp());
    const RightValue* v2 = readRightValue(subExpr->getSecondOp());
    
    FireMLDataType dataType = getAlgoResultType(*v1, *v2);
    if (dataType == Int) {
        IntConst result;
        result.value = v1->toInt() - v2->toInt();
        subExpr->setRightValue(&result);
    } else if (dataType == Float) {
        FloatConst result;
        result.value = v1->toFloat() - v2->toFloat();
        subExpr->setRightValue(&result);
    } else {
        assert(0);  //type error
    }
}

void ExprProcessor::visit(RightValueExpr* rightValueExpr) { }