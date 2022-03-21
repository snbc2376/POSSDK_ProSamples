#include "LoadPOSSDK_PRO.h"
#include "SampleBankQueue.h"

extern pQueryStatus mQueryStatus;
extern pPrintContent mPrintContent;

int Sample_BankQueue(int handle, char *errorStatus)
{
	int nRet = SUCCESS;
	int nStatus = 0;
	char cStatus[128] = { 0 };

	//��ӡǰ����״̬
	nStatus = mQueryStatus(handle, cStatus);
	if (!strcmp(cStatus, "Normal") == 0)
	{
		strcpy(errorStatus, cStatus);
		return nStatus;
	}
	//�����ӡ����
	char *xmlStr = "<pos-print>\
		<image>../../resource/SAMPLELOGO.jpg</image>\
		<text>��������ҵ�񣺴�ȡ��&#xA;</text>\
		<page width='600' height='300' x='0' y='0'>\
		<text x='200' y='20'>�ŶӺ��룺&#xA;</text>\
		<text x='300' y='20' bold='true' scale-h='2' scale-v='4'>A0486&#xA;</text>\
		<text x='100' y='80'>�����ڵ��ŶӶ���ǰ����&#xA;</text>\
		<text x='350' y='80'scale-h='2' scale-v='4'>41&#xA;</text>\
		<text x='370' y='80'>�˵Ⱥ�&#xA;</text>\
		</page>\
		<text align='center'>����������кţ���������&#xA;</text>\
		<text align='center'>�Ŷ���֤�룺12052400-1010 4860&#xA;</text>\
		<text align='center'>------------------------------------------------&#xA;</text>\
		<text align='center'>2022-03-17 18:15:33 ����Ӫҵ��&#xA;</text>\
		<text align='center'>�����Ʊ��ܱ�ƾ��&#xA;</text>\
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

int Sample_BankQueue_En(int handle, char *errorStatus)
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

	//�����ӡ����
	char *xmlStr = "<pos-print>\
		<image>../../resource/SAMPLELOGO.jpg</image>\
		<text>Your hosting business: deposits and withdrawals&#xA;</text>\
		<page width='600' height='300' x='0' y='0'>\
		<text x='200' y='20'>Queue number:&#xA;</text>\
		<text x='300' y='20' bold='true' scale-h='2' scale-v='4'>A0486&#xA;</text>\
		<text x='100' y='80'>There are&#xA;</text>\
		<text x='150' y='80'scale-h='2' scale-v='4'>41&#xA;</text>\
		<text x='170' y='80'>people waiting in front of your queue&#xA;</text>\
		</page>\
		<text align='center'>Please be patient and pay attention to the call number, the number will be invalid&#xA;</text>\
		<text align='center'>Queue verification code: 12052400-1010 4860&#xA;</text>\
		<text align='center'>------------------------------------------------&#xA;</text>\
		<text align='center'>2022-03-17 18:15:33 Branch Sales Department&#xA;</text>\
		<text align='center'>Please keep this receipt&#xA;</text>\
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



