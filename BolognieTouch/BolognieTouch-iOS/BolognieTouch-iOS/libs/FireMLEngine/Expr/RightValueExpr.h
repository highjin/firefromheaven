//
//  RightValueExpr.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-25.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_RightValueExpr_h
#define BolognieTouch_iOS_RightValueExpr_h

#include "Expression.h"
#include "RightValue.h"
#include "IntConst.h"
#include "StringConst.h"
#include "FloatConst.h"

namespace FireMLEngine {
    
    /**
     Store a const, or represent other expressions
     */
    class RightValueExpr : public Expression {
    private:
        RightValue* rightValue;
        
    public:
        RightValueExpr() : rightValue(NULL) { }
        virtual ~RightValueExpr() {
            if (rightValue != NULL) {
                delete rightValue;
            }
        }
        
        /*template <class T>
        T* createRightValue() {
            T* newRightValue = new T();
            rightValue = newRightValue;
            return newRightValue;
        }*/
        
        void setRightValue(RightValue* rightValue) {
            if (this->rightValue != NULL) {
                delete this->rightValue;
            }
            
            this->rightValue = rightValue;
        }
        inline RightValue* getRightValue() { return rightValue; }
        
        EXPR_ACCEPT_FUNC
    };
}

#endif
