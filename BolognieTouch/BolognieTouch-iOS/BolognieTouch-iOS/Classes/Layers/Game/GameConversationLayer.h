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

typedef enum  {
    HiddenByScript = 0,
    Animating = 1,
    LineBreakWaiting = 2,
    Finished = 3
} GameConversationState;

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
    char* dialogSub;    //used for per-word animation
    
    int dialogCharNum;
    int dialogSubCharNum;   //used for per-word animation, in UTF-8 length!!
    
    void cleanupOldConversation();

    void schedulePerWordAnimation();
    void unschedulePerWordAnimation();
    GameConversationState state;
    
public:
    GameConversationLayer();
    virtual ~GameConversationLayer();
    virtual bool init();
    LAYER_NODE_FUNC(GameConversationLayer); 
    
    void show(const char* dialog, const char* name = NULL);
    //void append(const char* dialog);
    void hide();
    //TODO: hidden by right click
    
    void perWordAnimationScheduler(cocos2d::ccTime delta);
    static void onTouchHandler(void* owner);
};

#endif
