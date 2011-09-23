//
//  GameConversationLayer.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-22.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_GameConversationLayer_h
#define BolognieTouch_iOS_GameConversationLayer_h

#include "cocos2d.h"

class GameConversationLayer : public cocos2d::CCLayer {
private:
    cocos2d::CCSprite* dialogBackground;
    cocos2d::CCSprite* nameBackground;
    cocos2d::CCLabelTTF* dialogLabel;
    cocos2d::CCLabelTTF* nameLabel;
    bool isDialogVisible;
    bool isNameVisible;
    
    char* name;
    char* dialog;
    
    void deleteNameAndDialog();
    
public:
    GameConversationLayer();
    virtual ~GameConversationLayer();
    virtual bool init();
    LAYER_NODE_FUNC(GameConversationLayer); 
    
    void show(const char* dialog, const char* name = NULL);
    void append(const char* dialog);
    void hide();
    //TODO: hidden by right click
};

#endif
