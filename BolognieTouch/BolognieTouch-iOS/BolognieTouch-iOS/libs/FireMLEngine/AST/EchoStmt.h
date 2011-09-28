//
//  EchoStmt.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-27.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_EchoStmt_h
#define BolognieTouch_iOS_EchoStmt_h

namespace FireMLEngine {
    class EchoStmt : public Statement {
    private: 
        Expression* expression;
        
    public:
        EchoStmt() : expression(NULL) { }
        virtual ~EchoStmt() {
            if (expression != NULL) {
                delete expression;
            }
        }
        
        void setExpression(Expression* expression) {
            if (this->expression != NULL) {
                delete this->expression;
            }
            
            this->expression = expression;
        }
        
        inline Expression* getExpression() { return expression; }
        
        AST_ACCEPT_FUNC
    };
}

#endif
