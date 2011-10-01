//
//  ParameterDef.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-30.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_ParameterDef_h
#define BolognieTouch_iOS_ParameterDef_h

#include "Definition.h"
#include "RightValue.h"

namespace FireMLEngine {
    
    typedef enum {
        AutoPara,
        IntPara,
        FloatPara,
        BoolPara, 
        StringPara, 
        ExpressionPara
    } ParameterType;
    
    class ParameterDef : public Definition {
    public:
        ParameterType parameterType;
        
        ParameterDef() : parameterType(AutoPara) { }
        virtual ~ParameterDef() {
        }
        
        AST_ACCEPT_FUNC
    };
}

#endif
