#include "EntryScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

bool EntryScene::init()
{
    if ( !CCScene::init() )
	{
		return false;
	}
    
    loadGuiResources();
    playBackgroundMusic();
    
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

void EntryScene::loadGuiResources() 
{
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("guiatlas.plist");
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("frameatlas1.plist");
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("frameatlas2.plist");
}

void EntryScene::playBackgroundMusic()
{
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("复调1.mp3");
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("复调1.mp3");
}
