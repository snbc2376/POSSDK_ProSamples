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
	nRet = mPrintText(handle,"2020年04月10日09：48\n","");
	nRet = mPrintText(handle, lineBetwen, "");
	nRet = mPrintText(handle, "#20美团外卖\n", "Bold=1|Align=1|HScale=2|VScale=2");
	nRet = mPrintText(handle, "切尔西ChelseaKitchen\n", "Bold=0|HScale=1|VScale=1");
	nRet = mPrintText(handle, "在线支付(已支付)\n", "Bold=1|HScale=2|VScale=2");
	nRet = mPrintText(handle, "订单号：5415221202244734\n", "Bold=0|HScale=1|VScale=1");
	nRet = mPrintText(handle, "下单时间：2021-04-10 10：00：00\n", "");
	nRet = mPrintText(handle, "---------------------1号口袋--------------------\n", "Align=0");
	nRet = mPrintText(handle, "意大利茄汁意面X1                            32.9\n", "");
	nRet = mPrintText(handle, "7寸浓香芝士披萨X1                           34.9\n", "");
	nRet = mPrintText(handle, "葡式蛋挞2个装X1                                9\n", "");
	nRet = mPrintText(handle, "9寸培根土豆披萨X1                           54.9\n", "");
	nRet = mPrintText(handle, "9寸芝士加量X1                                 10\n", "");
	nRet = mPrintText(handle, "---------------------其他-----------------------\n", "");
	nRet = mPrintText(handle, "[满100.0元减40.0元]\n", "");
	nRet = mPrintText(handle, "[减配送费3.0元]\n", "");
	nRet = mPrintText(handle, "\n", "");
	nRet = mPrintText(handle, "餐盒费：7\n", "");
	nRet = mPrintText(handle, "[赠送惠尔康茶饮 X 1]:\n", "");
	nRet = mPrintText(handle, lineBetwen, "");
	nRet = mPrintText(handle, "原价：￥141.7  \n", "Align=2");
	nRet = mPrintText(handle, "实付：￥107.7 \n", "Bold=1|HScale=2|VScale=2");
	nRet = mPrintText(handle, lineBetwen, "Bold=0|Align=0|HScale=1|VScale=1");
	nRet = mPrintText(handle, "通鑫学生公寓A5-2\n", "Bold=1|HScale=2|VScale=2");
	nRet = mPrintText(handle, "号（A5-107）\n", "Bold=0");
	nRet = mPrintText(handle, "131****0501\n", "");
	nRet = mPrintText(handle, "苏（先生）\n", "");
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



