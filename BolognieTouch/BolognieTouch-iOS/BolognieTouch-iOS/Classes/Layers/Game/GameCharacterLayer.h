//
//  GameCharacterLayer.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-21.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_GameCharacterLayer_h
#define BolognieTouch_iOS_GameCharacterLayer_h

#include "cocos2d.h"

class GameCharacterLayer : public cocos2d::CCLayer {
private:
    cocos2d::CCSprite* imageSprite; //TODO: Actor layer, for multiple characters
    
public:
    GameCharacterLayer();
    virtual bool init();
    LAYER_NODE_FUNC(GameCharacterLayer);
    
    void show(const char* filename, cocos2d::CCPoint position);    //TODO: Transition
    void hide();    //TODO: Transition
    //TODO: hidden by right click
};

#endif
