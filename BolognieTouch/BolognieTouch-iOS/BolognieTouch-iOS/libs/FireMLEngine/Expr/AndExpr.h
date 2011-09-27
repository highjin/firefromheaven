//
//  AndExpr.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-26.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_AndExpr_h
#define BolognieTouch_iOS_AndExpr_h

#include "BinaryLogicExpr.h"

namespace FireMLEngine {
    class AndExpr : public BinaryLogicExpr {
    public:
        EXPR_ACCEPT_FUNC
    };
}

#endif
