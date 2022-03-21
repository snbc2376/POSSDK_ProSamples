#include "LoadPOSSDK_PRO.h"
#include "SampleMovieTicket.h"

extern pQueryStatus mQueryStatus;
extern pPrintContent mPrintContent;

int Sample_MovieTicket(int handle, char *errorStatus)
{
	int nRet = SUCCESS;
	int nStatus = 0;
	char cStatus[128] = { 0 };

	//打印前查状态
	nStatus = mQueryStatus(handle, cStatus);
	if (!strcmp(cStatus, "Normal") == 0)
	{
		strcpy(errorStatus, cStatus);
		return nStatus;
	}

	//具体打印内容
	char *xmlStr = "<pos-print>\
		<image>../../resource/maoyan.jpeg</image>\
		<text>成都市和平电影院&#xA;</text>\
		<text>夏洛特烦恼（2D）&#xA;</text>\
		<text scale-h='2' scale-v='2'>三楼2号厅		16:00&#xA;</text>\
		<text scale-h='2' scale-v='2'>三排四列	2020-07-20&#xA;</text>\
		<page width='600' height='300' x='0' y='0'>\
		<symbol type='qr' x='0' y='0' width='3'>www.baidu.com&#xA;</text>\
		<text x='300' y='20'>票价：0.1元&#xA;</text>\
		<text x='300' y='40'>服务费：3元&#xA;</text>\
		<text x='300' y='60'>07-20 15:48出票&#xA;</text>\
		<text x='300' y='100'>网络售票&#xA;</text>\
		<text x='300' y='120'>156547789&#xA;</text>\
		</page>\
		<cut/>\
		</pos-print>";

	nRet = mPrintContent(handle, 0, xmlStr);

	//查状态
	nStatus = mQueryStatus(handle, cStatus);
	if (!strcmp(cStatus, "Normal") == 0)
	{
		strcpy(errorStatus, cStatus);
		return nStatus;
	}

	return nRet;
}

int Sample_MovieTicket_En(int handle, char *errorStatus)
{
	int nRet = SUCCESS;
	int nStatus = 0;
	char cStatus[128] = { 0 };

	// check status
	nStatus = mQueryStatus(handle, cStatus);
	if (!strcmp(cStatus, "Normal") == 0)
	{
		strcpy(errorStatus, cStatus);
		return nStatus;
	}

	//具体打印内容
	char *xmlStr = "<pos-print>\
		<text scale-h='3' scale-v='3'>Great Lakes Unit2911&#xA;</text>\
		<text scale-h='3' scale-v='3'>WORLD WAR X IMAX 3D&#xA;</text>\
		<text scale-h='3' scale-v='3'>1:20pm Thu 8/8/2013&#xA;</text>\
		<text >ADGADSS S10.50&#xA;</text>\
		<page width='600' height='100' x='0' y='0'>\
		<text x='0' y='20' scale-h='4' scale-v='4' bold='1'>24&#xA;</text>\
		<text x='100' y='20' scale-h='4' scale-v='4'>PG13&#xA;</text>\
		</page>\
		<barcode type='code128' align='center'>006776140094001</barcode>\
		<text >STATION: 006 8/8/2013 1:01pm&#xA;</text>\
		<cut/>\
		</pos-print>";

	nRet = mPrintContent(handle, 0, xmlStr);
	// check status
	nStatus = mQueryStatus(handle, cStatus);
	if (!strcmp(cStatus, "Normal") == 0)
	{
		strcpy(errorStatus, cStatus);
		return nStatus;
	}

	return nRet;
}



