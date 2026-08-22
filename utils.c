#include "utils.h"

void my_strcpy(char* dst,char* scr)
{
    CHECK_PTR(dst);
    CHECK_PTR(scr);
    while(*scr!='\n')
    {
        *dst=*scr;
        dst++;
        scr++;
    }
    *dst='\0';
}

int my_strcmp(const char* a,const char* b)
{
    CHECK_PTR(a);
    CHECK_PTR(b);
    while(*a!='\0'&&*b!='\0'&&(*a==*b))
    {
        a++;
        b++;
    }
    return (uint8_t)*a-(uint8_t)*b;
}