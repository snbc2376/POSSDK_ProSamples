#pragma once

//*****************API function sample********************************************
//打开设备
//Open printer
int Sample_Open(char *model, char *portInfo);

//关闭设备
//Close printer
int Sample_Close(int handle);

//枚举设备列表
//Enumerate device list
int Sample_EnumDevice(int type, char *deviceList, int deviceListLen);



