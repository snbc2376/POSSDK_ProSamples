#include "LoadPOSSDK_PRO.h"
#include "SampleTrafficTicket.h"

extern pPrintText mPrintText;
extern pQueryStatus mQueryStatus;
extern pPaperCut mPaperCut;
extern pFeedLines mFeedLines;
extern pPrintImageFile mPrintImageFile;
extern pBarCodePrint mBarCodePrint;

int Sample_TrafficTicket(int handle, char *errorStatus)
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

	nRet = mPrintText(handle, "Υ��ͣ����֪��\n", "HScale=2|VScale=2|Align=1");
	nRet = mPrintText(handle,"��ţ�2301202300120339\n","HScale=1|VScale=1|Align=0");
	nRet = mPrintText(handle, "�����ƺţ���Az3456\n", "");
	nRet = mPrintText(handle, "������ɫ����\n", "");
	nRet = mPrintText(handle, "�������ͣ�С����ͨ�ͳ�\n", "");
	nRet = mPrintText(handle, "Υ��ͣ��ʱ�䣺\n", "");
	nRet = mPrintText(handle, "2021��05��20��21ʱ03��\n", "");
	nRet = mPrintText(handle, "Υ��ͣ���ص㣺\n", "");
	nRet = mPrintText(handle, "����·ȫ·��\n", "");
	nRet = mPrintText(handle, "		�û�����������ʱ�䡢�ص�ͣ�ţ�Υ���ˡ���·��ͨ��ȫ������56���Ĺ涨����\
��3�պ�15���ڳֱ���֪��������Ͻ��������ӽ�ͨΥ�������ڽ��ܴ���\n", "");
	mFeedLines(handle, 1);
	//���д�ӡӡ��
	nRet = mPrintImageFile(handle, "../../resource/01.bmp", "x=-2");
	nRet = mPrintText(handle, "2021��5��20��\n", "Align=2");
	nRet = mPrintText(handle, "��ע�������������˵Ǽǵ�ס����ַ������ϵ�绰�����仯�ģ���\
��ʱ��Ǽǵس���������������������\n", "Align=0");
	nRet = mPrintText(handle, "һʽ���ݣ�һ�����ڻ������ϣ�һ�ݸ���\n", "");
	nRet = mPaperCut(handle, 0, 0);
	
	//��״̬
	nStatus = mQueryStatus(handle, cStatus);
	if (!strcmp(cStatus, "Normal") == 0)
	{
		strcpy(errorStatus, cStatus);
		return nStatus;
	}

	return nRet;
}

int Sample_TrafficTicket_En(int handle, char *errorStatus)
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

	//logo
	nRet = mPrintImageFile(handle, "../../resource/01.bmp", "x=-2");

	// Sample
	nRet = mPrintText(handle, "Penalty Fare Notice\n", "Bold=1|HScale=3|VScale=3");
	nRet = mPrintText(handle, "APNRFN000021005\n", "");
	nRet = mPrintText(handle, "Amount Due:$20.00\n", "");
	nRet = mPrintText(handle, "This Penalty Fare Notice is given in accordance with the\
Penalty Faare Regulations 2018.\n", "Bold=0|HScale=1|VScale=1");
	nRet = mPrintText(handle, "Importance:Please quote the above Penalty Fare Notice number in all commucations\n", "");
	nRet = mPrintText(handle, "Date/Time:10/09/2018 07:54\n", "");
	nRet = mPrintText(handle, "Issued at:Liverpool lime Street\n", "");
	nRet = mPrintText(handle, "Issued on:\n", "");
	nRet = mPrintText(handle, "Issue Reason:No Ticket\n", "");
	nRet = mPrintText(handle, "Grounds Info:\n", "");
	nRet = mPrintText(handle, "From Wavertree Tech Park To Liverpool Lime Street\n", "");
	nRet = mPrintText(handle, "Class of Travel:Standard Class\n", "");
	nRet = mPrintText(handle, "Name:Mr Richerd Clark\n", "");
	nRet = mPrintText(handle, "Address:City\n", "");
	nRet = mPrintText(handle, "Date of Birth:\n", "");
	nRet = mPrintText(handle, "Adult/Child:Adult\n", "");
	nRet = mPrintText(handle, "Authorised Collector:352260\n", "");
	nRet = mPrintText(handle, "Penalty Fare Fine:$20.00\n", "");
	nRet = mPrintText(handle, "Amount Paid:$0.00\n", "");
	nRet = mPrintText(handle, "Amount Due:$20.00\n", "");
	nRet = mPrintText(handle, "This notice must be paid within 21 days beginning with \
the day following the day on which the notice is charged:\n", "");
	nRet = mPrintText(handle, "01/10/2018\n", "");
	nRet = mPaperCut(handle, 0, 0);

	// check status
	nStatus = mQueryStatus(handle, cStatus);
	if (!strcmp(cStatus, "Normal") == 0)
	{
		strcpy(errorStatus, cStatus);
		return nStatus;
	}

	return nRet;
}



