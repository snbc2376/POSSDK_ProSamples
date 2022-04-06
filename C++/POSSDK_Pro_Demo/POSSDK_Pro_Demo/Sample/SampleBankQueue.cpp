#include "LoadPOSSDK_PRO.h"
#include "SampleBankQueue.h"

extern pQueryStatus mQueryStatus;
extern pPrintContent mPrintContent;

int Sample_BankQueue(int handle, char *errorStatus)
{
	int nRet = SUCCESS;
	int nStatus = 0;
	char cStatus[128] = { 0 };

	//打印前查下状态
	nStatus = mQueryStatus(handle, cStatus);
	if (!strcmp(cStatus, "Normal") == 0 && !strcmp(cStatus, "PaperNearEnd") == 0)
	{
		strcpy(errorStatus, cStatus);
		return nStatus;
	}
	//具体打印内容
	char *xmlStr = "<pos-print>\
		<image align='center'>../../resource/SAMPLELOGO.jpg</image>\
		<text>您的主办业务：存取款&#xA;</text>\
		<page width='600' height='210' x='0' y='0'>\
		<text x='200' y='100'>排队号码：&#xA;</text>\
		<text x='320' y='100' bold='true' scale-h='2' scale-v='4'>A0486&#xA;</text>\
		<text x='100' y='200'scale-h='1' scale-v='1'>你所在的排队队列前还有&#xA;</text>\
		<text x='370' y='200'scale-h='2' scale-v='4'>41&#xA;</text>\
		<text x='410' y='200'scale-h='1' scale-v='1'>人等候&#xA;</text>\
		</page>\
		<text align='center'>请耐心留意叫号，过号作废&#xA;</text>\
		<text align='center'>排队验证码：12052400-1010 4860&#xA;</text>\
		<text align='center'>------------------------------------------------&#xA;</text>\
		<text align='center'>2022-03-17 18:15:33 分行营业部&#xA;</text>\
		<text align='center'>请妥善保管本凭条&#xA;</text>\
		<cut/>\
		</pos-print>";

	nRet = mPrintContent(handle, 0, xmlStr);
	if (nRet!=0)
	{
		return nRet;
	}
	// check status
	nStatus = mQueryStatus(handle, cStatus);
	if (!strcmp(cStatus, "Normal") == 0 && !strcmp(cStatus, "PaperNearEnd") == 0)
	{
		strcpy(errorStatus, cStatus);
		return nStatus;
	}

	return nRet;
}

int Sample_BankQueue_En(int handle, char *errorStatus)
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
		<image align='center'>../../resource/SAMPLELOGO.jpg</image>\
		<text>Your hosting business: deposits and withdrawals&#xA;</text>\
		<page width='600' height='210' x='0' y='0'>\
		<text x='150' y='100'>Queue number:&#xA;</text>\
		<text x='320' y='100' bold='true' scale-h='2' scale-v='4'>A0486&#xA;</text>\
		<text x='100' y='200' scale-h='1' scale-v='1'>There are&#xA;</text>\
		<text x='230' y='200' scale-h='2' scale-v='4'>41&#xA;</text>\
		<text x='300' y='200' scale-h='1' scale-v='1'>people waiting in front of your queue&#xA;</text>\
		</page>\
		<text align='center'>Please be patient and pay attention to the call  number, the number will be invalid&#xA;</text>\
		<text align='center'>Queue verification code: 12052400-1010 4860&#xA;</text>\
		<text align='center'>------------------------------------------------&#xA;</text>\
		<text align='center'>2022-03-17 18:15:33 Branch Sales Department&#xA;</text>\
		<text align='center'>Please keep this receipt&#xA;</text>\
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



