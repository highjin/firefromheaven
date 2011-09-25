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

namespace FireMLEngine {
    class RuntimeKernel {
    private:
        FireMLRoot root;    //it will be filled by bsonReader
        
    public:
        RuntimeKernel();
        virtual ~RuntimeKernel();
        virtual bool init();
        
        static RuntimeKernel* sharedRuntimeKernel();
        
        inline FireMLRoot* getRoot() { return &root; }
    };
}

#endif
