//
//  Statement.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-24.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_Statement_h
#define BolognieTouch_iOS_Statement_h

#include "ASTNode.h"
#include "IASTVisitor.h"

namespace FireMLEngine {
    class Statement : public ASTNode {
    public:
        virtual void accept(IASTVisitor* visitor) = 0;
    };
}


#endif
