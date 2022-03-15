#include "LoadPOSSDK_PRO.h"
#include "SampleRestaurant.h"

extern pPrintText mPrintText;
extern pQueryStatus mQueryStatus;
extern pPaperCut mPaperCut;
extern pFeedLines mFeedLines;

int Sample_Restaurant(int handle, char *errorStatus)
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

	char *lineBetwen = "------------------------------------------------\n";
	// Sample
	nRet = mPrintText(handle, lineBetwen, "Bold=0|Align=0|HScale=1|VScale=1|Underline=0|Italics=0|Font=FontA");
	nRet = mPrintText(handle,"2020��04��10��09��48\n","");
	nRet = mPrintText(handle, lineBetwen, "");
	nRet = mPrintText(handle, "#20��������\n", "Bold=1|Align=1|HScale=2|VScale=2");
	nRet = mPrintText(handle, "�ж���ChelseaKitchen\n", "Bold=0|HScale=1|VScale=1");
	nRet = mPrintText(handle, "����֧��(��֧��)\n", "Bold=1|HScale=2|VScale=2");
	nRet = mPrintText(handle, "�����ţ�5415221202244734\n", "Bold=0|HScale=1|VScale=1");
	nRet = mPrintText(handle, "�µ�ʱ�䣺2021-04-10 10��00��00\n", "");
	nRet = mPrintText(handle, "---------------------1�ſڴ�--------------------\n", "Align=0");
	nRet = mPrintText(handle, "�������֭����X1                            32.9\n", "");
	nRet = mPrintText(handle, "7��Ũ��֥ʿ����X1                           34.9\n", "");
	nRet = mPrintText(handle, "��ʽ��̢2��װX1                                9\n", "");
	nRet = mPrintText(handle, "9�������������X1                           54.9\n", "");
	nRet = mPrintText(handle, "9��֥ʿ����X1                                 10\n", "");
	nRet = mPrintText(handle, "---------------------����-----------------------\n", "");
	nRet = mPrintText(handle, "[��100.0Ԫ��40.0Ԫ]\n", "");
	nRet = mPrintText(handle, "[�����ͷ�3.0Ԫ]\n", "");
	nRet = mPrintText(handle, "\n", "");
	nRet = mPrintText(handle, "�ͺзѣ�7\n", "");
	nRet = mPrintText(handle, "[���ͻݶ������� X 1]:\n", "");
	nRet = mPrintText(handle, lineBetwen, "");
	nRet = mPrintText(handle, "ԭ�ۣ���141.7  \n", "Align=2");
	nRet = mPrintText(handle, "ʵ������107.7 \n", "Bold=1|HScale=2|VScale=2");
	nRet = mPrintText(handle, lineBetwen, "Bold=0|Align=0|HScale=1|VScale=1");
	nRet = mPrintText(handle, "ͨ��ѧ����ԢA5-2\n", "Bold=1|HScale=2|VScale=2");
	nRet = mPrintText(handle, "�ţ�A5-107��\n", "Bold=0");
	nRet = mPrintText(handle, "131****0501\n", "");
	nRet = mPrintText(handle, "�գ�������\n", "");
	nRet = mPrintText(handle, lineBetwen, "HScale=1|VScale=1");
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

int Sample_Restaurant_En(int handle, char *errorStatus)
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

	// Sample
	nRet = mPrintText(handle, "XxxxXxxx\n", "Bold=1|Align=1|HScale=1|VScale=1|Underline=0|Italics=0|Font=FontA");
	nRet = mPrintText(handle, "201 East 31st St.\n", "Bold=0");
	nRet = mPrintText(handle, "New York, NY 10000\n", "");
	nRet = mPrintText(handle, "0344590786\n", "");
	nRet = mPrintText(handle, "\n", "");
	nRet = mPrintText(handle, "Server: Kristen                       Station: 7\n", "Align=0");
	nRet = mPrintText(handle, "------------------------------------------------\n", "");
	nRet = mPrintText(handle, "Order #: 123401                          Dine In\n", "");
	nRet = mPrintText(handle, "Table: L6                               Guest: 2\n", "");
	nRet = mPrintText(handle, "------------------------------------------------\n", "");
	nRet = mPrintText(handle, "1 Lamb Embuchado.                          12.00\n", "");
	nRet = mPrintText(handle, "1 NY Strip 6oz                             18.00\n", "");
	nRet = mPrintText(handle, "1 Mozzarella Flatbread                     10.00\n", "");
	nRet = mPrintText(handle, "1 Mahan                                     5.00\n", "");
	nRet = mPrintText(handle, "\n", "");
	nRet = mPrintText(handle, "Bar Subtotal:                               0.00\n", "");
	nRet = mPrintText(handle, "Food Subtotal:                             45.00\n", "");
	nRet = mPrintText(handle, "Tax:                                        3.99\n", "");
	nRet = mPrintText(handle, "                                        ========\n", "");
	nRet = mPrintText(handle, "TOTAL:            $49.00\n", "Bold=1|HScale=2|VScale=2");
	nRet = mPrintText(handle, "\n", "Bold=0|HScale=1|VScale=1");
	nRet = mPrintText(handle, ">> Ticket #: 11 <<\n", "Align=1");
	nRet = mPrintText(handle, "4/23/2019 7:03:24 PM\n", "");
	nRet = mPrintText(handle, "**********************************************\n", "");
	nRet = mPrintText(handle, "Join our mailing list for exclusive offers\n", "");
	nRet = mPrintText(handle, "\n", "");
	nRet = mPrintText(handle, "www.XxxxXxxx.com\n", "Underline=1");
	nRet = mPrintText(handle, "\n", "Underline=0");
	nRet = mPrintText(handle, "15% Gratuity = $6.75\n", "");
	nRet = mPrintText(handle, "18% Gratuity = $8.10\n", "");
	nRet = mPrintText(handle, "20% Gratuity = $9.00\n", "");
	nRet = mPrintText(handle, "22% Gratuity = $9.90\n", "");
	nRet = mPrintText(handle, "\n", "");
	nRet = mPrintText(handle, "**********************************************\n", "");
	nRet = mPrintText(handle, "Join Us For Our $5 Happy Hour Daily 5-8pm\n", "");

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



