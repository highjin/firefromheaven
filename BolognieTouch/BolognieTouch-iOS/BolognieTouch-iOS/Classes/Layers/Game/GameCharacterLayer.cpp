//
//  GameCharacterLayer.cpp
//  BolognieTouch-iOS
//
//  Created by  on 11-9-21.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#include "GameCharacterLayer.h"

using namespace cocos2d;

GameCharacterLayer::GameCharacterLayer() 
: CCLayer(), imageSprite(NULL) {
}

bool GameCharacterLayer::init() {
    if (! CCLayer::init()) {
        return false;
    }
    
    return true;
}

//position: (0, 0) for left-upper corner, for compatity with krkr
void GameCharacterLayer::show(const char* filename, CCPoint position) {
    if (imageSprite != NULL) {
        removeChild(imageSprite, true);
    }
    
    CCSize screenSize = CCDirector::sharedDirector()->getWinSize();
    
    imageSprite = CCSprite::spriteWithFile(filename);
    CCSize texSize = imageSprite->getTexture()->getContentSize();
    
    //imageSprite->setAnchorPoint(ccp(0, 0));
    imageSprite->setPosition(ccp(position.x + texSize.width / 2, screenSize.height - position.y - texSize.height / 2));
    
    addChild(imageSprite);
}

void GameCharacterLayer::hide() {
    if (imageSprite != NULL) {
        removeChild(imageSprite, true);
    }
}
