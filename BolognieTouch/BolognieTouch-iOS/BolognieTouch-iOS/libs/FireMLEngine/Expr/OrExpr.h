//
//  OrExpr.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-26.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_OrExpr_h
#define BolognieTouch_iOS_OrExpr_h

#include "BinaryLogicExpr.h"

namespace FireMLEngine {
    class OrExpr : public BinaryLogicExpr {
    public:
        EXPR_ACCEPT_FUNC
    };
}

#endif
