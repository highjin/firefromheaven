//
//  BolognieTouchAppController.h
//  BolognieTouch
//
//  Created by  on 11-9-20.
//  Copyright __MyCompanyName__ 2011年. All rights reserved.
//

@class RootViewController;

@interface AppController : NSObject <UIAccelerometerDelegate, UIAlertViewDelegate, UITextFieldDelegate,UIApplicationDelegate> {
    UIWindow *window;
    RootViewController	*viewController;
}

@end

