//
//  RightValue.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-25.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_RightValue_h
#define BolognieTouch_iOS_RightValue_h

#include <string>
#include "Value.h"
#include "FireMLDataType.h"

namespace FireMLEngine {
    
    class RightValue : public Value {
    public:
        virtual FireMLDataType getDataType() const = 0;
        virtual std::string toString() const = 0;
        virtual bool toBoolean() const = 0;
        virtual bool equals(const RightValue* value) const = 0;
    };
}

#endif
