//
//  NotExpr.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-26.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_NotExpr_h
#define BolognieTouch_iOS_NotExpr_h

#include "MonoExpr.h"

namespace FireMLEngine {
    class NotExpr : public MonoExpr {
    public:
        EXPR_ACCEPT_FUNC
    };
}

#endif
