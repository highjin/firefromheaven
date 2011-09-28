//
//  Scope.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-27.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_Scope_h
#define BolognieTouch_iOS_Scope_h

#include <map>
#include <string>
#include "RightValue.h"
#include "VarRef.h"

namespace FireMLEngine {
    
    typedef enum {
        LocalScopeType,
        FormalScopeType
    } ScopeType;
    
    class Scope {
    private:
        std::map<std::string, RightValue*> variables;   //store deep-clone of rightvalue in this map
        
    public:
        virtual ~Scope() {
            for (std::map<std::string, RightValue*>::iterator it = variables.begin(); it != variables.end(); ++it) {
                delete it->second;
            }
            variables.clear();
        }
        
        virtual ScopeType getScopeType() const = 0;
        
        const RightValue* getValue(const std::string& varName) const {
            if (variables.find(varName) != variables.end()) {
                std::map<std::string, RightValue*>::const_iterator it = variables.find(varName);
                return it->second;
            } else {
                return NULL;
            }
        }
        
        const RightValue* getValue(const VarRef& varRef) const {
            return getValue(varRef.varName);
        }
        
        void setValue(const std::string& varName, const RightValue& value) {
            if (variables.find(varName) != variables.end() && variables[varName] != NULL) {
                delete variables[varName];
            }
            
            variables[varName] = value.clone();
        }
        
        bool isExist(const std::string& varName) const {
            return variables.find(varName) != variables.end();
        }
    };
}

#endif
