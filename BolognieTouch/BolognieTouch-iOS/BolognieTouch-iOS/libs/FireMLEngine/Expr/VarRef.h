//
//  VarRef.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-26.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_VarRef_h
#define BolognieTouch_iOS_VarRef_h

#include "LeftValue.h"
#include <string>

namespace FireMLEngine {
    class VarRef : public LeftValue {
    public:
        std::string varName;
    };
}

#endif
