//
//  RuntimeKernel.cpp
//  BolognieTouch-iOS
//
//  Created by  on 11-9-24.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#include "binary_iarchive.hpp"

#include "RuntimeKernel.h"
using namespace FireMLEngine;

//singleton stuff
static RuntimeKernel runtimeKernelInstance;
static bool runtimeKernelFirstRun = true;

RuntimeKernel::RuntimeKernel() {
    
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


