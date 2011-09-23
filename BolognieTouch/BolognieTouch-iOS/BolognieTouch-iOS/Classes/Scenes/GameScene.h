//
//  GameScene.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-21.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_GameScene_h
#define BolognieTouch_iOS_GameScene_h

#include "cocos2d.h"
#include "GameBackgroundLayer.h"
#include "GameTouchReceiverLayer.h"
#include "GameCharacterLayer.h"
#include "GameConversationLayer.h"

class GameScene : public cocos2d::CCScene {
private:
    GameBackgroundLayer* backgroundLayer;
    GameCharacterLayer* characterLayer;
    GameConversationLayer* conversationLayer;
    GameTouchReceiverLayer* touchReceiverLayer;
    
public:
    virtual bool init();
    SCENE_NODE_FUNC(GameScene);
    
    inline GameBackgroundLayer* getBackgroundLayer() { return backgroundLayer; }
    inline GameCharacterLayer* getCharacterLayer() { return characterLayer; }
    inline GameConversationLayer* getConversationLayer() { return conversationLayer; }
    void onExit();
};


#endif
