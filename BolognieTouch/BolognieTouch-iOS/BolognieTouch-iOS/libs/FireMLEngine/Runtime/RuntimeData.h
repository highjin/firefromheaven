//
//  RuntimeData.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-25.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_RuntimeData_h
#define BolognieTouch_iOS_RuntimeData_h

#include "InstructionStack.h"
#include "CallStack.h"
#include "ScopeStack.h"

namespace FireMLEngine {
    class RuntimeData {
    private:
        InstructionStack instructionStack;
        CallStack callStack;
        ScopeStack scopeStack;
        
    public:
        std::string currentActorName;
        std::string currentActorAvatar;
        
        RuntimeData() : currentActorName(""), currentActorAvatar("") {
            
        }
        
        inline InstructionStack& getInstructionStack() { return instructionStack; }
        inline CallStack& getCallStack() { return callStack; }
        inline ScopeStack& getScopeStack() { return scopeStack; }
        
        inline void reset() {
            instructionStack.clear();
            callStack.clear();
            
            instructionStack.push(InstructionStack::ROOT_FLAG);
            
            currentActorName = "";
            currentActorAvatar = "";
        }
    };
}

#endif
