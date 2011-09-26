//
//  RuntimeKernel.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-24.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_RuntimeKernel_h
#define BolognieTouch_iOS_RuntimeKernel_h

#include "FireMLRoot.h"
#include "RuntimeData.h"
#include "RuntimeASTVisitor.h"
#include "IEngineFunctionCaller.h"
#include <string>

namespace FireMLEngine {
    class RuntimeKernel {
    private:
        FireMLRoot root;    //it will be filled by bsonReader
        RuntimeData runtimeData;
        RuntimeASTVisitor visitor;
        IEngineFunctionCaller* funcCaller;
        
    public:
        RuntimeKernel();
        virtual ~RuntimeKernel();
        virtual bool init();
        
        static RuntimeKernel* sharedRuntimeKernel();
        
        inline FireMLRoot* getRoot() { return &root; }
        inline RuntimeData* getRuntimeData() { return &runtimeData; }
        inline IEngineFunctionCaller* getFuncCaller() { return funcCaller; }
        
        inline void registerFuncCaller(IEngineFunctionCaller* funcCaller) {
            this->funcCaller = funcCaller;
        }
        
        void next();
        void behave(FuncReturnBehavior behavior);
    };
}

#endif
