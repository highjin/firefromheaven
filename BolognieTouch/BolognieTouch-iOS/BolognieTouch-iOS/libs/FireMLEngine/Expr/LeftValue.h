//
//  LeftValueExpr.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-26.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_LeftValue_h
#define BolognieTouch_iOS_LeftValue_h

#include "Value.h"

namespace FireMLEngine {
    
    typedef enum {
        VarRefType
    } LeftValueType;
    
    class LeftValue : public Value {
    public:
        virtual LeftValueType getLeftValueType() const = 0;
    };
}

#endif
