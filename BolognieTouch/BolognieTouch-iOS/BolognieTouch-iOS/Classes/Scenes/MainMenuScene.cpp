#include "MainMenuScene.h"
#include "MainMenuLayer.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

bool MainMenuScene::init()
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
    
    MainMenuLayer* mainMenuLayer = MainMenuLayer::node();
    this->addChild(mainMenuLayer, 1);
    
    return true;
}

void MainMenuScene::loadGuiResources() 
{
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("gui_small_atlas.plist");
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("gui_big_atlas.plist");
}

void MainMenuScene::playBackgroundMusic()
{
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("复调1.mp3");
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("复调1.mp3", true);
}

void MainMenuScene::onExit() {
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();   //TODO: Fade out
}
