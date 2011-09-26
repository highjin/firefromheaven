//
//  BinaryExpr.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-25.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_BinaryExpr_h
#define BolognieTouch_iOS_BinaryExpr_h

#include "RightValueExpr.h"
namespace FireMLEngine {
    class BinaryExpr : public RightValueExpr {
    private:
        Expression* firstOp;
        Expression* secondOp;
        
    public:
        BinaryExpr() : firstOp(NULL), secondOp(NULL) { }
        virtual ~BinaryExpr() {
            if (firstOp != NULL) {
                delete firstOp;
            }
            
            if (secondOp != NULL) {
                delete secondOp;
            }
        }
        
        template <class T>
        T* createFirstOp() {
            T* newFirstOp = new T();
            firstOp = newFirstOp;
            return newFirstOp;
        }
        
        template <class T>
        T* createSecondOp() {
            T* newSecondOp = new T();
            secondOp = newSecondOp;
            return newSecondOp;
        }
        
        inline Expression* getFirstOp() { return firstOp; }
        inline Expression* getSecondOp() { return secondOp; }
        
        virtual void accept(IExprVisitor* visitor) = 0;
    };
}

#endif
