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
        
        template <class T>
        T* createRightValue() {
            T* newRightValue = new T();
            rightValue = newRightValue;
            return newRightValue;
        }
        
        inline RightValue* getRightValue() { return rightValue; }
        
        virtual void accept(IExprVisitor* visitor) = 0;
    };
}

#endif
