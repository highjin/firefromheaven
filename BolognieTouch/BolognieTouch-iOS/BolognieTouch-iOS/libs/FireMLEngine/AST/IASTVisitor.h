//
//  IASTVisitor.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-24.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_IASTVisitor_h
#define BolognieTouch_iOS_IASTVisitor_h

#define AST_ACCEPT_FUNC virtual void accept(IASTVisitor* visitor) { \
                            visitor->visit(this); \
                        }

namespace FireMLEngine {
    
    class FireMLRoot;
    class ActionLayerDef;
    class FunctionDef;
    class PlotDef;
    class ContinueStmt;
    class FunctionCallStmt;
    class MusicStmt;
    class MusicStopStmt;
    class MusicVolStmt;
    class SwitchStmt;
    class SelectStmt;
    class ActorStmt;
    class DialogStmt;
    class IfStmt;
    class LoopStmt;
    class BackgroundStmt;
    class EchoStmt;
    class IncludeStmt;
    class BreakStmt;
    class ExpressionStmt;
    class ReturnStmt;
    
    class ParameterDef;
    class SelectOption;
    class SwitchCase;
    class IfBlock;
    
    class DataStmt;
    class AssetDef;
    
    class IASTVisitor {
    public:
        virtual void visit(FireMLRoot* root) = 0;
        virtual void visit(ActionLayerDef* actionLayerDef) = 0;
        virtual void visit(FunctionDef* functionDef) = 0;
        virtual void visit(PlotDef* plotDef) = 0;
        virtual void visit(ContinueStmt* continueStmt) = 0;
        virtual void visit(FunctionCallStmt* funcCallStmt) = 0;
        virtual void visit(MusicStmt* musicStmt) = 0;
        virtual void visit(MusicStopStmt* musicStopStmt) = 0;
        virtual void visit(MusicVolStmt* musicVolStmt) = 0;
        virtual void visit(SwitchStmt* switchStmt) = 0;
        virtual void visit(SelectStmt* selectStmt) = 0;
        virtual void visit(ActorStmt* actorStmt) = 0;
        virtual void visit(DialogStmt* dialogStmt) = 0;
        virtual void visit(IfStmt* ifStmt) = 0;
        virtual void visit(LoopStmt* loopStmt) = 0;
        virtual void visit(BackgroundStmt* backgroundStmt) = 0;
        virtual void visit(EchoStmt* echoStmt) = 0;
        virtual void visit(IncludeStmt* includeStmt) = 0;
        virtual void visit(BreakStmt* breakStmt) = 0;
        virtual void visit(ExpressionStmt* expressionStmt) = 0;
        virtual void visit(ReturnStmt* returnStmt) = 0;
        
        virtual void visit(ParameterDef* parameterDef) = 0;
        virtual void visit(SelectOption* selectOption) = 0;
        virtual void visit(SwitchCase* switchCase) = 0;
        virtual void visit(IfBlock* ifBlock) = 0;
        
        virtual void visit(DataStmt* dataStmt) = 0;
        virtual void visit(AssetDef* assetDef) = 0;
    };
}

#endif
