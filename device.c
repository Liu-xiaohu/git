#include "device.h"

//仅本文件可见 
static volatile uint8_t dev_reg;

void Device_Init(void)
{
    dev_reg=0U;
    LOG("device init ok");
}

void LED_On(uint8_t n)
{
    if(n>=8)
    {
        LOG("led num out of range");
        return;
    }
    BIT_SET(dev_reg,n);
}

void LED_Off(uint8_t n)
{
    if(n>=8)
    {
        LOG("led num out of range");
        return;
    }
    BIT_CLR(dev_reg,n);
}

uint8_t Device_GetStatus(void)
{
    return dev_reg;
}