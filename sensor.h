#ifndef __SENSOR_H__
#define __SENSOR_H__
#include "utils.h"

#define SENSOR_CNT 3
typedef struct
{
    char id[16];
    float temp;
    float humi;
    int light;
    int timestamp;
}SensorData;

//全局传感器数组
extern SensorData g_sensor_list[SENSOR_CNT];

void Sensor_Init(SensorData* dev,const char* id);
void Sensor_Read(SensorData* dev);
void Sensor_Print(const SensorData* dev);
void Sensor_PrintAll(SensorData* devs[],int count);

#endif