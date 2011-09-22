//
//  GameScene.cpp
//  BolognieTouch-iOS
//
//  Created by  on 11-9-21.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#include "GameScene.h"
using namespace cocos2d;

bool GameScene::init() {
    if (!CCScene::init()) {
        return false;
    }
    
    backgroundLayer = GameBackgroundLayer::node();
    addChild(backgroundLayer, 0);
    
    touchReceiverLayer = GameTouchReceiverLayer::node();
    addChild(touchReceiverLayer, 1);
    
    backgroundLayer->Show("波洛革涅城.jpg");
    
    return true;
}
