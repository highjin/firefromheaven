//
//  GameScene.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-21.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_GameScene_h
#define BolognieTouch_iOS_GameScene_h

#include "cocos2d.h"
#include "GameBackgroundLayer.h"

class GameScene : public cocos2d::CCScene {
private:
    GameBackgroundLayer* backgroundLayer;
    
public:
    virtual bool init();
    SCENE_NODE_FUNC(GameScene);
};


#endif
