//
//  RuntimeASTVisitor.cpp
//  BolognieTouch-iOS
//
//  Created by  on 11-9-25.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#include "RuntimeASTVisitor.h"
#include "RuntimeKernel.h"
#include "DialogStmt.h"
#include "BackgroundStmt.h"
#include "ActorStmt.h"
#include "EchoStmt.h"
#include "ExpressionStmt.h"
#include "FunctionCallStmt.h"
#include <map>
using namespace std;
using namespace FireMLEngine;

RuntimeASTVisitor::RuntimeASTVisitor(RuntimeKernel* kernel) : kernel(kernel), exprProcessor(kernel), varRefProcessor(&(kernel->getRuntimeData()->getScopeStack())) {
    
}

void RuntimeASTVisitor::visit(FireMLRoot* root) {
    root->mainPlot.accept(this);
}

void RuntimeASTVisitor::visit(ActionLayerDef* actionLayerDef) { }
void RuntimeASTVisitor::visit(FunctionDef* functionDef) { }

void RuntimeASTVisitor::visit(PlotDef* plotDef) {
    kernel->getRuntimeData()->getScopeStack().openLocalScope();
    kernel->getRuntimeData()->getInstructionStack().push(InstructionStack::CLOSE_LOCAL_SCOPE_FLAG);
    kernel->getRuntimeData()->getInstructionStack().push(plotDef->content);
    kernel->next();
}

void RuntimeASTVisitor::visit(ContinueStmt* continueStmt) { }

void RuntimeASTVisitor::visit(FunctionCallStmt* funcCallStmt) { 
    FormalScope* formalScope = kernel->getRuntimeData()->getScopeStack().openFormalScope();
    for (map<string, Expression*>::iterator it = funcCallStmt->paramMap.begin(); it != funcCallStmt->paramMap.end(); ++it) {
        string name = it->first;
        Expression* expr = it->second;
        const RightValue* rightValue = exprProcessor.eval(expr);
        formalScope->setValue(it->first, *rightValue);
    }
    
    kernel->getRuntimeData()->getScopeStack().openLocalScope();
    
    kernel->getRuntimeData()->getInstructionStack().push(InstructionStack::CALL_FLAG);
    kernel->getRuntimeData()->getInstructionStack().push(InstructionStack::CLOSE_LOCAL_SCOPE_FLAG);
    kernel->getRuntimeData()->getInstructionStack().push(InstructionStack::CLOSE_FORMAL_SCOPE_FLAG);
    
    kernel->getRuntimeData()->getInstructionStack().push(kernel->getRoot()->funcDefMap[funcCallStmt->name].funcDefContent);
    
    CallStackElement elem;
    elem.destination = &(kernel->getRoot()->funcDefMap[funcCallStmt->name]);
    elem.returnValueDest = exprProcessor.getVarName(funcCallStmt->getReturnDest());
    kernel->getRuntimeData()->getCallStack().push(elem);
    
    kernel->next();
}


void RuntimeASTVisitor::visit(MusicStmt* musicStmt) { }
void RuntimeASTVisitor::visit(MusicStopStmt* musicStopStmt) { }
void RuntimeASTVisitor::visit(MusicVolStmt* musicVolStmt) { }
void RuntimeASTVisitor::visit(SwitchStmt* switchStmt) { }
void RuntimeASTVisitor::visit(SelectStmt* selectStmt) { }

void RuntimeASTVisitor::visit(ActorStmt* actorStmt) {
    kernel->getRuntimeData()->currentActorName = varRefProcessor.replaceVarRef(actorStmt->name);
    kernel->getRuntimeData()->currentActorAvatar = varRefProcessor.replaceVarRef(actorStmt->avatar); 
    //TODO: asset, layer
    
    string img = varRefProcessor.replaceVarRef(actorStmt->img);
    kernel->behave(kernel->getFuncCaller()->actor(img, actorStmt->layer, actorStmt->position));
}

void RuntimeASTVisitor::visit(DialogStmt* dialogStmt) {
    string text = varRefProcessor.replaceVarRef(dialogStmt->text);
    kernel->behave(kernel->getFuncCaller()->dialog(text, kernel->getRuntimeData()->currentActorName));
}

void RuntimeASTVisitor::visit(IfStmt* ifStmt) { }
void RuntimeASTVisitor::visit(LoopStmt* loopStmt) { }

void RuntimeASTVisitor::visit(BackgroundStmt* backgroundStmt) { 
    string img = varRefProcessor.replaceVarRef(backgroundStmt->img);
    kernel->behave(kernel->getFuncCaller()->background(img));
    //TODO: asset
}

void RuntimeASTVisitor::visit(EchoStmt* echoStmt) { 
    std::string result = exprProcessor.evalStr(echoStmt->getExpression());
    kernel->behave(kernel->getFuncCaller()->echo(result));
}


void RuntimeASTVisitor::visit(IncludeStmt* includeStmt) { }
void RuntimeASTVisitor::visit(BreakStmt* breakStmt) { }

void RuntimeASTVisitor::visit(ExpressionStmt* expressionStmt) {
    for (int i = 0; i < expressionStmt->expressionList.size(); i++) {
        exprProcessor.eval(expressionStmt->expressionList[i]);
    }
    kernel->next();
}

void RuntimeASTVisitor::visit(ReturnStmt* returnStmt) { }


void RuntimeASTVisitor::visit(ParameterDef* parameterDef) { }
void RuntimeASTVisitor::visit(SelectOption* selectOption) { }
void RuntimeASTVisitor::visit(SwitchCase* switchCase) { }
void RuntimeASTVisitor::visit(IfBlock* ifBlock) { }

void RuntimeASTVisitor::visit(DataStmt* dataStmt) { }
void RuntimeASTVisitor::visit(AssetDef* assetDef) { }
