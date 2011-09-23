//
//  ScriptHolder.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-23.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_ScriptHolderManager_h
#define BolognieTouch_iOS_ScriptHolderManager_h

#ifndef NULL
#define NULL 0
#endif

typedef enum {
    WaitOnRelease = 0,
    GotoNextOnRelease = 1
} ScriptHolderReleaseBehavior;

typedef void (*ScriptHolderOnTouchHandler)(void* sender);

typedef struct {
    void* holder;
    ScriptHolderReleaseBehavior releaseBehavior;
    ScriptHolderOnTouchHandler onTouchHandler;
} ScriptHolderItem;

/**
 This singleton class is used to manager those actions that requires script to pause, such as waiting for background transition animation, waiting for the user's response in a selection box.
 */
class ScriptHolderManager {
private:
    ScriptHolderItem holderItem;   //TODO: multiple holder
    
public:
    ScriptHolderManager();
    virtual ~ScriptHolderManager();
    virtual bool init();
    
    static ScriptHolderManager* sharedScriptHolderManager();
    
    /**
     @param releaseBehavior Whether to execute the next script command automatically when released. For animation holder and selection box, it should be GotoNextOnRelease. For conversation, it should be WaitOnRelease.
     @param onTouchHandler What to do when the user click on the global touch layer while the script is held by this obj.
     */
    void registerScriptHolder(void* obj, ScriptHolderReleaseBehavior releaseBehavior, ScriptHolderOnTouchHandler onTouchHandler = NULL); //TODO: add params for the handler
    
    void releaseScriptHolder(void* obj);
    
    inline bool isScriptHolding() { return holderItem.holder != NULL; }
    
    /**
     Invoked when the user click on the global touch layer while the script is held. 
     */
    void onTouch();
};


#endif
