//
//  LocalScope.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-27.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_LocalScope_h
#define BolognieTouch_iOS_LocalScope_h

#include "Scope.h"

namespace FireMLEngine {
    class LocalScope : public Scope {
    public:
        virtual ScopeType getScopeType() const { return LocalScopeType; }
    };
}

#endif
