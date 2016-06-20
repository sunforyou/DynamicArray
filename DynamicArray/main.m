//
//  main.m
//  DynamicArray
//
//  Created by 宋旭 on 16/3/15.
//  Copyright © 2016年 sky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Array.h"
#import "Object.h"
#import "People.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
#pragma mark －－ 创建动态数组并添加元素
        Array *arr = ArrayCreate();
        People *p1 = PeopleNew(1, "小明", 20);
        People *p2 = PeopleNew(2, "大明", 21);
        People *p3 = PeopleNew(3, "小李", 22);
        People *p4 = PeopleNew(4, "小张", 24);
        People *p5 = PeopleNew(5, "小马", 28);
        People *p6 = PeopleNew(6, "小陈", 29);
        People *p7 = PeopleNew(7, "小蔡", 25);
        People *p8 = PeopleNew(8, "小王", 26);
        
        ArrayAdd(arr, (Object *)p1);
        ArrayAdd(arr, (Object *)p2);
        ArrayAdd(arr, (Object *)p3);
        ArrayAdd(arr, (Object *)p4);
        ArrayAdd(arr, (Object *)p5);
        ArrayAdd(arr, (Object *)p6);
        ArrayAdd(arr, (Object *)p7);
        ArrayAdd(arr, (Object *)p8);
        
        printf("数组创建成功，插入几个元素:\n");
        
        for (int i = 0; i<ArrayGetLength(arr); i++) {
            printf("位置: %d,名字: %s,年龄: %d\n",i+1,PeopleGetName((People*)ArrayGet(arr, i)),PeopleGetAge((People*)ArrayGet(arr, i)));
        }
        
#pragma mark －－ 删除元素
        printf("\n把小李删掉再打印一遍，(删除元素)\n");
        
        ArrayRemoveAt(arr, 2);
        for (int i = 0; i<ArrayGetLength(arr); i++) {
            printf("位置: %d,名字: %s,年龄: %d\n",i+1,PeopleGetName((People*)ArrayGet(arr, i)),PeopleGetAge((People*)ArrayGet(arr, i)));
        }
        
#pragma mark －－ 插入元素
        printf("\n欢迎老王，(插入元素)\n");
        People *p9 = PeopleNew(6, "老王", 50);
        
        ArrayInsert(arr, 5, (Object *)p9);
        for (int i = 0; i<ArrayGetLength(arr); i++) {
            printf("位置: %d,名字: %s,年龄: %d\n",i+1,PeopleGetName((People*)ArrayGet(arr, i)),PeopleGetAge((People*)ArrayGet(arr, i)));
        }
        
#pragma mark －－ 查询元素
        printf("\n(查询元素)请输入要查询的位置\n");
        printf("提示:您输入的整数应在0-%d之间\n",arr->length_-1);
        int position;
        scanf("%d",&position);
        if (position >= arr->length_) {
            printf("\n对不起，您输入的位置超出教室范围\n");
        }else{
            printf("他是%s,今年%d岁\n",PeopleGetName((People*)ArrayGet(arr, position)),PeopleGetAge((People*)ArrayGet(arr, position)));
        }
        
#pragma mark －－ 内存管理
        ArrayDestory(arr);
        PeopleDestory(p1);
        PeopleDestory(p2);
        PeopleDestory(p3);
        PeopleDestory(p4);
        PeopleDestory(p5);
        PeopleDestory(p6);
        PeopleDestory(p7);
        PeopleDestory(p8);
        PeopleDestory(p9);
        
    }
    return 0;
}
