//
//  BinaryAlgoExpr.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-25.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_BinaryAlgoExpr_h
#define BolognieTouch_iOS_BinaryAlgoExpr_h

#include "BinaryExpr.h"

namespace FireMLEngine {
    class BinaryAlgoExpr : public BinaryExpr {
    public:
        virtual void accept(IExprVisitor* visitor) = 0;
    };
}

#endif
