//
//  PlotDef.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-24.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_PlotDef_h
#define BolognieTouch_iOS_PlotDef_h

#include "Definition.h"
#include "Statement.h"
#include <vector>

namespace FireMLEngine {
    class PlotDef : public Definition {
    public:
        std::vector<Statement*> content;
        
        virtual ~PlotDef() {
            for(int i = 0; i < content.size(); i++) {
                delete content[i];
            }
            content.clear();
        }
        
        /**
         Create a new statement with type of T, and put it into the end of content list. 
         */
        /*template <class T>
        T* createNewStatement() {
            T* newStat = new T();
            content.push_back(newStat);
            return newStat;
        }*/
        
        AST_ACCEPT_FUNC;
    };
}


#endif
