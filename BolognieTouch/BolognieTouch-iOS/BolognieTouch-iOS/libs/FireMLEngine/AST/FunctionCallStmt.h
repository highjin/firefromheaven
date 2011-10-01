//
//  FunctionCallStmt.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-30.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_FunctionCallStmt_h
#define BolognieTouch_iOS_FunctionCallStmt_h

#include "Statement.h"
#include "Expression.h"
#include "LeftValueExpr.h"
#include <string>
#include <map>

namespace FireMLEngine {
    class FunctionCallStmt : public Statement {
    private:
        LeftValueExpr* returnDest; 
        
    public:
        std::string name;
        std::map<std::string, Expression*> paramMap;
        
        FunctionCallStmt() : returnDest(NULL) { }
        virtual ~FunctionCallStmt() {
            for (std::map<std::string, Expression*>::iterator it = paramMap.begin(); it != paramMap.end(); ++it) {
                if (it->second != NULL) {
                    delete it->second;
                }
            }
            paramMap.clear();
            
            if (returnDest != NULL) {
                delete returnDest;
            }
        }
        
        void setReturnDest(LeftValueExpr* returnDest) {
            if (this->returnDest != NULL) {
                delete this->returnDest;
            }
            this->returnDest = returnDest;
        }
        
        inline LeftValueExpr* getReturnDest() { return returnDest; }
        
        AST_ACCEPT_FUNC
    };
}

#endif
