#include "LoadPOSSDK_PRO.h"
#include "SampleAPI.h"

extern pOpenPrinter mOpenPrinter;
extern pClosePrinter mClosePrinter;
extern pPrintText mPrintText;
extern pQueryStatus mQueryStatus;
extern pPaperCut mPaperCut;
extern pFeedLines mFeedLines;
extern pEnumDevice mEnumDevice;
extern pBarCodePrint mBarCodePrint;

int Sample_Open(char *model, char *portInfo)
{
	return mOpenPrinter(model, portInfo);
}

int Sample_Close(int handle)
{
	return mClosePrinter(handle);
}

int Sample_EnumDevice(int type, char * deviceList, int deviceListLen)
{
	return mEnumDevice(type, deviceList, deviceListLen);
}


