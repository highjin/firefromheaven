//
//  GameBackgroundLayer.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-21.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_GameBackgroundLayer_h
#define BolognieTouch_iOS_GameBackgroundLayer_h

#include "cocos2d.h"

class GameBackgroundLayer : public cocos2d::CCLayer {
private:
    cocos2d::CCSprite* imageSprite;
    
public:
    GameBackgroundLayer();
    virtual bool init();
    LAYER_NODE_FUNC(GameBackgroundLayer);
    
    void show(const char* filename);    //TODO: Transition
};


#endif
