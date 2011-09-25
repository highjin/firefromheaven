//
//  FireMLRoot.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-24.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_FireMLRoot_h
#define BolognieTouch_iOS_FireMLRoot_h

#include "PlotDef.h"
#include <map>

namespace FireMLEngine {
    class FireMLRoot {
    public:
        PlotDef mainPlot;
        std::map<int, ASTNode*> nodeMap;
        
        void accept(IASTVisitor* visitor) {
            visitor->visit(this);
        }
    };
}

#endif
