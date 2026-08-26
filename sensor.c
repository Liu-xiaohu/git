#include "sensor.h"

SensorData g_sensor_list[SENSOR_CNT];

void Sensor_Init(SensorData* dev,const char* id)
{
    CHECK_PTR_VOID(dev);
    my_strcpy(dev->id,id);
    dev->temp=0;
    dev->humi=0;
    dev->light=0;
    dev->timestamp=0;
}

void Sensor_Read(SensorData* dev)
{
    CHECK_PTR_VOID(dev);
    //模仿随机采集
    dev->temp=(20.0f+rand()%300)/10.0f;
    dev->humi=(30.0f+rand()%400)/10.0f;
    dev->light=rand()%10000;
    dev->timestamp=(int)time(NULL);
}

void Sensor_Print(const SensorData* dev)
{
    CHECK_PTR_VOID(dev);
    printf("[%s] time:%d  temp:%.1f℃  humi:%.1f%%  light:%d\n",
           dev->id, dev->timestamp, dev->temp, dev->humi, dev->light);
}

void Sensor_PrintAll(SensorData devs[],int count)
{
    for(int i=0;i<count;i++)
    {
        Sensor_Print(&devs[i]);
    }
}