//
//  EquExpr.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-26.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_EquExpr_h
#define BolognieTouch_iOS_EquExpr_h

#include "BinaryCmpExpr.h"

namespace FireMLEngine {
    class EquExpr : public BinaryCmpExpr {
    public:
        EXPR_ACCEPT_FUNC
    };
}

#endif
