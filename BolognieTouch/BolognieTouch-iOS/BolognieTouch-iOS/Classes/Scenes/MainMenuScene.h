#ifndef __MAIN_MENU_SCENE_H__
#define __MAIN_MENU_SCENE_H__

#include "cocos2d.h"

class MainMenuScene : public cocos2d::CCScene
{
private:
    void loadGuiResources(); 
    void playBackgroundMusic();
    
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();  
    
    SCENE_NODE_FUNC(MainMenuScene);
};

#endif // __HELLOWORLD_SCENE_H__
