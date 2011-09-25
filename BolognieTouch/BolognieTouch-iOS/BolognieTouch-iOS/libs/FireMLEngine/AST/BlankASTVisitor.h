//
//  BlankASTVisitor.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-24.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_BlankASTVisitor_h
#define BolognieTouch_iOS_BlankASTVisitor_h

#include "IASTVisitor.h"

namespace FireMLEngine {
    class BlankASTVisitor : public IASTVisitor {
        virtual void visit(FireMLRoot* root);
        virtual void visit(ActionLayerDef* actionLayerDef);
        virtual void visit(FunctionDef* functionDef);
        virtual void visit(PlotDef* plotDef);
        virtual void visit(ContinueStmt* continueStmt);
        virtual void visit(FunctionCallStmt* funcCallStmt);
        virtual void visit(MusicStmt* musicStmt);
        virtual void visit(MusicStopStmt* musicStopStmt);
        virtual void visit(MusicVolStmt* musicVolStmt);
        virtual void visit(SwitchStmt* switchStmt);
        virtual void visit(SelectStmt* selectStmt);
        virtual void visit(ActorStmt* actorStmt);
        virtual void visit(DialogStmt* dialogStmt);
        virtual void visit(IfStmt* ifStmt);
        virtual void visit(LoopStmt* loopStmt);
        virtual void visit(BackgroundStmt* backgroundStmt);
        virtual void visit(EchoStmt* echoStmt);
        virtual void visit(IncludeStmt* includeStmt);
        virtual void visit(BreakStmt* breakStmt);
        virtual void visit(ExpressionStmt* expressionStmt);
        virtual void visit(ReturnStmt* returnStmt);
        
        virtual void visit(ParameterDef* parameterDef);
        virtual void visit(SelectOption* selectOption);
        virtual void visit(SwitchCase* switchCase);
        virtual void visit(IfBlock* ifBlock);
        
        virtual void visit(DataStmt* dataStmt);
        virtual void visit(AssetDef* assetDef);
    };
}

#endif
