//
//  Definition.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-24.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_Definition_h
#define BolognieTouch_iOS_Definition_h

#include "ASTNode.h"
#include "IASTVisitor.h"
#include <string>

namespace FireMLEngine {
    class Definition : public ASTNode {
    public:
        std::string name;
        
        virtual void accept(IASTVisitor* visitor) = 0;
    };
}

#endif
