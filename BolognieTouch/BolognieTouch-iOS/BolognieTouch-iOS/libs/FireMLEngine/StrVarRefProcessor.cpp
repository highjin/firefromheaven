//
//  StrVarRefProcessor.cpp
//  BolognieTouch-iOS
//
//  Created by  on 11-9-30.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#include "StrVarRefProcessor.h"
#include "ScopeStack.h"
#include <assert.h>
using namespace FireMLEngine;
using namespace std;

StrVarRefProcessor::StrVarRefProcessor(ScopeStack* scopeStack) : scopeStack(scopeStack) {
}

string StrVarRefProcessor::replaceVarRef(const string& str) const {
    string r = str;
    StrVarRefState state = Normal;
    int leftBracePos;
    
    for (int pos = 0; pos < r.size(); pos++) {
        char c = r[pos];
                
        if (state == Normal) {
            if (c == '{') {
                state = LeftBrace;
                leftBracePos = pos;
            } else {
                continue;
            }
        } else if (state == LeftBrace) {
            if (c == '$') {
                state = VarName;
            } else {
                state = Normal;
            }
        } else if (state == VarName) {
            if (c == '}') {  //bingo!
                
                //do replace
                string varName = r.substr(leftBracePos + 2, pos - leftBracePos - 2);
                assert(scopeStack->isExist(varName));   //does variable exist? 
                string value = scopeStack->getValue(varName)->toString(); 
                r = r.replace(leftBracePos, pos - leftBracePos + 1, value);
                pos = leftBracePos + value.size() - 1;
                
                state = Normal;
            } else if (c == '{' || c == '$') {    //TODO: check variable name accurately. maybe: \w+[\w\d]*
                state = Normal;
            } else {    
                continue;
            }
            
        }
    }
    
    return r;
}