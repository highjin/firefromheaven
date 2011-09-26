//
//  BackgroundStmt.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-25.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_BackgroundStmt_h
#define BolognieTouch_iOS_BackgroundStmt_h

#include "Statement.h"
#include <string>

namespace FireMLEngine {
    class BackgroundStmt : public Statement {
    public:
        std::string img;
        std::string asset;
        
        AST_ACCEPT_FUNC;
    };
}

#endif
