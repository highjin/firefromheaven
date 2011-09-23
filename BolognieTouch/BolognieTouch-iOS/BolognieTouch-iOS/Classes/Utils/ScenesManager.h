//
//  ScenesManager.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-21.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_ScenesManager_h
#define BolognieTouch_iOS_ScenesManager_h

typedef enum {
    kUninitialized = 0,
    kMainMenuScene = 1,
    kGameScene = 2,
} SceneTypes;

class ScenesManager {
private:
    static ScenesManager* instance;
    SceneTypes currentScene;
    
public:
    virtual bool init();
    inline static ScenesManager* sharedScenesManager() { return instance; }
};


#endif
