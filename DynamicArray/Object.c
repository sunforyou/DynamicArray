//
//  Object.c
//  DynamicArray
//
//  Created by 宋旭 on 16/3/15.
//  Copyright © 2016年 sky. All rights reserved.
//

#include "Object.h"//引用自己定义的文件时用引号
#include <stdlib.h>//引用库头文件时用简括号


void ObjectRetain(Object *obj) {
    
    obj->retainCount_++;
    
}

void ObjectRelease(Object *obj) {
    
    obj->retainCount_--;
    
    if (obj->retainCount_ <= 0) {
        free(obj);
        int number;
        printf("The NO.%d Object is released\n",++number);
    }
}

int ObjectRetainCount(Object *obj) {
    return obj->retainCount_;
}