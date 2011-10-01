//
//  InstructionStack.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-25.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_InstructionStack_h
#define BolognieTouch_iOS_InstructionStack_h

#include <list>
#include <vector>
#include "Statement.h"

namespace FireMLEngine {
    class InstructionStack {
    private:
        std::list<int> instStack;   //stack top = list end
        
    public:
        
        static const int ROOT_FLAG = 0;
        static const int CLOSE_LOCAL_SCOPE_FLAG = -1;
        static const int CLOSE_FORMAL_SCOPE_FLAG = -2;
        static const int CALL_FLAG = -3;
        
        inline std::list<int>& getRawData() { return instStack; }
        
        inline void push(const Statement* statement) {
            instStack.push_back(statement->_id);
        }
        
        inline void push(int _id) {
            instStack.push_back(_id);
        }
        
        void push(const std::vector<Statement*>& statementSequence) {
            for (int i = statementSequence.size() - 1; i >= 0; i--) {
                instStack.push_back(statementSequence[i]->_id);
            }
        }
        
        void push(std::vector<int> idSequence) {
            for (int i = idSequence.size() - 1; i >= 0; i--) {
                instStack.push_back(idSequence[i]);
            }
        }
        
        inline int pop() {
            int r = instStack.back();
            std::list<int>::iterator it = instStack.end();
            --it;
            instStack.erase(it);
            return r;
        }
        
        inline int peek() {
            return instStack.back();
        }
        
        inline int count() {
            return instStack.size();
        }
        
        inline void clear() {
            instStack.clear();
        }
    };
}

#endif
