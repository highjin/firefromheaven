//
//  ScriptHolder.cpp
//  BolognieTouch-iOS
//
//  Created by  on 11-9-23.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#include "ScriptHolderManager.h"
#include <assert.h>

//singleton stuff
static ScriptHolderManager scriptHolderManagerInstance;
static bool scriptHolderManagerFirstRun = true;

ScriptHolderManager::ScriptHolderManager() {
    holderItem.holder = NULL;
}

ScriptHolderManager::~ScriptHolderManager() {
    assert(holderItem.holder == NULL);
}

bool ScriptHolderManager::init() {
    return true;    //do nothing
}

ScriptHolderManager* ScriptHolderManager::sharedScriptHolderManager() {
	if (scriptHolderManagerFirstRun)
	{
		scriptHolderManagerInstance.init();
        scriptHolderManagerFirstRun = false;
	}
    
	return &scriptHolderManagerInstance;
}

void ScriptHolderManager::registerScriptHolder(void* holder, ScriptHolderReleaseBehavior releaseBehavior, ScriptHolderOnTouchHandler onTouchHandler) {
    assert(holderItem.holder == NULL);
    
    holderItem.holder = holder;
    holderItem.releaseBehavior = releaseBehavior;
    holderItem.onTouchHandler = onTouchHandler;
}

void ScriptHolderManager::releaseScriptHolder(void* obj) {
    holderItem.holder = NULL;
    //TODO: GotoNext
}

void ScriptHolderManager::onTouch() {
    if (holderItem.holder != NULL && holderItem.onTouchHandler != NULL) {
        holderItem.onTouchHandler(holderItem.holder);
    }
}