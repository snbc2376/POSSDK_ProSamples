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
	if (!strcmp(cStatus, "Normal") == 0 && !strcmp(cStatus, "PaperNearEnd") == 0)
	{
		strcpy(errorStatus, cStatus);
		return nStatus;
	}

	//具体打印内容
	char *xmlStr = "<pos-print>\
		<image x='10'>../../resource/maoyan.jpg</image>\
		<text x='10'>成都市和平电影院&#xA;</text>\
		<text x='10'>夏洛特烦恼（2D）&#xA;</text>\
		<text x='10' scale-h='2' scale-v='2'>三楼2号厅		16:00&#xA;</text>\
		<text x='10' scale-h='2' scale-v='2'>三排4列	   2020-07-20&#xA;</text>\
		<page width='600' height='600' x='0' y='0'>\
		<symbol type='qr' x='10' y='260' width='9'>www.baidu.com</symbol>\
		<text x='250' y='30' scale-h='1' scale-v='1'>票价：0.1元&#xA;</text>\
		<text x='250' y='60'>服务费：3元&#xA;</text>\
		<text x='250' y='90'>07-20 15:48出票&#xA;</text>\
		<text x='250' y='130'>网络售票&#xA;</text>\
		<text x='250' y='160'>156547789&#xA;</text>\
		</page>\
		<cut/>\
		</pos-print>";


	nRet = mPrintContent(handle, 0, xmlStr);

	//查状态
	nStatus = mQueryStatus(handle, cStatus);
	if (!strcmp(cStatus, "Normal") == 0 && !strcmp(cStatus, "PaperNearEnd") == 0)
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
	if (!strcmp(cStatus, "Normal") == 0 && !strcmp(cStatus, "PaperNearEnd") == 0)
	{
		strcpy(errorStatus, cStatus);
		return nStatus;
	}

	//具体打印内容
	char *xmlStr = "<pos-print>\
		<text scale-h='2' scale-v='2'>Great Lakes Unit2911&#xA;</text>\
		<text scale-h='2' scale-v='2'>WORLD WAR X IMAX 3D&#xA;</text>\
		<text scale-h='2' scale-v='2'>1:20pm Thu 8/8/2013&#xA;</text>\
		<text scale-h='1' scale-v='1'>ADGADSS S10.50&#xA;</text>\
		<page width='600' height='150' x='0' y='0'>\
		<text x='100' y='120' scale-h='4' scale-v='4' bold='1'>24&#xA;</text>\
		<text x='200' y='100' scale-h='4' scale-v='4' bold='0'>PG13&#xA;</text>\
		</page>\
		<barcode type='code128' align='center'>006776140094001</barcode>\
		<text scale-h='1' scale-v='1'>STATION: 006 8/8/2013 1:01pm&#xA;</text>\
		<cut/>\
		</pos-print>";

	nRet = mPrintContent(handle, 0, xmlStr);
	// check status
	nStatus = mQueryStatus(handle, cStatus);
	if (!strcmp(cStatus, "Normal") == 0 && !strcmp(cStatus, "PaperNearEnd") == 0)
	{
		strcpy(errorStatus, cStatus);
		return nStatus;
	}

	return nRet;
}



