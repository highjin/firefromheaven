//
//  IEngineFunctionCaller.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-25.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_IEngineFunctionCaller_h
#define BolognieTouch_iOS_IEngineFunctionCaller_h

#include <string>
#include "PositionData.h"

namespace  FireMLEngine {
    
    typedef enum  {
        GotoNext = 0,  
        WaitForUser = 1
    } FuncReturnBehavior;
    
    class IEngineFunctionCaller {
    public:
        virtual FuncReturnBehavior dialog(std::string& text, std::string& name) = 0;
        virtual FuncReturnBehavior background(std::string& img) = 0; //TODO: asset
        virtual FuncReturnBehavior actor(std::string& img, std::string& layer, PositionData position) = 0;
        virtual void end() = 0;
    };
}


#endif
