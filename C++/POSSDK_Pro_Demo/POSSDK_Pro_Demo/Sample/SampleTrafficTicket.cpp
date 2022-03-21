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

	//打印前查下状态
	nStatus = mQueryStatus(handle, cStatus);
	if (!strcmp(cStatus, "Normal") == 0)
	{
		strcpy(errorStatus, cStatus);
		return nStatus;
	}

	nRet = mPrintText(handle, "违法停车告知单\n", "HScale=2|VScale=2|Align=1");
	nRet = mPrintText(handle,"编号：2301202300120339\n","HScale=1|VScale=1|Align=0");
	nRet = mPrintText(handle, "车辆牌号：黑Az3456\n", "");
	nRet = mPrintText(handle, "车身颜色：白\n", "");
	nRet = mPrintText(handle, "车辆类型：小型普通客车\n", "");
	nRet = mPrintText(handle, "违法停车时间：\n", "");
	nRet = mPrintText(handle, "2021年05月20日21时03分\n", "");
	nRet = mPrintText(handle, "违法停车地点：\n", "");
	nRet = mPrintText(handle, "环阳路全路段\n", "");
	nRet = mPrintText(handle, "		该机动车在上述时间、地点停放，违反了《道路交通安全法》第56条的规定，请\
于3日后15日内持本告知单，到各辖区交警大队交通违法处理窗口接受处理。\n", "");
	mFeedLines(handle, 1);
	//居中打印印章
	nRet = mPrintImageFile(handle, "../../resource/01.bmp", "x=-2");
	nRet = mPrintText(handle, "2021年5月20日\n", "Align=2");
	nRet = mPrintText(handle, "备注：机动车所有人登记的住所地址或者联系电话发生变化的，请\
及时向登记地车辆管理所申请变更备案。\n", "Align=0");
	nRet = mPrintText(handle, "一式两份，一份贴于机动车上，一份附卷\n", "");
	nRet = mPaperCut(handle, 0, 0);
	
	//查状态
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



