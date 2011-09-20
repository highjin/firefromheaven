//
//  main.m
//  BsonTest
//
//  Created by  on 11-8-15.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

#include <stdio.h>
#include "bson.h"

int main (int argc, const char * argv[])
{

    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];

    // insert code here...
    NSLog(@"Hello, World!");
    
    FILE* fp = fopen("/Users/Wander/Desktop/result.bin", "rb");
    
    if (fp == NULL)
    {
        NSLog(@"File not found\n");
        return -1;
    }
    
    fseek(fp, 0L, SEEK_END);
    size_t sz = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    
    char* bsonBuffer = malloc(sizeof(char) * sz);
    fread(bsonBuffer, sz, sizeof(char), fp);
    
    fclose(fp);
    
    bson b[1];
    bson_init_data(b, bsonBuffer);
    
    bson_iterator i[1];
    bson_type type;
    const char* key;
    const char* value;
    
    bson_iterator_init(i, b);
    
    type = bson_iterator_next(i);
    key = bson_iterator_key(i);
    value = bson_iterator_string(i);
  
    NSLog(@"Type: %d, Key: %s, Value: %s", type, key, value);

    free(bsonBuffer);  
    
    [pool drain];
    return 0;
}

