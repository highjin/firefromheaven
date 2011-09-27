//
//  BsonReaderMacro.h
//  BolognieTouch-iOS
//
//  Created by  on 11-9-26.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef BolognieTouch_iOS_BsonReaderMacro_h
#define BolognieTouch_iOS_BsonReaderMacro_h

#define MONGO_USE_LONG_LONG_INT //FIXME: where to put this define?
#include "bson.h"

#define BSON_KEY_AND_TYPE(it)   const char* key = bson_iterator_key(it); \
bson_type type = bson_iterator_type(it);
#define STR_EQUALS(str1, str2)  (strcmp((str1), (str2)) == 0)
#define BSON_READ_STR(it)       (type == BSON_NULL ? "" : bson_iterator_string(it))
#define BSON_KEY_IS(str)        (STR_EQUALS(key, str))

#endif
