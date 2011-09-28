//
//  AssignExpr.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-26.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_AssignExpr_h
#define BolognieTouch_iOS_AssignExpr_h

#include "RightValueExpr.h"
#include "LeftValueExpr.h"

namespace FireMLEngine {
    class AssignExpr : public RightValueExpr {
    private:
        LeftValueExpr* leftExpr;
        Expression* rightExpr;
    
    public:
        AssignExpr() : leftExpr(NULL), rightExpr(NULL) { }
        virtual ~AssignExpr() {
            if (leftExpr != NULL) {
                delete leftExpr;
            }
            
            if (rightExpr != NULL) {
                delete rightExpr;
            }
        }
        
        void setLeftExpr(LeftValueExpr* leftExpr) {
            if (this->leftExpr != NULL) {
                delete this->leftExpr;
            }
            
            this->leftExpr = leftExpr;
        }
        
        void setRightExpr(Expression* rightExpr) {
            if (this->rightExpr != NULL) {
                delete this->rightExpr;
            }
            
            this->rightExpr = rightExpr;
        }
        
        inline LeftValueExpr* getLeftExpr() { return leftExpr; }
        inline Expression* getRightExpr() { return rightExpr; }
        
        EXPR_ACCEPT_FUNC
    };
}

#endif
