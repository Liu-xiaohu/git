#ifndef __DEVICE_H__
#define __DEVICE_H__
#include "utils.h"

void Device_Init(void);
void LED_On(uint8_t);
void LED_Off(uint8_t);
uint8_t Device_GetStatus(void);

#endif