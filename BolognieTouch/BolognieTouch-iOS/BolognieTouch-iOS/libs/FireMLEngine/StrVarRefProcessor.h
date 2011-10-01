//
//  StrVarRefProcessor.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-30.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_StrVarRefProcessor_h
#define BolognieTouch_iOS_StrVarRefProcessor_h

#include <string>

namespace FireMLEngine {
    class ScopeStack;
    
    typedef enum {
        Normal,
        LeftBrace,
        VarName
    } StrVarRefState;
    
    class StrVarRefProcessor {
    private:
        ScopeStack* scopeStack;
        
    public:
        StrVarRefProcessor(ScopeStack* scopeStack);
        
        /**
         Replace embeded variable to its value
         */
        std::string replaceVarRef(const std::string& str) const; 
    };
}


#endif
