//
//  GameTouchReceiverLayer.cpp
//  BolognieTouch-iOS
//
//  Created by  on 11-9-21.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#include "GameTouchReceiverLayer.h"
#include "MainMenuScene.h"
#include "GameScene.h"

using namespace cocos2d;

GameTouchReceiverLayer::GameTouchReceiverLayer()
: CCLayerColor(), opState(0) {
}

bool GameTouchReceiverLayer::init() {
    if (!CCLayer::init()) {
        return false;
    }
    
    setIsTouchEnabled(true);
    
    CCSize screenSize = CCDirector::sharedDirector()->getWinSize();
    //setPosition(ccp(screenSize.width / 2, screenSize.height / 2));
    setPosition(ccp(0,0));
    changeWidthAndHeight(screenSize.width, screenSize.height);
    setColor(ccc3(255, 0, 0));
    setOpacity(0);
    
    return true;
}

void GameTouchReceiverLayer::ccTouchesEnded(cocos2d::CCSet *touches, cocos2d::CCEvent *event) {
    /*CCTouch* touch = (CCTouch*) (touches->anyObject());
    CCPoint location = touch->locationInView(touch->view());*/
    
    GameScene* gameScene = (GameScene*) getParent();
    
    switch(opState) {
        case 0:
            gameScene->getBackgroundLayer()->Show("图书馆大厅.jpg");
            break;
            
        case 1:
            gameScene->getBackgroundLayer()->Show("校园小路.jpg");
            break;
            
        default:
            opState = -1;   //exit
            break;
    }
    
    opState++;
    
    if (opState == 0) {
        CCDirector::sharedDirector()->replaceScene(MainMenuScene::node());
    }
}