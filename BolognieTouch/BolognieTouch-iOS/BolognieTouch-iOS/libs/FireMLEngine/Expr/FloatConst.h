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
        
        virtual float toFloat() const {
            return value;
        }
        
        virtual int toInt() const {
            return (int)value;
        }
        
        virtual bool toBoolean() const {
            return value != 0;
        }
        
        
        virtual bool equals(const RightValue* ref) const {    //TODO: epsilon? 
            return (ref->getDataType() == Float) && (((FloatConst*)ref)->value == value);
        }
        
        virtual RightValue* clone() const {
            FloatConst* r = new FloatConst();
            r->value = value;
            return r;
        }
    };
}

#endif
