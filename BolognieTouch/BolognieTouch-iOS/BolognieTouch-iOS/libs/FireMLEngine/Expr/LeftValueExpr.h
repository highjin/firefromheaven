//
//  LeftValueExpr.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-26.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_LeftValueExpr_h
#define BolognieTouch_iOS_LeftValueExpr_h

#include "Expression.h"
#include "LeftValue.h"

namespace FireMLEngine {

    class LeftValueExpr : public Expression {
    private:
        LeftValue* leftValue;
        
    public:
        LeftValueExpr() : leftValue(NULL) { }
        inline ~LeftValueExpr() {
            if (leftValue != NULL) {
                delete leftValue;
            }
        }
        
        /*template <class T>
        T* createLeftValue() {
            if (leftValue != NULL) {
                delete leftValue;
            }
            
            T* newLeftValue = new T();
            leftValue = newLeftValue;
            return newLeftValue;
        }*/
        
        void setLeftValue(LeftValue* value) {
            if (leftValue != NULL) {
                delete leftValue;
            }
            
            this->leftValue = value;
        }
        
        
        inline LeftValue* getLeftValue() { return leftValue; }
        
        EXPR_ACCEPT_FUNC
    };
}

#endif
