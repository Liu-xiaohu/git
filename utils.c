#include "utils.h"

void my_strcpy(char* dst,const char* scr)
{
    CHECK_PTR_VOID(dst);
    CHECK_PTR_VOID(scr);
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
    CHECK_PTR_RET(a);
    CHECK_PTR_RET(b);
    while(*a!='\0'&&*b!='\0'&&(*a==*b))
    {
        a++;
        b++;
    }
    return (uint8_t)*a-(uint8_t)*b;
}