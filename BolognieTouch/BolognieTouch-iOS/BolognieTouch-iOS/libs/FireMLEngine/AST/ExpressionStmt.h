//
//  ExpressionStmt.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-27.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_ExpressionStmt_h
#define BolognieTouch_iOS_ExpressionStmt_h

#include "Statement.h"
#include "Expression.h"
#include <vector>

namespace FireMLEngine {
    class ExpressionStmt : public Statement {
    public:
        std::vector<Expression*> expressionList;
        
        virtual ~ExpressionStmt() {
            for (int i = 0; i < expressionList.size(); i++) {
                delete expressionList[i];
            }
            expressionList.clear();
        }
        
        AST_ACCEPT_FUNC
    };
}


#endif
