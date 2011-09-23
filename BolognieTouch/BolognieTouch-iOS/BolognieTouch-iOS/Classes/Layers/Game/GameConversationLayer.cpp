//
//  GameConversationLayer.cpp
//  BolognieTouch-iOS
//
//  Created by  on 11-9-22.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#include "GameConversationLayer.h"
using namespace cocos2d;

GameConversationLayer::GameConversationLayer() {
    name = NULL;
    dialog = NULL;
    isDialogVisible = false;
    isNameVisible = false;
}

GameConversationLayer::~GameConversationLayer() {
    if (name != NULL) {
        delete [] name;
        name = NULL;
    }
    
    if (dialog != NULL) {
        delete [] dialog;
        dialog = NULL;
    }
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
    
    deleteNameAndDialog();
    
    this->dialog = new char[strlen(dialog) + 1];
    strcpy(this->dialog, dialog);
    dialogLabel->setString(this->dialog);
    dialogBackground->setOpacity(255);  //TODO: transition
    
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
    char* tmp = this->dialog;
    this->dialog = new char[strlen(tmp) + strlen(dialog) + 1];
    strcpy(this->dialog, tmp);
    strcat(this->dialog, dialog);
    
    dialogLabel->setString(this->dialog);
}

void GameConversationLayer::hide() {
    deleteNameAndDialog();
    
    dialogLabel->setString("");
    nameLabel->setString("");
    
    dialogBackground->setOpacity(0);
    nameBackground->setOpacity(0);
}

void GameConversationLayer::deleteNameAndDialog() {
    if (this->dialog != NULL) {
        delete [] this->dialog;
        this->dialog = NULL;
    }
    
    if (this->name != NULL) {
        delete [] this->name;
        this->name = NULL;
    }
}
