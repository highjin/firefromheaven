//
//  FunctionDef.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-30.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_FunctionDef_h
#define BolognieTouch_iOS_FunctionDef_h

#include <vector>
#include <map>
#include <string>
#include "Definition.h"
#include "ParameterDef.h"

namespace FireMLEngine {
    class FunctionDef : public Definition {
    public:
        std::map<std::string, ParameterDef> paraMap;
        std::vector<Statement*> funcDefContent;
        
        virtual ~FunctionDef() {
            for (int i = 0; i < funcDefContent.size(); i++) {
                if (funcDefContent[i] != NULL) {
                    delete funcDefContent[i];
                }
                funcDefContent.clear();
            }
        }
        
        AST_ACCEPT_FUNC
    };
}

#endif
