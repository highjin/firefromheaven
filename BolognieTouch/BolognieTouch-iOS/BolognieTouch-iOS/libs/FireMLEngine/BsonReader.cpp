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
#include "FireMLRoot.h"
#include "DialogStmt.h"
using namespace FireMLEngine;

BsonReader::BsonReader() {
    
}

void BsonReader::readTo(const char *bsonFileName, FireMLEngine::FireMLRoot *root) {
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


void BsonReader::visit(FireMLRoot* root) {
    
    bson_iterator* it = bsonItStack.top();
    
    while(bson_iterator_next(it) != BSON_EOO) {
        const char* key = bson_iterator_key(it);
        if (strcmp(key, "MainPlot") == 0) {
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
        const char* key  = bson_iterator_key(it);
        if (strcmp(key, "ID") == 0) {
            plotDef->_id = bson_iterator_int(it);
        } else if (strcmp(key, "Content") == 0) {
            bson_iterator contentIt;
            bson_iterator_subiterator(it, &contentIt);
            while (bson_iterator_next(&contentIt) != BSON_EOO) {
                //read statements
                
                bson_iterator stmtIt;
                bson_iterator_subiterator(&contentIt, &stmtIt);
                
                bson_iterator_next(&stmtIt);    //assuming _t is the first element
                const char* type = bson_iterator_string(&stmtIt);
                bsonItStack.push(&stmtIt);
                
                if (strcmp(type, "DialogStmt") == 0) {
                    plotDef->createNewStatement<DialogStmt>()->accept(this);
                }
                //TODO: other type of statement
                
                
                bsonItStack.pop();
            }
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
void BsonReader::visit(ActorStmt* actorStmt) { }

void BsonReader::visit(DialogStmt* dialogStmt) {
    bson_iterator* it = bsonItStack.top();
    
    while (bson_iterator_next(it) != BSON_EOO) {
        const char* key = bson_iterator_key(it);
        if (strcmp(key, "ID") == 0) {
            dialogStmt->_id = bson_iterator_int(it);
        } else if (strcmp(key, "Text") == 0) {
            dialogStmt->text = bson_iterator_string(it);
        }
    }
}

void BsonReader::visit(IfStmt* ifStmt) { }
void BsonReader::visit(LoopStmt* loopStmt) { }
void BsonReader::visit(BackgroundStmt* backgroundStmt) { }
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

