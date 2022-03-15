#include "LoadPOSSDK_PRO.h"
#include "SampleImage.h"

extern pPrintText mPrintText;
extern pPaperCut mPaperCut;
extern pFeedLines mFeedLines;
extern pPrintImageFile mPrintImageFile;
extern pPrintDownloadedImage mPrintDownloadedImage;
extern pDownloadImage mDownloadImage;

int Sample_PrintImage(int handle)
{
	int result = SUCCESS;

	// Alignment and offset
	char *alginFileName = "../../resource/01.bmp";
	mPrintText(handle, "=====================\n", "");
	mPrintText(handle, "Alignment and offset, x = -1\n", "");
	mPrintImageFile(handle, alginFileName, "x=-1");

	mPrintText(handle, "Alignment and offset, x = 50\n", "");
	mPrintImageFile(handle, alginFileName, "x=50");

	mPrintText(handle, "Alignment and offset, x = -2\n", "");
	mPrintImageFile(handle, alginFileName, "x=-2");

	mPrintText(handle, "Alignment and offset, x = -3\n", "");
	mPrintImageFile(handle, alginFileName, "x=-3");


	// Zoom
	mPrintText(handle, "=====================\n", "");
	char *zoomFileName = "../../resource/01.bmp";
	mPrintText(handle, "Zoom, Scale = 20\n", "");
	mPrintImageFile(handle, zoomFileName, "x=-2|Scale=20");

	mPrintText(handle, "Zoom, Scale = 50\n", "");
	mPrintImageFile(handle, zoomFileName, "x=-2|Scale=50");

	mPrintText(handle, "Zoom, Scale = 100\n", "");
	mPrintImageFile(handle, zoomFileName, "x=-2|Scale=100");

	mPrintText(handle, "Zoom, Scale = 200\n", "");
	mPrintImageFile(handle, zoomFileName, "x=-2|Scale=200");

	mPrintText(handle, "Zoom, Width = 100, Height = 200\n", "");
	mPrintImageFile(handle, zoomFileName, "x=-2|Width=100|Height=200");

	mPrintText(handle, "Zoom, Width = 200, Height = 100\n", "");
	mPrintImageFile(handle, zoomFileName, "x=-2|Width=200|Height=100");


	// Dither
	mPrintText(handle, "=====================\n", "");
	char *DitherFileName = "../../resource/dither.jpg";
	mPrintText(handle, "Dither, Dither = 0, Threshold = -1\n", "");
	mPrintImageFile(handle, DitherFileName, "x=-2|Dither=0|Threshold=-1");

	mPrintText(handle, "Dither, Dither = 0, Threshold = 100\n", "");
	mPrintImageFile(handle, DitherFileName, "x=-2|Dither=0|Threshold=100");

	mPrintText(handle, "Dither, Dither = 1\n", "");
	mPrintImageFile(handle, DitherFileName, "x=-2|Dither=1");

	mPrintText(handle, "Dither, Dither = 2\n", "");
	mPrintImageFile(handle, DitherFileName, "x=-2|Dither=2");

	mPrintText(handle, "Dither, Dither = 3\n", "");
	mPrintImageFile(handle, DitherFileName, "x=-2|Dither=3");


	// Type
	mPrintText(handle, "=====================\n", "");
	mPrintText(handle, "PNG\n", "");
	mPrintImageFile(handle, "../../resource/1.png", "x=-2|Dither=3");
	
	mPrintText(handle, "JPEG\n", "");
	mPrintImageFile(handle, "../../resource/2.jpg", "x=-2|Dither=3");

	mPrintText(handle, "TIF\n", "");
	mPrintImageFile(handle, "../../resource/3.tif", "x=-2|Dither=3");

	mPrintText(handle, "GIF\n", "");
	mPrintImageFile(handle, "../../resource/4.gif", "x=-2|Dither=3");

	// RAM
	mPrintText(handle, "=====================\n", "");
	mPrintText(handle, "DownLoadImage RAM\n", "");
	result = mDownloadImage(handle, IMAGE_TYPE_RAM, "../../resource/RAM1.bmp|../../resource/RAM2.bmp|../../resource/RAM3.bmp", "");
	if (result == SUCCESS)
	{
		result = mPrintDownloadedImage(handle, IMAGE_TYPE_RAM, 1, "X=-2");
		result = mPrintDownloadedImage(handle, IMAGE_TYPE_RAM, 2, "X=-2");
		result = mPrintDownloadedImage(handle, IMAGE_TYPE_RAM, 3, "X=-2");
	}
	else
	{
		char error[256] = { 0 };
		sprintf(error, "DownLoadImage failed. error = %d\n", result);
		mPrintText(handle, error, "");
	}

	// Flash
	mPrintText(handle, "=====================\n", "");
	mPrintText(handle, "DownLoadImage Flash\n", "");
	result = mDownloadImage(handle, IMAGE_TYPE_FLASH, "../../resource/Flash1.bmp|../../resource/Flash2.bmp|../../resource/Flash3.bmp", "");
	if (result == SUCCESS)
	{
		result = mPrintDownloadedImage(handle, IMAGE_TYPE_FLASH, 1, "X=-2");
		result = mPrintDownloadedImage(handle, IMAGE_TYPE_FLASH, 2, "X=-2");
		result = mPrintDownloadedImage(handle, IMAGE_TYPE_FLASH, 3, "X=-2");
	}
	else
	{
		char error[256] = { 0 };
		sprintf(error, "DownLoadImage failed. error = %d\n", result);
		mPrintText(handle, error, "");
	}

	//ÇÐÖ½ Cut Paper
	result = mPaperCut(handle, 0, 0);

	return result;
}

