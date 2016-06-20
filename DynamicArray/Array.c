//
//  Array.c
//  DynamicArray
//
//  Created by 宋旭 on 16/3/15.
//  Copyright © 2016年 sky. All rights reserved.
//

#include "Array.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

static AnyPointer * allocMemoryByCapacity(Array *arr) {
    return malloc(sizeof(AnyPointer) * arr->capacity_);
}

Array * ArrayCreate() {
    Array * arr = malloc(sizeof(Array));
    arr->length_ = 0;
    arr->capacity_ = 32;
    arr->values_ = allocMemoryByCapacity(arr);
    return arr;
}

int ArrayGetLength(Array *arr) {
    return arr->length_;
}

void ArrayAdd(Array *arr, AnyPointer value){
    if (arr->length_ >= arr->capacity_) {
        arr->capacity_ *= 2;
        AnyPointer *oldValues = arr->values_;
        arr->values_ = allocMemoryByCapacity(arr);
        memcpy(arr->values_, oldValues, arr->length_ * sizeof(AnyPointer));
        free(oldValues);
    }
    
    arr->values_[arr->length_] = value;
    arr->length_++;
    OBJECT_RETAIN(value);
}

void ArrayInsert(Array *arr, int index, AnyPointer newValue) {
    assert(index>=0 && index<arr->length_);
    
    arr->length_++;
    for (int i = arr->length_-2; i>=index; i--) {
        arr->values_[i+1] = arr->values_[i];
    }
    arr->values_[index] = newValue;
    OBJECT_RETAIN(arr->values_[index]);
}

AnyPointer ArrayGet(Array *arr, int index) {
    assert(index>=0 && index<arr->length_);
    return arr->values_[index];
}

void ArrayRemoveAt(Array *arr,int index) {
    assert(index>=0 && index<arr->length_);
    OBJECT_RELEASE(arr->values_[index]);
    
    arr->length_--;
    for (int i = index; i<arr->length_; i++) {
        arr->values_[i] = arr->values_[i+1];
    }
}

void ArrayDestory(Array *arr) {
    
    for (int j = 0; j<arr->length_; j++) {
        OBJECT_RELEASE(arr->values_[j]);
    }
    free(arr->values_);
    free(arr);
    printf("array was destroyed\n");
}
