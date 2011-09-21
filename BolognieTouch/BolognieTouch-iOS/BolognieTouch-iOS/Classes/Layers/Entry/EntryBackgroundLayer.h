//
//  EntryBackgroundLayer.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-20.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_EntryBackgroundLayer_h
#define BolognieTouch_iOS_EntryBackgroundLayer_h

#include "cocos2d.h"

class EntryBackgroundLayer : public cocos2d::CCLayer
{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();  
    
	// implement the "static node()" method manually
	LAYER_NODE_FUNC(EntryBackgroundLayer);
};




#endif
