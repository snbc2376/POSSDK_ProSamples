#include "LoadPOSSDK_PRO.h"
#include "SampleSupermarket.h"

extern pPrintText mPrintText;
extern pQueryStatus mQueryStatus;
extern pPaperCut mPaperCut;
extern pFeedLines mFeedLines;
extern pPrintImageFile mPrintImageFile;
extern pBarCodePrint mBarCodePrint;

int Sample_Supermarket(int handle, char *errorStatus)
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

	char *lineBetwen = "------------------------------------------------\n";
	//居中打印logo
	nRet = mPrintImageFile(handle, "../../resource/SAMPLELOGO.jpg", "x=-2");

	// Sample
	nRet = mPrintText(handle,"超市：小叮当超市\n","Align=1");
	nRet = mPrintText(handle, "地址：XX市XX区96号\n", "");
	nRet = mPrintText(handle, "商品名称               单价    数量	  金额\n", "Align=0|Bold=1");
	nRet = mPrintText(handle, lineBetwen, "");
	nRet = mPrintText(handle, "001 铁观音乌龙碎150g\n", "Bold=0");
	nRet = mPrintText(handle, "6923182120134		12.00	1	12.00\n", "");
	nRet = mPrintText(handle, "002 蓝莓原汁酒 740ml\n", "");
	nRet = mPrintText(handle, "6923182120710		20.00	1	20.00\n", "");
	nRet = mPrintText(handle, "003 完达山原味酸奶\n", "");
	nRet = mPrintText(handle, "6923182121211		21.00	1	21.00\n", "");
	nRet = mPrintText(handle, "004 购物袋500*300\n", "");
	nRet = mPrintText(handle, "6945582900024		0.20	1	0.20\n", "");
	nRet = mPrintText(handle, "[会员优惠]                              -5.20\n", "");
	nRet = mPrintText(handle, lineBetwen, "");
	nRet = mPrintText(handle, "合计               53.20\n", "HScale=2|VScale=2");
	nRet = mPrintText(handle, "优惠               -5.20\n", "HScale=2|VScale=2");
	nRet = mPrintText(handle, "\n", "");
	nRet = mPrintText(handle, "现金                                    48.00\n", "HScale=1|VScale=1");
	nRet = mPrintText(handle, "已收金额                                50.00\n", "");
	nRet = mPrintText(handle, "现金找零                                2.00\n", "");
	nRet = mPrintText(handle, "************************************************\n", "");
	mFeedLines(handle, 1);
	mBarCodePrint(handle, BarCode_Code128, "1234567890123", strlen("1234567890123"), "x=-3");
	nRet = mPrintText(handle, "谢谢惠顾，欢迎再次光临\n", "Align=1");
	nRet = mPaperCut(handle, 0, 0);
	
	// check status
	nStatus = mQueryStatus(handle, cStatus);
	if (!strcmp(cStatus, "Normal") == 0 && !strcmp(cStatus, "PaperNearEnd") == 0)
	{
		strcpy(errorStatus, cStatus);
		return nStatus;
	}

	return nRet;
}

int Sample_Supermarket_En(int handle, char *errorStatus)
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

	char *lineBetwen = "------------------------------------------------\n";
	//logo
	nRet = mPrintImageFile(handle, "../../resource/SAMPLELOGO.jpg", "x=-2");

	// Sample
	nRet = mPrintText(handle, "CUSTOMER COPY\n", "Bold=1|Align=1");
	nRet = mPrintText(handle, "Date:11/01/2022 11:34:25 am\n", "Align=0");
	nRet = mPrintText(handle, "Cashier		HKDM\n", "");
	nRet = mPrintText(handle, "SalesPerson:HONGKONG HK\n", "");
	nRet = mPrintText(handle, "Subsidiary:1				 WS:4\n", "");
	nRet = mPrintText(handle, "StoreCode:001\n", "");
	nRet = mPrintText(handle, lineBetwen, "");
	nRet = mPrintText(handle, "LN# ITEM		PRICE	  QTY	 Net(HKD)\n", "");
	nRet = mPrintText(handle, lineBetwen, "");
	nRet = mPrintText(handle, "1-00008853		6.00	   1	 6.00\n", "Bold=0");
	nRet = mPrintText(handle, lineBetwen, "");
	nRet = mPrintText(handle, "Total Qty:				 1\n", "Bold=1");
	nRet = mPrintText(handle, "Total Amount(HKD):			 6.00\n", "");
	nRet = mPrintText(handle, "Rounded Amount:				 0\n", "Bold=0");
	nRet = mPrintText(handle, "Total Sales:				 1\n", "");
	nRet = mPrintText(handle, "Total Return:				-0\n", "");
	nRet = mPrintText(handle, "Total Disc Amount(HKD) :\n", "Bold=1");
	nRet = mPrintText(handle, "Total Original Price(HKD):		 6\n", "Bold=1");
	nRet = mPrintText(handle, lineBetwen, "");
	nRet = mPrintText(handle, "Cash					 6.00\n", "Bold=0");
	nRet = mFeedLines(handle, 1);
	mBarCodePrint(handle, BarCode_Code128, "1234567890123", strlen("1234567890123"), "x=-3");
	nRet = mPrintText(handle, "Thank you for shopping at M&S.\n", "Align=1|Bold=1");
	nRet = mPaperCut(handle, 0, 0);

	// check status
	nStatus = mQueryStatus(handle, cStatus);
	if (!strcmp(cStatus, "Normal") == 0 && !strcmp(cStatus, "PaperNearEnd") == 0)
	{
		strcpy(errorStatus, cStatus);
		return nStatus;
	}

	return nRet;
}



