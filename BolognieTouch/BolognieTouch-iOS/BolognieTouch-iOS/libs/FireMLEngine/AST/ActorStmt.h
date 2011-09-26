//
//  ActorStmt.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-25.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_ActorStmt_h
#define BolognieTouch_iOS_ActorStmt_h

#include "Statement.h"
#include "PositionData.h"
#include <string>
namespace FireMLEngine {
    class ActorStmt : public Statement {
    public:
        std::string name;
        std::string img;
        std::string asset;
        std::string avatar;
        std::string avaAsset;
        std::string layer;
        PositionData position;
        
        AST_ACCEPT_FUNC;
    };
}

#endif
