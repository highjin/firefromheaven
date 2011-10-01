//
//  ScopeStack.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-27.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_ScopeStack_h
#define BolognieTouch_iOS_ScopeStack_h

#include "Scope.h"
#include "LocalScope.h"
#include "FormalScope.h"
#include "VarRef.h"
#include <list>

namespace FireMLEngine {
    /**
     Notice:
     1. (Currently) A function can access to its caller's variables.
     2. If the name of a formal variable conflicts with an existing variable, use the formal variable.
     3. if, switch and loop have their own blocks.
     */
    class ScopeStack {
    private:
        std::list<Scope*> scopeStack;   //list end = stack top = current scope
        
        Scope* searchVar(const std::string& varName) const {
            //return searchVar(varName);
            for (std::list<Scope*>::const_reverse_iterator it = scopeStack.rbegin(); it != scopeStack.rend(); ++it) {
                if ((*it)->isExist(varName)) {
                    return *it;
                }
            }
            
            return NULL;
        }
        
    public:
        virtual ~ScopeStack() {
            clear();
        }
        
        void clear() {
            for (std::list<Scope*>::iterator it = scopeStack.begin(); it != scopeStack.end(); ++it) {
                if ((*it) != NULL) {
                    delete (*it);
                }
            }
            
            scopeStack.clear();
        }
        
        LocalScope* openLocalScope() {
            LocalScope* newLocalScope = new LocalScope();
            scopeStack.push_back(newLocalScope);
            return newLocalScope;
        }
        
        FormalScope* openFormalScope() {
            FormalScope* newFormalScope = new FormalScope();
            scopeStack.push_back(newFormalScope);
            return newFormalScope;
        }
        
        void closeScope() {
            std::list<Scope*>::iterator it = scopeStack.end();
            --it;
            scopeStack.erase(it);
        }
        
        const RightValue* getValue(const std::string& varName) const {
            const Scope* scope = searchVar(varName);
            if (scope != NULL) {
                return scope->getValue(varName);
            } else {
                return NULL;
            }
        }
        
        const RightValue* getValue(const VarRef& varRef) const {
            return getValue(varRef.varName);
        }
        
        //search variable from the nearest scope to the farest. If variable does not exist, declare it at the nearest (stack top). value will be deep cloned.
        void setValue(const std::string& varName, const RightValue& value) {
            Scope* scope = searchVar(varName);
            if (scope != NULL) {
                scope->setValue(varName, value);
            } else {
                scope = scopeStack.back();
                scope->setValue(varName, value);
            }
        }
        
        bool isExist(const std::string& varName) const {
            return searchVar(varName) != NULL;
        }
    };
}

#endif
