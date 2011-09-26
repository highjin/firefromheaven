//
//  FloatConst.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-25.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_FloatConst_h
#define BolognieTouch_iOS_FloatConst_h

#include "RightValue.h"
#include <sstream>

namespace FireMLEngine {
    class FloatConst : public RightValue {
    public:
        float value;
        
        virtual FireMLDataType getDataType() const {
            return Float;
        }
        
        virtual std::string toString() const {
            std::stringstream ss;
            ss << value;
            return ss.str();
        }
        
        virtual bool toBoolean() const {
            return value != 0;
        }
        
        virtual bool equals(const RightValue* ref) {    //TODO: epsilon? 
            return (ref->getDataType() == Float) && (((FloatConst*)ref)->value == value);
        }
    };
}

#endif
