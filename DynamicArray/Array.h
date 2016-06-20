//
//  Array.h
//  DynamicArray
//
//  Created by 宋旭 on 16/3/15.
//  Copyright © 2016年 sky. All rights reserved.
//

#ifndef Array_h
#define Array_h

#include <stdio.h>
#include "Object.h"

typedef Object* AnyPointer;

typedef struct Array_ {
    int length_;
    int capacity_;
    AnyPointer *values_;
    
} Array;

///创建动态数组
Array * ArrayCreate();

///获取数组长度
int ArrayGetLength(Array *arr);

///添加元素
void ArrayAdd(Array *arr, AnyPointer value);

///插入元素
void ArrayInsert(Array *arr, int index, AnyPointer newValue);

///移除元素
void ArrayRemoveAt(Array *arr, int index);

///查询元素
AnyPointer ArrayGet(Array *arr, int index);

///销毁数组
void ArrayDestory(Array *arr);

#endif /* Array_h */
