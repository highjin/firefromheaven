//
//  RuntimeKernel.cpp
//  BolognieTouch-iOS
//
//  Created by  on 11-9-24.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#include "RuntimeKernel.h"

using namespace FireMLEngine;

//singleton stuff
static RuntimeKernel runtimeKernelInstance;
static bool runtimeKernelFirstRun = true;

RuntimeKernel::RuntimeKernel() : visitor(this), funcCaller(NULL) {
    
}

RuntimeKernel::~RuntimeKernel() {
    
}

bool RuntimeKernel::init() {
    return true;
}

RuntimeKernel* RuntimeKernel::sharedRuntimeKernel() {
    if (runtimeKernelFirstRun)
	{
		runtimeKernelInstance.init();
        runtimeKernelFirstRun = false;
	}
    
	return &runtimeKernelInstance;
}

void RuntimeKernel::next() {
    if (runtimeData.getInstructionStack().count() > 0) {
        int id = runtimeData.getInstructionStack().pop();
        if (id == InstructionStack::ROOT_FLAG) {
            root.accept(&visitor);
        } else if (id == InstructionStack::CLOSE_LOCAL_SCOPE_FLAG) {
            runtimeData.getScopeStack().closeScope();
            next();
        } else if (id == InstructionStack::CLOSE_FORMAL_SCOPE_FLAG) {
            runtimeData.getScopeStack().closeScope();
            next();
        } else if (id == InstructionStack::CALL_FLAG) {
            CallStackElement elem = runtimeData.getCallStack().pop();
            next();
        } else {
            root.nodeMap[id]->accept(&visitor);
        }
    } else {
        funcCaller->end();
    }
}

void RuntimeKernel::behave(FuncReturnBehavior behavior) {
    switch (behavior) {
        case GotoNext:
            next();
            break;
            
        case WaitForUser:
            break;
    }
}



