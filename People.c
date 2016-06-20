//
//  People.c
//  DynamicArray
//
//  Created by 宋旭 on 16/3/16.
//  Copyright © 2016年 sky. All rights reserved.
//

#include "People.h"
#include <stdlib.h>
#include "Object.h"

People *PeopleNew(int position,char *name,int age) {
    
    People * human = malloc(sizeof(People));
    
    OBJECT_RETAIN(human);
    
    human->position = position;
    human->name = name;
    human->age = age;
    
    return human;
}

char* PeopleGetName(People *person) {
    return person->name;
}

int PeopleGetAge(People *person) {
    return person->age;
}

void PeopleDestory(People *person) {
    
    OBJECT_RELEASE(person);
}
