//
//  GameScene.cpp
//  BolognieTouch-iOS
//
//  Created by  on 11-9-21.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "MainMenuScene.h"
#include "RuntimeKernel.h"

using namespace cocos2d;
using namespace CocosDenshion;
using namespace FireMLEngine;

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
    
    RuntimeKernel* kernel = RuntimeKernel::sharedRuntimeKernel();
    kernel->getRuntimeData()->reset();    //TODO: load
    kernel->registerFuncCaller(this);
    
    //for debug
    backgroundLayer->show("波洛革涅城.jpg");
    
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("旋律3.mp3");
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("旋律3.mp3", true);
    
    return true;
}

void GameScene::onExit() {
    //SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
}

FuncReturnBehavior GameScene::dialog(std::string& text, std::string& name) {
    conversationLayer->show(text.c_str(), name.c_str());
    return WaitForUser;
}

FuncReturnBehavior GameScene::background(std::string &img) {
    backgroundLayer->show(img.c_str());
    return GotoNext;    //TODO: Transition and wait
}

FuncReturnBehavior GameScene::actor(std::string& img, std::string& layer, PositionData position) {
    if (img.size() > 0) {
        characterLayer->show(img.c_str(), ccp(position.x, position.y));
    } else {
        characterLayer->hide();
    }
    return GotoNext;
}

void GameScene::end() {
    touchReceiverLayer->setIsTouchEnabled(false);
    CCTouchDispatcher::sharedDispatcher()->removeDelegate(touchReceiverLayer);    //seems a bug in cocos2d?
    CCDirector::sharedDirector()->replaceScene(MainMenuScene::node());
}

