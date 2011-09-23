//
//  utf8.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-22.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_utf8_h
#define BolognieTouch_iOS_utf8_h

#include <iostream>
#include <string>
using namespace std;

#define SKIP_MULTI_BYTE_SEQUENCE(input) {              \
    if( (*(input++)) >= 0xc0 ) {                       \
    while( (*input & 0xc0) == 0x80 ){ input++; }       \
    }                                                  \
}                                                      

typedef unsigned char utf8;

void substr(const utf8 *string, 
            int start, 
            int len, 
            utf8 *substring)
{
    int bytes, i;
    const utf8 *str2;
    
    while( *string && start ) {
        SKIP_MULTI_BYTE_SEQUENCE(string);
        --start;
    }
    
    for(str2 = string; *str2 && len; len--) {
        SKIP_MULTI_BYTE_SEQUENCE(str2);
    }
    
    bytes = (int) (str2 - string);
    for(i = 0; i < bytes; i++) {
        substring[i] = string[i];
    }
    substring[bytes] = '\0';
}

int length(const utf8 *string)
{
    int len;
    len = 0;
    while( *string ) {
        ++len;
        SKIP_MULTI_BYTE_SEQUENCE(string);
    }
    return len;
}

#endif
