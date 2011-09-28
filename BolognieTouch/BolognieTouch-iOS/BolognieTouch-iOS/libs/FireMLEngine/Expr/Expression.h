//
//  Expression.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-25.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_Expression_h
#define BolognieTouch_iOS_Expression_h

#include "IExprVisitor.h"
#include "FireMLDataType.h"

namespace FireMLEngine {
    
    typedef enum {
        LeftValueExprType,
        RightValueExprType
    } ExpressionType;
    
    class Expression {
    public:
        FireMLDataType dataType;
        
        virtual ExpressionType getExpressionType() const = 0;
        virtual void accept(IExprVisitor* visitor) = 0;
    };
}

#endif
