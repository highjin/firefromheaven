//
//  ASTNode.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-24.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_ASTNode_h
#define BolognieTouch_iOS_ASTNode_h

#include "IASTVisitor.h"

namespace FireMLEngine {
    class ASTNode {      
    public:
        ASTNode* parent;
        int _id;
        
        virtual void accept(IASTVisitor* visitor) = 0;
    };
}


#endif
