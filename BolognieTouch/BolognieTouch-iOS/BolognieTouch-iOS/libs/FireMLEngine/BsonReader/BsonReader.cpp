//
//  BsonReader.cpp
//  BolognieTouch-iOS
//
//  Created by  on 11-9-24.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#include "BsonReader.h"
#include "bson.h"
#include "stdio.h"
#include "DialogStmt.h"
#include "BackgroundStmt.h"
#include "ActorStmt.h"
#include <assert.h>
#include <string.h>
using namespace FireMLEngine;



BsonReader::BsonReader() {
    
}

void BsonReader::readTo(const char *bsonFileName, FireMLEngine::FireMLRoot *root) {
    this->root = root;
    
    FILE* fp = fopen(bsonFileName, "rb");
    
    //get file size
    fseek(fp, 0L, SEEK_END);
    int bsonSize = (int)ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    
    //init bson
    bson bsonObj;
    bson_init_size(&bsonObj, bsonSize);
    fread(bsonObj.data, bsonSize, 1, fp);
    fclose(fp);
    
    bson_iterator bsonIt;
    bson_iterator_init(&bsonIt, &bsonObj);
    
    bsonItStack.push(&bsonIt);  //data of root will be in the top of the stack
    root->accept(this);
    bsonItStack.pop();
}

void BsonReader::addId(bson_iterator *it, FireMLEngine::ASTNode *node) {
    node->_id = bson_iterator_int(it);
    root->nodeMap[node->_id] = node;
}

void BsonReader::readPosition(bson_iterator *it, PositionData* position) {
    
    if (bson_iterator_type(it) == BSON_NULL) {
        position->x = 0;
        position->y = 0;
        return;
    }
    
    bson_iterator subIt;
    bson_iterator_subiterator(it, &subIt);
    
    int x, y;
    
    while (bson_iterator_next(&subIt) != BSON_EOO) {
        BSON_KEY_AND_TYPE(&subIt);
        if (STR_EQUALS(key, "X")) {
            x = bson_iterator_int(&subIt);
        } else if (BSON_KEY_IS("Y")) {
            y = bson_iterator_int(&subIt);
        }
    }
    
    position->x = x;
    position->y = y;
}

void BsonReader::visitMainContent(std::vector<Statement*>& target) {
    bson_iterator* it = bsonItStack.top();
    while (bson_iterator_next(it) != BSON_EOO) {
        //read statements
        
        bson_iterator stmtIt;
        bson_iterator_subiterator(it, &stmtIt);
        
        bson_iterator_next(&stmtIt);    //assuming _t is the first element
        const char* _t = bson_iterator_string(&stmtIt);
        
        Statement* statement;
        
        if (STR_EQUALS(_t, "DialogStmt")) {
            statement = new DialogStmt();
        } else if (STR_EQUALS(_t, "BackgroundStmt")) {
            statement = new BackgroundStmt();
        } else if (STR_EQUALS(_t, "ActorStmt")) {
            statement = new ActorStmt();
        } else {
            continue;   //for debug, ignoring unimplemented type
        }
        //TODO: other type of statement
        
        bsonItStack.push(&stmtIt);
        statement->accept(this);
        bsonItStack.pop();
        
        target.push_back(statement);
        //the owner of target will in charge of deleting this statement
    }
}

void BsonReader::visit(FireMLRoot* root) {
    bson_iterator* it = bsonItStack.top();
    
    while(bson_iterator_next(it) != BSON_EOO) {
        BSON_KEY_AND_TYPE(it);
        
        if (BSON_KEY_IS("MainPlot")) {
            bson_iterator mainPlotIt;
            bson_iterator_subiterator(it, &mainPlotIt);
            
            bsonItStack.push(&mainPlotIt);
            root->mainPlot.accept(this);
            bsonItStack.pop();
        }
        //TODO others
    }
}


void BsonReader::visit(ActionLayerDef* actionLayerDef) { }
void BsonReader::visit(FunctionDef* functionDef) { }

void BsonReader::visit(PlotDef* plotDef) {
    bson_iterator* it = bsonItStack.top();
    
    while(bson_iterator_next(it) != BSON_EOO) {
        BSON_KEY_AND_TYPE(it);
        
        if (BSON_KEY_IS("ID")) {
            addId(it, plotDef);
        } else if (BSON_KEY_IS("Content")) {
            bson_iterator contentIt;
            bson_iterator_subiterator(it, &contentIt);
            bsonItStack.push(&contentIt);
            visitMainContent(plotDef->content);
            bsonItStack.pop();
        }
    }
}

void BsonReader::visit(ContinueStmt* continueStmt) { }
void BsonReader::visit(FunctionCallStmt* funcCallStmt) { }
void BsonReader::visit(MusicStmt* musicStmt) { }
void BsonReader::visit(MusicStopStmt* musicStopStmt) { }
void BsonReader::visit(MusicVolStmt* musicVolStmt) { }
void BsonReader::visit(SwitchStmt* switchStmt) { }
void BsonReader::visit(SelectStmt* selectStmt) { }

void BsonReader::visit(ActorStmt* actorStmt) {
    bson_iterator* it = bsonItStack.top();
    
    while (bson_iterator_next(it) != BSON_EOO) {
        BSON_KEY_AND_TYPE(it);
        
        if (BSON_KEY_IS("ID")) {
            addId(it, actorStmt);
        } else if (BSON_KEY_IS("Name")) {
            actorStmt->name = BSON_READ_STR(it);
        } else if (BSON_KEY_IS("Img")) {
            actorStmt->img = BSON_READ_STR(it);
        } else if (BSON_KEY_IS("Asset")) {
            actorStmt->asset = BSON_READ_STR(it);
        } else if (BSON_KEY_IS("Avatar")) {
            actorStmt->avatar = BSON_READ_STR(it);
        } else if (BSON_KEY_IS("Layer")) {
            actorStmt->layer = BSON_READ_STR(it);
        } else if (BSON_KEY_IS("Position")) {
            readPosition(it, &(actorStmt->position));
        }
    }
}

void BsonReader::visit(DialogStmt* dialogStmt) {
    bson_iterator* it = bsonItStack.top();
    
    while (bson_iterator_next(it) != BSON_EOO) {
        const char* key = bson_iterator_key(it);
        if (BSON_KEY_IS("ID")) {
            addId(it, dialogStmt);
        } else if (BSON_KEY_IS("Text")) {
            assert(bson_iterator_type(it) == BSON_STRING);
            dialogStmt->text = bson_iterator_string(it);
        }
    }
}

void BsonReader::visit(IfStmt* ifStmt) { }
void BsonReader::visit(LoopStmt* loopStmt) { }
                           
void BsonReader::visit(BackgroundStmt* backgroundStmt) {
    bson_iterator* it = bsonItStack.top();
    while (bson_iterator_next(it) != BSON_EOO) {
        const char* key = bson_iterator_key(it);
        bson_type type = bson_iterator_type(it);
        if (BSON_KEY_IS("ID")) {
            addId(it, backgroundStmt);
        } else if (BSON_KEY_IS("Img")) {
            backgroundStmt->img = BSON_READ_STR(it);
        } else if (BSON_KEY_IS("Asset")) {
            backgroundStmt->asset = BSON_READ_STR(it);
        }
    }
}
                           
void BsonReader::visit(EchoStmt* echoStmt) { }
void BsonReader::visit(IncludeStmt* includeStmt) { }
void BsonReader::visit(BreakStmt* breakStmt) { }
void BsonReader::visit(ExpressionStmt* expressionStmt) { }
void BsonReader::visit(ReturnStmt* returnStmt) { }

void BsonReader::visit(ParameterDef* parameterDef) { }
void BsonReader::visit(SelectOption* selectOption) { }
void BsonReader::visit(SwitchCase* switchCase) { }
void BsonReader::visit(IfBlock* ifBlock) { }

void BsonReader::visit(DataStmt* dataStmt) { }
void BsonReader::visit(AssetDef* assetDef) { }

