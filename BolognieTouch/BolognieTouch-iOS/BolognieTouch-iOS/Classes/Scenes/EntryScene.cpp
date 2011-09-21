#include "EntryScene.h"
#include "EntryBackgroundLayer.h"
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
    
    CCLayer* layer = EntryBackgroundLayer::node();
    addChild(layer);
    
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
