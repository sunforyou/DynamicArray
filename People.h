//
//  People.h
//  DynamicArray
//
//  Created by 宋旭 on 16/3/16.
//  Copyright © 2016年 sky. All rights reserved.
//

#ifndef People_h
#define People_h

#include <stdio.h>

typedef struct People {
    int retainCount_;
    int position;
    char *name;
    int age;
} People;

///生成机器人
People *PeopleNew(int position,char *name,int age);

///给机器人命名
char* PeopleGetName(People *person);

///获取机器人姓名
int PeopleGetAge(People *person);

///销毁机器人
void PeopleDestory(People *person);

#endif /* People_h */
