//
//  GameTouchReceiverLayer.cpp
//  BolognieTouch-iOS
//
//  Created by  on 11-9-21.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#include "GameTouchReceiverLayer.h"
#include "MainMenuScene.h"
#include "GameScene.h"
#include "ScriptHolderManager.h"

#include "RuntimeKernel.h"
using namespace FireMLEngine;
using namespace cocos2d;

GameTouchReceiverLayer::GameTouchReceiverLayer()
: CCLayerColor(), opState(0) {
}

bool GameTouchReceiverLayer::init() {
    if (!CCLayer::init()) {
        return false;
    }
    
    setIsTouchEnabled(true);
    
    CCSize screenSize = CCDirector::sharedDirector()->getWinSize();
    //setPosition(ccp(screenSize.width / 2, screenSize.height / 2));
    setPosition(ccp(0,0));
    changeWidthAndHeight(screenSize.width, screenSize.height);
    setColor(ccc3(255, 0, 0));
    setOpacity(0);
    
    return true;
}

void GameTouchReceiverLayer::ccTouchesEnded(cocos2d::CCSet *touches, cocos2d::CCEvent *event) {
    /*CCTouch* touch = (CCTouch*) (touches->anyObject());
    CCPoint location = touch->locationInView(touch->view());*/
    
    if (ScriptHolderManager::sharedScriptHolderManager()->isScriptHolding()) {
        ScriptHolderManager::sharedScriptHolderManager()->onTouch();
    } else {
        //next();
        RuntimeKernel::sharedRuntimeKernel()->next();
    }
}

void GameTouchReceiverLayer::next() {
    GameScene* gameScene = (GameScene*) getParent();
    
    switch(opState) {
        case 0:
            gameScene->getBackgroundLayer()->show("图书馆大厅.jpg");
            gameScene->getConversationLayer()->show("大家好~");
            //gameScene->getConversationLayer()->show(((DialogStmt*)(RuntimeKernel::sharedRuntimeKernel()->getRoot()->mainPlot.content[0]))->text.c_str());
            break;
            
        case 1:
            gameScene->getCharacterLayer()->show("老师_闭目.png", ccp(250, 0));
            gameScene->getConversationLayer()->show("“我是波洛革涅的第一美男，路德维希·克莱因教授。”", "路德维希");
            //gameScene->getConversationLayer()->show(((DialogStmt*)(RuntimeKernel::sharedRuntimeKernel()->getRoot()->mainPlot.content[1]))->text.c_str());            
            break;
            
        case 2:
            gameScene->getCharacterLayer()->show("老师_微笑.png", ccp(250, 0)); 
            gameScene->getConversationLayer()->show("“这里是图书馆哦~”", "路德维希");
            //gameScene->getConversationLayer()->show(((DialogStmt*)(RuntimeKernel::sharedRuntimeKernel()->getRoot()->mainPlot.content[2]))->text.c_str());            
            break;
            
        case 3:
            gameScene->getConversationLayer()->show("“由于菠萝被水彩化了，我决定出门走走。”", "路德维希");
            //gameScene->getConversationLayer()->show(((DialogStmt*)(RuntimeKernel::sharedRuntimeKernel()->getRoot()->mainPlot.content[3]))->text.c_str());            
            break; 
            
        case 4:
            gameScene->getCharacterLayer()->hide();
            gameScene->getBackgroundLayer()->show("波洛革涅城.jpg");
            gameScene->getConversationLayer()->show("波洛革涅城，是一个古老的大学城。\n");
            break;
            
        case 5:
            gameScene->getConversationLayer()->append("它是围绕着波洛革涅大学建成的。\n");
            break;
            
        case 6:
            gameScene->getConversationLayer()->show("这所大学的历史，可以追溯到14世纪中叶，是神圣罗马帝国所开设的大学。\n");
            break;
            
        case 7:
            gameScene->getConversationLayer()->show("波洛革涅有法学院、神学院、医学院。\n");
            break;
            
        case 8:
            gameScene->getConversationLayer()->append("但最知名的还是它的哲学院。哇咔咔……");
            break;
            
        case 9:
            gameScene->getConversationLayer()->show("“总之呢，先出大门再说。”", "路德维希");
            break;
            
        case 10:
            gameScene->getBackgroundLayer()->show("图书馆门前.jpg");
            gameScene->getConversationLayer()->show("图书馆门前。");
            break;
            
        case 11:
            gameScene->getCharacterLayer()->show("老师_笑.png", ccp(250, 0));
            gameScene->getConversationLayer()->show("“嗯，图书真好呀。”", "路德维希");
            break;
            
        case 12:
            gameScene->getCharacterLayer()->show("小安_普通2.png", ccp(50, 10));
            gameScene->getConversationLayer()->show("“路德维希老师？您要去哪里？”", "安德烈亚斯");
            break;
            
        case 13:
            gameScene->getCharacterLayer()->show("老师_说话.png", ccp(460, 0));
            gameScene->getConversationLayer()->show("“是小安呀~”", "路德维希");
            break;
            
        case 14:
            gameScene->getCharacterLayer()->show("老师_闭目.png", ccp(460, 0));
            gameScene->getConversationLayer()->show("“我去哪里都可以呀。小安想去哪里呢？”", "路德维希");
            break;
            
        case 15:
            gameScene->getCharacterLayer()->show("小安_笑着说.png", ccp(10, 0));
            gameScene->getConversationLayer()->show("“我想去哲学路~”", "安德烈亚斯");
            break;
            
        case 16:
            gameScene->getCharacterLayer()->show("老师_微笑.png", ccp(460, 0));
            gameScene->getConversationLayer()->show("“好呀。”", "路德维希");
            break;
            
        case 17:
            gameScene->getBackgroundLayer()->show("校园小路.jpg");
            gameScene->getCharacterLayer()->hide();
            gameScene->getConversationLayer()->show("这里是哲学路。");
            break;
            
        default:
            opState = -1;   //exit
            break;
    }
    
    opState++;
    
    if (opState == 0) {
        //CCDirector::sharedDirector()->popScene();
        setIsTouchEnabled(false);
        CCTouchDispatcher::sharedDispatcher()->removeDelegate(this);    //seems a bug in cocos2d?
        CCDirector::sharedDirector()->replaceScene(MainMenuScene::node());
    }
}

void GameTouchReceiverLayer::onExit() {
    //do nothing
}