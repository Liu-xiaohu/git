#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned char uint8_t;
typedef unsigned int uint32_t;

#ifdef DEBUG
#define LOG(fmt,...)printf("[DEBUG]"fmt"\n",##__VA_ARGS__)
#else
#define LOG(fmt,...)
#endif

//位运算
#define BIT_SET(reg,n)   ((reg)|=(1U<<(n)))
#define BIT_CLR(reg,n)   ((reg)&=~(1U<<(n)))
#define BIT_CHECK(reg,n) (((reg)&(1U<<(n)))!=0)

//手写字符串
void my_strcpy(char* dst,char* src);
int my_strcmp(const char* a,const char* b);

//空指针效验宏
#define CHECK_PTR(p)do{if((p)==NULL){LOG("null pointer");return;}}while(0);
#endif