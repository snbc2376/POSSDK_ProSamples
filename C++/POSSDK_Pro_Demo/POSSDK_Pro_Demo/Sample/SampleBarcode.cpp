#include "LoadPOSSDK_PRO.h"
#include "SampleBarcode.h"

extern pPrintText mPrintText;
extern pBarcodePrint mBarCodePrint;
extern pFeedLines mFeedLines;
extern pPaperCut mPaperCut;

int Sample_PrintBarCode(int handle)
{
	int result = SUCCESS;
	
	// Sample
	mPrintText(handle, "UPC-A\n", "");
	char *data_UPCA = "123456789012";
	result = mBarCodePrint(handle, BarCode_UPCA, data_UPCA, strlen(data_UPCA), "BasicWidth=3|Height=60");
	mFeedLines(handle, 1);

	mPrintText(handle, "UPC-E\n", "");
	char *data_UPCE = "023456789012";
	result = mBarCodePrint(handle, BarCode_UPCE, data_UPCE, strlen(data_UPCE), "BasicWidth=3|Height=60");
	mFeedLines(handle, 1);

	mPrintText(handle, "EAN13\n", "");
	char *data_EAN13 = "3456789012345";
	result = mBarCodePrint(handle, BarCode_EAN13, data_EAN13, strlen(data_EAN13), "BasicWidth=3|Height=60");
	mFeedLines(handle, 1);

	mPrintText(handle, "EAN8\n", "");
	char *data_EAN8 = "12345678";
	result = mBarCodePrint(handle, BarCode_EAN8, data_EAN8, strlen(data_EAN8), "BasicWidth=3|Height=60");
	mFeedLines(handle, 1);

	mPrintText(handle, "CODE39\n", "");
	char *data_CODE39 = "01234ABCDE $%+-./";
	result = mBarCodePrint(handle, BarCode_Code39, data_CODE39, strlen(data_CODE39), "BasicWidth=2|Height=60");
	mFeedLines(handle, 1);

	mPrintText(handle, "ITF\n", "");
	char *data_ITF = "01234567891234";
	result = mBarCodePrint(handle, BarCode_ITF, data_ITF, strlen(data_ITF), "BasicWidth=3|Height=60");
	mFeedLines(handle, 1);

	mPrintText(handle, "CODEBAR\n", "");
	char *data_CODEBAR = "A0123456789$+-./:D";
	result = mBarCodePrint(handle, BarCode_Codebar, data_CODEBAR, strlen(data_CODEBAR), "BasicWidth=2|Height=60");
	mFeedLines(handle, 1);

	mPrintText(handle, "CODE93\n", "");
	char *data_CODE93 = "01234ABCDE $%+-./";
	result = mBarCodePrint(handle, BarCode_Code93, data_CODE93, strlen(data_CODE93), "BasicWidth=3|Height=60");
	mFeedLines(handle, 1);

	mPrintText(handle, "CODE128\n", "");
	char *data_CODE128 = "01234ABCDExyz";
	result = mBarCodePrint(handle, BarCode_Code128, data_CODE128, strlen(data_CODE128), "BasicWidth=3|Height=60");
	mFeedLines(handle, 1);

	mPrintText(handle, "QR\n", "");
	char *data_QR = "0123456789ABCDEFGHIJKLmnopqrstuvwxyzºº×Ö";
	result = mBarCodePrint(handle, BarCode_QR, data_QR, strlen(data_QR), "");
	mFeedLines(handle, 1);

	mPrintText(handle, "PDF417\n", "");
	char *data_PDF417 = "0123456789ABCDEFGHIJKLmnopqrstuvwxyzºº×Ö";
	result = mBarCodePrint(handle, BarCode_PDF417, data_PDF417, strlen(data_PDF417), "");
	mFeedLines(handle, 1);

	mPrintText(handle, "MAXICODE\n", "");
	char *data_MAXICODE = "0123456789ABCDEFGHIJKLmnopqrstuvwxyz";
	result = mBarCodePrint(handle, BarCode_MAXICODE, data_MAXICODE, strlen(data_MAXICODE), "");
	mFeedLines(handle, 1);

	mPrintText(handle, "GS1\n", "");
	char *data_GS1 = "01234567891234";
	result = mBarCodePrint(handle, BarCode_GS1, data_GS1, strlen(data_GS1), "GS1Type=1");
	mFeedLines(handle, 1);

	//ÇÐÖ½ Cut Paper
	result = mPaperCut(handle, 0, 0);

	return result;
}


