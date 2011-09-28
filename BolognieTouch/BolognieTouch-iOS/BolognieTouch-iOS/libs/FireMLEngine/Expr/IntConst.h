//
//  IntConst.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-25.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_IntConst_h
#define BolognieTouch_iOS_IntConst_h

#include "RightValue.h"
#include <sstream>

namespace FireMLEngine {
    class IntConst : public RightValue {
    public:
        int value;
        
        virtual FireMLDataType getDataType() const {
            return Int;
        }
        
        virtual std::string toString() const {
            std::stringstream ss;
            ss << value;
            return ss.str();
        }
        
        virtual float toFloat() const {
            return (float)value;
        }
        
        virtual int toInt() const {
            return value;
        }
        
        virtual bool toBoolean() const {
            return value != 0;
        }
        
        virtual bool equals(const RightValue* ref) const {
            return (ref->getDataType() == Int) && (((IntConst*)ref)->value == value);
        }
        
        virtual RightValue* clone() const {
            IntConst* r = new IntConst();
            r->value = value;
            return r;
        }
    };
}

#endif
