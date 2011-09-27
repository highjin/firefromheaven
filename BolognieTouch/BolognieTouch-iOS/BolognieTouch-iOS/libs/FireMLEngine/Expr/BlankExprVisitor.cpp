//
//  BlankExprVisitor.cpp
//  BolognieTouch-iOS
//
//  Created by  on 11-9-25.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#include "BlankExprVisitor.h"
using namespace FireMLEngine;

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
void BlankExprVisitor::visit(SubExpr* subExpr) { }
void BlankExprVisitor::visit(RightValueExpr* rightValueExpr) { }
