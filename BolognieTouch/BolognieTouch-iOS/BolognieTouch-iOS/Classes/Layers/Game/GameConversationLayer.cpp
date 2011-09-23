//
//  GameConversationLayer.cpp
//  BolognieTouch-iOS
//
//  Created by  on 11-9-22.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#include "GameConversationLayer.h"
#include "utf8.h"
#include "ScriptHolderManager.h"
using namespace cocos2d;

GameConversationLayer::GameConversationLayer() : name(NULL), dialog(NULL), dialogSub(NULL), isDialogVisible(false), isNameVisible(false), dialogCharNum(0), dialogSubCharNum(0), perWordAnimationScheduled(false) {
}

GameConversationLayer::~GameConversationLayer() {
    cleanupOldConversation();
}

bool GameConversationLayer::init() {
    
    if (!CCLayer::init()) {
        return false;
    }
    
    CCSize screenSize = CCDirector::sharedDirector()->getWinSize();
    
    dialogBackground = CCSprite::spriteWithSpriteFrameName("对话框.png");
    dialogBackground->setPosition(ccp(screenSize.width / 2, screenSize.height / 2));
    dialogBackground->setOpacity(0);
    addChild(dialogBackground, 0);
    
    nameBackground = CCSprite::spriteWithSpriteFrameName("姓名框.png");
    CCSize nameTexSize = nameBackground->getTextureRect().size;
    nameBackground->setPosition(ccp(188 + nameTexSize.width / 2, screenSize.height - 586 - nameTexSize.height / 2));
    nameBackground->setOpacity(0);
    addChild(nameBackground, 0);
    
    CCSize dialogSize = CCSizeMake(605, 107);
    dialogLabel = CCLabelTTF::labelWithString(""/*"这里是图书馆～"*/, dialogSize, CCTextAlignmentLeft, "STHeitiSC-Light", 18);
    dialogLabel->setPosition(ccp(208 + dialogSize.width / 2, screenSize.height - 645 - dialogSize.height / 2));
    dialogLabel->setColor(ccc3(0, 0, 0));
    addChild(dialogLabel, 1);
                             
    CCSize nameSize = CCSizeMake(125, 20);
    nameLabel = CCLabelTTF::labelWithString(""/*"路德维希"*/, nameSize, CCTextAlignmentLeft, "STHeitiSC-Light", 18);
    nameLabel->setPosition(ccp(212 + nameSize.width / 2, screenSize.height - 594 - nameSize.height / 2));
    nameLabel->setColor(ccc3(15, 18, 67));
    addChild(nameLabel, 1);
    
    
    return true;
}


void GameConversationLayer::show(const char* dialog, const char* name) {
    assert(dialog != NULL);
    cleanupOldConversation();
    
    int len = strlen(dialog);
    this->dialog = new char[len + 1];
    this->dialogSub = new char[len + 1];
    
    this->dialogCharNum = utf8_strlen((utf8*)dialog);
    
    strcpy(this->dialog, dialog);
    dialogLabel->setString("");
    dialogBackground->setOpacity(255);  //TODO: transition
    
    //begin per-word animation scheduler
    schedulePerWordAnimation();
    
    if (name != NULL) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        nameLabel->setString(this->name);
        nameBackground->setOpacity(255);
    } else {
        nameLabel->setString("");
        nameBackground->setOpacity(0);
    }
    
}

void GameConversationLayer::append(const char *dialog) {
    dialogSubCharNum = dialogCharNum;
    int newByteLength = strlen(this->dialog) + strlen(dialog) + 1;
    
    delete [] dialogSub;
    dialogSub = new char[newByteLength];
    
    char* tmp = this->dialog;
    this->dialog = new char[newByteLength];
    strcpy(this->dialog, tmp);
    strcat(this->dialog, dialog);
    delete [] tmp;
    
    dialogCharNum = utf8_strlen((utf8*)this->dialog);
    
    if (!perWordAnimationScheduled) {
        schedulePerWordAnimation();
    }
    
    //dialogLabel->setString(this->dialog);
}

void GameConversationLayer::hide() {
    cleanupOldConversation();
    
    dialogLabel->setString("");
    nameLabel->setString("");
    
    dialogBackground->setOpacity(0);
    nameBackground->setOpacity(0);
}

void GameConversationLayer::cleanupOldConversation() {
    
    if (perWordAnimationScheduled) {
        unschedulePerWordAnimation();
    }
    
    dialogSubCharNum = 0;
    dialogCharNum = 0;
    
    if (this->dialog != NULL) {
        delete [] this->dialog;
        this->dialog = NULL;
    }
    
    if (this->name != NULL) {
        delete [] this->name;
        this->name = NULL;
    }
    
    if (this->dialogSub != NULL) {
        delete [] this->dialogSub;
        this->dialogSub = NULL;
    }
}

void GameConversationLayer::perWordAnimationScheduler(ccTime delta) {
    if (dialogCharNum == 0) {
        dialogLabel->setString("");
        unschedulePerWordAnimation();
        assert(dialogSubCharNum = 0);
    } else {
        dialogSubCharNum++; 
        utf8_substr((utf8*)dialog, 0, dialogSubCharNum, (utf8*)dialogSub);
        dialogLabel->setString((char*)dialogSub);
    }
    
    if (dialogSubCharNum >= dialogCharNum) {
        unschedulePerWordAnimation();
    }
}

void GameConversationLayer::schedulePerWordAnimation() {
    schedule(schedule_selector(GameConversationLayer::perWordAnimationScheduler), 0.075f);
    perWordAnimationScheduled = true;
    //TODO: 0.5f -> property
    
    ScriptHolderManager::sharedScriptHolderManager()->registerScriptHolder(this, WaitOnRelease, GameConversationLayer::onTouchHandler);
}

void GameConversationLayer::unschedulePerWordAnimation() {
    unschedule(schedule_selector(GameConversationLayer::perWordAnimationScheduler));
    perWordAnimationScheduled = false;
    
    ScriptHolderManager::sharedScriptHolderManager()->releaseScriptHolder(this);
}

void GameConversationLayer::onTouchHandler(void* sender) {
    GameConversationLayer* layer = (GameConversationLayer*) sender;
    layer->dialogSubCharNum = layer->dialogCharNum;
    layer->unschedulePerWordAnimation();
    
    layer->dialogLabel->setString(layer->dialog);
}

