//
//  StringValue.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-25.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_StringConst_h
#define BolognieTouch_iOS_StringConst_h

#include "RightValue.h"
#include <string>

namespace FireMLEngine {
    class StringConst : public RightValue {
    public:
        std::string value;
        
        virtual FireMLDataType getDataType() const {
            return String;
        }
        
        virtual std::string toString() const {
            return value;
        }
        
        virtual bool toBoolean() const {
            return value.size() > 0;
        }
        
        virtual bool equals(const RightValue* ref) {
            return (ref->getDataType() == String) && (((StringConst*)ref)->value == value);
        }
    };
}

#endif
