//
//  EntryBackgroundLayer.cpp
//  BolognieTouch-iOS
//
//  Created by  on 11-9-20.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#include "EntryBackgroundLayer.h"
using namespace cocos2d;

// on "init" you need to initialize your instance
bool EntryBackgroundLayer::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !CCLayer::init() )
	{
		return false;
	}
    
	// ask director the window size
	CCSize size = CCDirector::sharedDirector()->getWinSize();
    
	// add "HelloWorld" splash screen"
	CCSprite* pSprite = CCSprite::spriteWithFile("opbg.png");
    
	// position the sprite on the center of the screen
	pSprite->setPosition( ccp(size.width/2, size.height/2) );
    
	// add the sprite as a child to this layer
	this->addChild(pSprite, 0);
	
	return true;
}