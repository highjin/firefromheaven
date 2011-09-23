//
//  GameBackgroundLayer.cpp
//  BolognieTouch-iOS
//
//  Created by  on 11-9-21.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#include "GameBackgroundLayer.h"
using namespace cocos2d;

GameBackgroundLayer::GameBackgroundLayer() 
    : CCLayer(), imageSprite(NULL) {
}

bool GameBackgroundLayer::init() {
    if (! CCLayer::init()) {
        return false;
    }
    
    setPosition(ccp(0,0));
    
    return true;
}

void GameBackgroundLayer::show(const char* filename) {
    if (imageSprite != NULL) {
        removeChild(imageSprite, true);
    }
    
    CCSize screenSize = CCDirector::sharedDirector()->getWinSize();

    imageSprite = CCSprite::spriteWithFile(filename);
    imageSprite->setPosition(ccp(screenSize.width / 2, screenSize.height / 2));

    //scaling
    CCSize texSize = imageSprite->getTexture()->getContentSize();
    imageSprite->setScaleX(screenSize.width / texSize.width);
    imageSprite->setScaleY(screenSize.height / texSize.height);
    
    addChild(imageSprite);
}


