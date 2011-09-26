//
//  BlankExprVisitor.cpp
//  BolognieTouch-iOS
//
//  Created by  on 11-9-25.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#include "IntConst.h"   //debug
#include "BinaryExpr.h"
#include "MonoExpr.h"

#include "BlankExprVisitor.h"
using namespace FireMLEngine;

void BlankExprVisitor::visit(AddExpr* addExpr) { }
void BlankExprVisitor::visit(AndExpr* andExpr) { }
void BlankExprVisitor::visit(AssignExpr* assignExpr) { }
void BlankExprVisitor::visit(DivExpr* divExpr) { }
void BlankExprVisitor::visit(EquExpr* equExpr) { }
void BlankExprVisitor::visit(GreatEquExpr* greatEquExpr) { }
void BlankExprVisitor::visit(GreatExpr* greatExpr) { }
void BlankExprVisitor::visit(LeftValueExpr* leftValueExpr) { }
void BlankExprVisitor::visit(LessEquExpr* lessEquExpr) { }
void BlankExprVisitor::visit(LessExpr* lessExpr) { }
void BlankExprVisitor::visit(MulExpr* mulExpr) { }
void BlankExprVisitor::visit(NegativeExpr* negativeExpr) { }
void BlankExprVisitor::visit(NeqExpr* neqExpr) { }
void BlankExprVisitor::visit(NotExpr* notExpr) { }
void BlankExprVisitor::visit(OrExpr* orExpr) { }
void BlankExprVisitor::visit(PowExpr* powExpr) { }
void BlankExprVisitor::visit(RightValueExpr* rightValueExpr) { }
void BlankExprVisitor::visit(SubExpr* subExpr) { }
