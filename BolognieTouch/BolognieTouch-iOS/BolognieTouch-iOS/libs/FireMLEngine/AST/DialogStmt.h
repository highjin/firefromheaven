//
//  DialogStatement.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-24.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_DialogStatement_h
#define BolognieTouch_iOS_DialogStatement_h

#include "Statement.h"
#include <string>

namespace FireMLEngine {
    class DialogStmt : public Statement {
    public:
        std::string text;
        virtual void accept(IASTVisitor* visitor) {
            visitor->visit(this);
        }
    };
}

#endif
