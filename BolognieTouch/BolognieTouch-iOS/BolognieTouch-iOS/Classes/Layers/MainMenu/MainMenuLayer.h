//
//  MainMenuLayer.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-21.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_MainMenuLayer_h
#define BolognieTouch_iOS_MainMenuLayer_h

#include "cocos2d.h"
class MainMenuLayer : public cocos2d::CCLayer {
private:
    cocos2d::CCMenu *mainMenu;
    void displayMenu();
    
public:
    virtual bool init();
    void startButtonCallback(CCObject* pSender);
    void continueButtonCallback(CCObject* pSender);
    void optionButtonCallback(CCObject* pSender);
    void extraButtonCallback(CCObject* pSender);
    void exitButtonCallback(CCObject* pSender);
    LAYER_NODE_FUNC(MainMenuLayer);
};


#endif
