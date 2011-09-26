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
        
        virtual bool toBoolean() const {
            return value != 0;
        }
        
        virtual bool equals(const RightValue* ref) {
            return (ref->getDataType() == Int) && (((IntConst*)ref)->value == value);
        }
    };
}

#endif
