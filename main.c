#include "utils.h"
#include "device.h"
#include "sensor.h"

#define BUF_LEN 128
int main(void)
{
    char buf[BUF_LEN];
    srand((unsigned)time(NULL));

    //初始化
    Device_Init();
    Sensor_Init(&g_sensor_list[0],"dev_01");
    Sensor_Init(&g_sensor_list[1],"dev_02");
    Sensor_Init(&g_sensor_list[2],"dev_03");

    printf("==== IoT Sensor System ====\n");
    printf("help:show help | read:collect data | led on n / led off n | status | exit\n");

    while(1)
    {
        printf(">");
        fgets(buf,BUF_LEN,stdin);
        //去掉换行符
        for(int i=0;buf[i]!='\0';i++)
        {
            if(buf[i]=='\n'||buf[i]=='\r')
            {
                buf[i]='\0';
                break;
            }
        }

        if(my_strcmp(buf,"exit")==0)
        {
            printf("exit system\n");
            break;
        }
        else if(my_strcmp(buf,"help")==0)
        {
            printf("read       → collect all sensor data\n");
            printf("led on n   → turn on led n(0~7)\n");
            printf("led off n  → turn off led n(0~7)\n");
            printf("status     → show device reg status\n");
            printf("exit       → quit\n");
        }
        else if(my_strcmp(buf,"read")==0)
        {
            for(int i=0;i<SENSOR_CNT;i++)
            {
                Sensor_Read(&g_sensor_list[i]);
            }
            Sensor_PrintAll(g_sensor_list,SENSOR_CNT);
        }
        else if(my_strcmp(buf,"status")==0)
        {
            printf("device reg = 0x%02X\n", Device_GetStatus());
        }
        else if(buf[0]=='l'&&buf[1]=='e'&&buf[2]=='d')
        {
            //简易解析led on 1
            char op[16];
            int num;
            sscanf(buf,"led %s %d",op,&num);
            if(my_strcmp(op,"on")==0)
            {
                LED_On((uint8_t)num);
                printf("led %d on\n",num);
            }
            else if(my_strcmp(buf,"off")==0)
            {
                LED_Off((uint8_t)num);
                printf("led %d off\n",num);
            }
        }
        else
        {
            printf("指令错误,输入help查看帮助\n");
        }
        
    }
    return 0;
}