//
//  blockInMemory.cpp
//  concurrency_lesson1
//
//  Created by FrankLiu on 2017/5/19.
//  Copyright © 2017年 FrankLiu. All rights reserved.
//
#include <cstring>
#include "blockInMemory.hpp"

char * getStr(){
    char *p1 = (char*)"abcde2";
    return p1;
}

char * getStr2() {
    char *p2 = (char *)"abcde2";
    return p2;
}

//heap memory

char *getHeapMem(int num){
    char *ptr = NULL;
    ptr = new char[num];
    //printf("length memory: %d\n", sizeof(ptr));
    return ptr;
}

//stack memory
char *getStackMem(int num){
    char buff[20];
    strcpy(buff, "233");
    return buff; // error as buff memory will be delete when this function is finished!
}

void call(){
    char *tmp = getHeapMem(20);
    strcpy(tmp, "123");
    //printf("%d\n", sizeof(tmp)/sizeof(char));
    //strncpy(tmp, "123", sizeof(tmp)/sizeof(char));
    printf("%s\n", tmp);
    delete tmp;
    tmp = getStackMem(20); // error; buff doen't exists
    strcpy(tmp, "ada");
    printf("%s\n", tmp);
    
    /*
    char *p1 = NULL;
    char *p2 = NULL;
    p1 = getStr();
    p2 = getStr2();
    
    printf("p1: %s, p2: %s\n", p1, p2);
    printf("address: p1: %d, p2: %d\n", p1, p2);
     */
}
