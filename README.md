# 物联网设备数据采集管理系统

## 项目简介
基于C语言实现的纯命令行物联网终端模拟系统，模拟多路传感器数据采集、LED外设控制、命令行交互等功能，采用模块化多文件工程架构。

## 功能特性
- 多路温湿度、光照传感器数据模拟采集与打印
- 位运算模拟硬件寄存器，实现LED灯开关控制
- 命令行交互，支持多条控制指令
- 模块化拆分，低耦合设计
- 空指针校验、参数保护，具备基础工程健壮性

## 编译运行
环境：Windows + MinGW GCC / Linux GCC
```bash
gcc main.c device.c sensor.c utils.c -o sensor_system
./sensor_system
