//
//  CallStack.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-25.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_CallStack_h
#define BolognieTouch_iOS_CallStack_h

#include <list>
#include <string>
#include "Definition.h"

namespace FireMLEngine {
    
    typedef struct {
        Definition* destination;
        std::string returnValueDest;
    } CallStackElement;
    
    class CallStack {
    private:
        std::list<CallStackElement> callStack;  //list end = stack top
        
    public:
        inline std::list<CallStackElement>& getRawData() { return callStack; }
        inline void push(const CallStackElement& element) {
            callStack.push_back(element);
        }
        
        CallStackElement pop() {
            
            CallStackElement r = callStack.back();
            std::list<CallStackElement>::iterator it = callStack.end();
            --it;
            callStack.erase(it);
            return r;
        }
        
        inline CallStackElement peek() {
            return callStack.back();
        }
        
        inline int count() {
            return callStack.size();
        }
        
        inline void clear() {
            callStack.clear();
        }
    };
}

#endif
