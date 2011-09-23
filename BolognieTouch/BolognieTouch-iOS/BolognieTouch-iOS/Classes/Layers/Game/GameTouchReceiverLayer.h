//
//  GameTouchReceiverLayer.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-21.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_GameTouchReceiverLayer_h
#define BolognieTouch_iOS_GameTouchReceiverLayer_h

#include "cocos2d.h"

class GameTouchReceiverLayer : public cocos2d::CCLayerColor {
private:
    int opState;    //for debug
    void next();    //for debug
    
public:
    GameTouchReceiverLayer();
    virtual bool init();
    LAYER_NODE_FUNC(GameTouchReceiverLayer);
    
    void ccTouchesEnded(cocos2d::CCSet *touches, cocos2d::CCEvent *event);
    void onExit();
};

#endif
