#pragma once

//*****************API function sample********************************************
//���豸
//Open printer
int Sample_Open(char *model, char *portInfo);

//�ر��豸
//Close printer
int Sample_Close(int handle);

//ö���豸�б�
//Enumerate device list
int Sample_EnumDevice(int type, char *deviceList, int deviceListLen);



