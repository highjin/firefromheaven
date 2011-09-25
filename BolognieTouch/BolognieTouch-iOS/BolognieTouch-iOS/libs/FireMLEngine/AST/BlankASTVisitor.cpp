//
//  BlankASTVisitor.cpp
//  BolognieTouch-iOS
//
//  Created by  on 11-9-24.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#include "BlankASTVisitor.h"
using namespace FireMLEngine;

void BlankASTVisitor::visit(FireMLRoot* root) { }
void BlankASTVisitor::visit(ActionLayerDef* actionLayerDef) { }
void BlankASTVisitor::visit(FunctionDef* functionDef) { }
void BlankASTVisitor::visit(PlotDef* plotDef) { }
void BlankASTVisitor::visit(ContinueStmt* continueStmt) { }
void BlankASTVisitor::visit(FunctionCallStmt* funcCallStmt) { }
void BlankASTVisitor::visit(MusicStmt* musicStmt) { }
void BlankASTVisitor::visit(MusicStopStmt* musicStopStmt) { }
void BlankASTVisitor::visit(MusicVolStmt* musicVolStmt) { }
void BlankASTVisitor::visit(SwitchStmt* switchStmt) { }
void BlankASTVisitor::visit(SelectStmt* selectStmt) { }
void BlankASTVisitor::visit(ActorStmt* actorStmt) { }
void BlankASTVisitor::visit(DialogStmt* dialogStmt) { }
void BlankASTVisitor::visit(IfStmt* ifStmt) { }
void BlankASTVisitor::visit(LoopStmt* loopStmt) { }
void BlankASTVisitor::visit(BackgroundStmt* backgroundStmt) { }
void BlankASTVisitor::visit(EchoStmt* echoStmt) { }
void BlankASTVisitor::visit(IncludeStmt* includeStmt) { }
void BlankASTVisitor::visit(BreakStmt* breakStmt) { }
void BlankASTVisitor::visit(ExpressionStmt* expressionStmt) { }
void BlankASTVisitor::visit(ReturnStmt* returnStmt) { }

void BlankASTVisitor::visit(ParameterDef* parameterDef) { }
void BlankASTVisitor::visit(SelectOption* selectOption) { }
void BlankASTVisitor::visit(SwitchCase* switchCase) { }
void BlankASTVisitor::visit(IfBlock* ifBlock) { }

void BlankASTVisitor::visit(DataStmt* dataStmt) { }
void BlankASTVisitor::visit(AssetDef* assetDef) { }
