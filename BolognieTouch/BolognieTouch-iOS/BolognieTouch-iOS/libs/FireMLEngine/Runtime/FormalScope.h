//
//  FormalScope.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-27.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_FormalScope_h
#define BolognieTouch_iOS_FormalScope_h

#include "Scope.h"

namespace FireMLEngine {
    class FormalScope : public Scope {
    public:
        virtual ScopeType getScopeType() const { return FormalScopeType; }
    };
}

#endif
