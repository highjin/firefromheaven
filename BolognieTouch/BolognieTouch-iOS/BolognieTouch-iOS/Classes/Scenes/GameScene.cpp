//
//  GameScene.cpp
//  BolognieTouch-iOS
//
//  Created by  on 11-9-21.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#include "GameScene.h"
#include "SimpleAudioEngine.h"
using namespace cocos2d;
using namespace CocosDenshion;

bool GameScene::init() {
    if (!CCScene::init()) {
        return false;
    }
    
    backgroundLayer = GameBackgroundLayer::node();
    addChild(backgroundLayer, 0);
    
    characterLayer = GameCharacterLayer::node();
    addChild(characterLayer, 1);
    
    conversationLayer = GameConversationLayer::node();
    addChild(conversationLayer, 2);
    
    touchReceiverLayer = GameTouchReceiverLayer::node();
    addChild(touchReceiverLayer, 5);
    
    //for debug
    backgroundLayer->show("波洛革涅城.jpg");
    
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("旋律3.mp3");
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("旋律3.mp3", true);
    
    return true;
}

void GameScene::onExit() {
    //SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
}

