#include "LoadPOSSDK_Pro.h"

pOpenPrinter mOpenPrinter = NULL;
pClosePrinter mClosePrinter = NULL;
pPrintText mPrintText = NULL;
pQueryStatus mQueryStatus = NULL;
pPaperCut mPaperCut = NULL;
pFeedLines mFeedLines = NULL;
pEnumDevice mEnumDevice = NULL;
pBarCodePrint mBarCodePrint = NULL;
pPrintImageFile mPrintImageFile = NULL;
pPrintDownloadedImage mPrintDownloadedImage = NULL;
pDownloadImage mDownloadImage = NULL;
pPrintContent mPrintContent = NULL;

char libPath[MAX_PATH_SIZE] = { 0 };
void *libHandle = NULL;

int getFullLibPath()
{
#ifdef _WIN32
	sprintf(libPath, "./%s", libName);
#elif defined __linux__
	int proBits = (int)sizeof(void*) * 8; // 32 or 64
	sprintf(libPath, "../x%d/%s", proBits, libName);
#endif
	return 0;
}

int Load()
{
	int nRet = 0;

	getFullLibPath();

	nRet = LoadLib();
	if (nRet != 0)
	{
		return nRet;
	}

	nRet = LoadFunc();
	if (nRet != 0)
	{
		return nRet;
	}

	return 0;
}

int LoadLib()
{
	libHandle = Tool_LoadLib();
	if (libHandle == NULL)
	{
		return Tool_LoadError();
	}
	return 0;
}

int ReleaseLib()
{
	if (libHandle)
	{
		Tool_FreeLib();
	}
	return 0;
}

int LoadFunc()
{
	mOpenPrinter = (pOpenPrinter)Tool_LoadFunc("OpenPrinter");
	if (mOpenPrinter == NULL)
	{
		return Tool_LoadError();
	}

	mClosePrinter = (pClosePrinter)Tool_LoadFunc("ClosePrinter");
	if (mClosePrinter == NULL)
	{
		return Tool_LoadError();
	}

	mPrintText = (pPrintText)Tool_LoadFunc("PrintText");
	if (mPrintText == NULL)
	{
		return Tool_LoadError();
	}

	mQueryStatus = (pQueryStatus)Tool_LoadFunc("QueryStatus");
	if (mQueryStatus == NULL)
	{
		return Tool_LoadError();
	}

	mPaperCut = (pPaperCut)Tool_LoadFunc("PaperCut");
	if (mPaperCut == NULL)
	{
		return Tool_LoadError();
	}

	mFeedLines = (pFeedLines)Tool_LoadFunc("FeedLines");
	if (mFeedLines == NULL)
	{
		return Tool_LoadError();
	}

	mEnumDevice = (pEnumDevice)Tool_LoadFunc("EnumDevice");
	if (mEnumDevice == NULL)
	{
		return Tool_LoadError();
	}

	mBarCodePrint = (pBarCodePrint)Tool_LoadFunc("BarCodePrint");
	if (mBarCodePrint == NULL)
	{
		return Tool_LoadError();
	}

	mPrintImageFile = (pPrintImageFile)Tool_LoadFunc("PrintImageFile");
	if (mPrintImageFile == NULL)
	{
		return Tool_LoadError();
	}

	mPrintDownloadedImage = (pPrintDownloadedImage)Tool_LoadFunc("PrintDownloadedImage");
	if (mPrintDownloadedImage == NULL)
	{
		return Tool_LoadError();
	}

	mDownloadImage = (pDownloadImage)Tool_LoadFunc("DownloadImage");
	if (mDownloadImage == NULL)
	{
		return Tool_LoadError();
	}

	mPrintContent = (pPrintContent)Tool_LoadFunc("PrintContent");
	if (mPrintContent == NULL)
	{
		return Tool_LoadError();
	}

	return 0;
}

#ifdef _WIN32
void *Tool_LoadLib()
{
	return LoadLibraryA(libPath);
}
void *Tool_LoadFunc(char *funcName)
{
	if (libHandle)
	{
		return (void *)GetProcAddress((HMODULE)libHandle, funcName);
	}
	return NULL;
}
int Tool_LoadError(char *linuxError)
{
	return GetLastError();
}
int Tool_FreeLib()
{
	if (libHandle)
	{
		FreeLibrary((HMODULE)libHandle);
	}
	return 0;
}
#elif defined __linux__
void *Tool_LoadLib()
{
	return dlopen(libPath, RTLD_NOW | RTLD_GLOBAL);
}
void *Tool_LoadFunc(char *funcName)
{
	if (libHandle)
	{
		return dlsym(libHandle, funcName);
	}
	return NULL;
}
int Tool_LoadError(char *linuxError)
{
	if(linuxError != NULL)
	{
		strcpy(linuxError, dlerror());	
	}
	return -1;
}
int Tool_FreeLib()
{
	if (libHandle)
	{
		dlclose(libHandle);
	}
	return 0;
}
#endif

