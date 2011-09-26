//
//  Position.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-25.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_Position_h
#define BolognieTouch_iOS_Position_h

namespace FireMLEngine {
    typedef struct PositionData {
    public:
        int x;
        int y;
        PositionData(int x, int y) : x(x), y(y) { }
        PositionData() : x(0), y(0) { }
        PositionData(const PositionData& rhs) : x(rhs.x), y(rhs.y) { }
    } PositionData;
}

#endif
