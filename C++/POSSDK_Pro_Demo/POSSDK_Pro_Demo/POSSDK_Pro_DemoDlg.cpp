
// POSSDK_PRO_DemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "POSSDK_Pro_Demo.h"
#include "POSSDK_Pro_DemoDlg.h"
#include "afxdialogex.h"
#include <string>

// Sample
#include "Sample/LoadPOSSDK_Pro.h"
#include "Sample/SampleAPI.h"
#include "Sample/SampleRestaurant.h"
#include "Sample/SampleXML.h"
#include "Sample/SampleSupermarket.h"
#include "Sample/SampleBankQueue.h"
#include "Sample/SampleTrafficTicket.h"
#include "Sample/SampleMovieTicket.h"

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPOSSDK_PRO_DemoDlg dialog



CPOSSDK_PRO_DemoDlg::CPOSSDK_PRO_DemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_POSSDK_PRO_DEMO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPOSSDK_PRO_DemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPOSSDK_PRO_DemoDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO1, &CPOSSDK_PRO_DemoDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CPOSSDK_PRO_DemoDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO4, &CPOSSDK_PRO_DemoDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_BUTTON1, &CPOSSDK_PRO_DemoDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CPOSSDK_PRO_DemoDlg::OnBnClickedButton2)
ON_CBN_EDITCHANGE(IDC_COMBO2, &CPOSSDK_PRO_DemoDlg::OnCbnEditchangeCombo2)
ON_CBN_EDITCHANGE(IDC_COMBO3, &CPOSSDK_PRO_DemoDlg::OnCbnEditchangeCombo3)
ON_BN_CLICKED(IDC_BUTTON_EU, &CPOSSDK_PRO_DemoDlg::OnBnClickedButtonEu)
ON_BN_CLICKED(IDC_BUTTON_EE, &CPOSSDK_PRO_DemoDlg::OnBnClickedButtonEe)
ON_BN_CLICKED(IDC_BUTTON_SUPERMARKET, &CPOSSDK_PRO_DemoDlg::OnBnClickedButtonSupermarket)
ON_BN_CLICKED(IDC_BUTTON_BANK_QUEUE, &CPOSSDK_PRO_DemoDlg::OnBnClickedButtonBankQueue)
ON_BN_CLICKED(IDC_BUTTON_MOVIE_TICKET, &CPOSSDK_PRO_DemoDlg::OnBnClickedButtonMovieTicket)
ON_BN_CLICKED(IDC_BUTTON_TRAFFIC_TICKET, &CPOSSDK_PRO_DemoDlg::OnBnClickedButtonTrafficTicket)
END_MESSAGE_MAP()


// CPOSSDK_PRO_DemoDlg message handlers

BOOL CPOSSDK_PRO_DemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// Add extra initialization here
	getModelAndIdFromIni();
	((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(TRUE);
	updateUIByRadio();
	initUIValue();

	int nRet = Load();
	if (nRet)
	{
		MessageBox(_T("Load library error. ") + nRet);
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPOSSDK_PRO_DemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPOSSDK_PRO_DemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CPOSSDK_PRO_DemoDlg::OnBnClickedRadio1()
{
	updateUIByRadio();
}

void CPOSSDK_PRO_DemoDlg::OnBnClickedRadio2()
{
	updateUIByRadio();
}

void CPOSSDK_PRO_DemoDlg::OnBnClickedRadio4()
{
	updateUIByRadio();
}

void CPOSSDK_PRO_DemoDlg::updateUIByRadio()
{
	int radioCheck = getRadioCheck();

	switch (radioCheck)
	{
	case  RADIO_USB:
		((CComboBox*)GetDlgItem(IDC_COMBO2))->EnableWindow(FALSE);
		((CComboBox*)GetDlgItem(IDC_COMBO3))->EnableWindow(FALSE);
		((CComboBox*)GetDlgItem(IDC_COMBO4))->EnableWindow(TRUE);
		((CComboBox*)GetDlgItem(IDC_COMBO5))->EnableWindow(FALSE);
		((CButton*)GetDlgItem(IDC_BUTTON_EU))->EnableWindow(TRUE);
		((CButton*)GetDlgItem(IDC_BUTTON_EE))->EnableWindow(FALSE);
		break;
	case  RADIO_COM:
		((CComboBox*)GetDlgItem(IDC_COMBO2))->EnableWindow(TRUE);
		((CComboBox*)GetDlgItem(IDC_COMBO3))->EnableWindow(TRUE);
		((CComboBox*)GetDlgItem(IDC_COMBO4))->EnableWindow(FALSE);
		((CComboBox*)GetDlgItem(IDC_COMBO5))->EnableWindow(FALSE);
		((CButton*)GetDlgItem(IDC_BUTTON_EU))->EnableWindow(FALSE);
		((CButton*)GetDlgItem(IDC_BUTTON_EE))->EnableWindow(FALSE);
		break;
	case RADIO_NET:
		((CComboBox*)GetDlgItem(IDC_COMBO2))->EnableWindow(FALSE);
		((CComboBox*)GetDlgItem(IDC_COMBO3))->EnableWindow(FALSE);
		((CComboBox*)GetDlgItem(IDC_COMBO4))->EnableWindow(FALSE);
		((CComboBox*)GetDlgItem(IDC_COMBO5))->EnableWindow(TRUE);
		((CButton*)GetDlgItem(IDC_BUTTON_EU))->EnableWindow(FALSE);
		((CButton*)GetDlgItem(IDC_BUTTON_EE))->EnableWindow(TRUE);
		break;
	default:
		break;
	}
}

int CPOSSDK_PRO_DemoDlg::getRadioCheck()
{
	if (((CButton*)GetDlgItem(IDC_RADIO1))->GetCheck() == 1){
		return RADIO_USB;
	}
	else if (((CButton*)GetDlgItem(IDC_RADIO2))->GetCheck() == 1) {
		return RADIO_COM;
	}
	else if (((CButton*)GetDlgItem(IDC_RADIO4))->GetCheck() == 1) {
		return RADIO_NET;
	}
	else {
		return RADIO_USB;
	}
}

void CPOSSDK_PRO_DemoDlg::initUIValue()
{
	// Model List
	if (m_ModelList.size() != 0)
	{
		for each (CString it in m_ModelList)
		{
			((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString(it);
		}
		((CComboBox*)GetDlgItem(IDC_COMBO1))->SetCurSel(0);
	}

	// COM
	CString portNumberList[] = { _T("COM1"), _T("COM2"), _T("COM3"), _T("COM4"), 
		_T("COM5"), _T("COM6"), _T("COM7"), _T("COM8"),
		_T("COM9"), _T("COM10"), _T("COM11"), _T("COM12")};
	for (int i = 0; i < sizeof(portNumberList) / sizeof(CString); i++)
	{
		((CComboBox*)GetDlgItem(IDC_COMBO2))->AddString(portNumberList[i]);
	}
	((CComboBox*)GetDlgItem(IDC_COMBO2))->SetCurSel(0);

	CString baudList[] = { _T("2400"), _T("4800"), _T("9600"), _T("19200"), _T("38400"),
		_T("57600"), _T("115200") };
	for (int i = 0; i < sizeof(baudList) / sizeof(CString); i++)
	{
		((CComboBox*)GetDlgItem(IDC_COMBO3))->AddString(baudList[i]);
	}
	((CComboBox*)GetDlgItem(IDC_COMBO3))->SetCurSel(sizeof(baudList) / sizeof(CString) -1);

	// Button
	((CButton*)GetDlgItem(IDC_BUTTON2))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_BUTTON5))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_BUTTON6))->EnableWindow(FALSE);
}

void CPOSSDK_PRO_DemoDlg::getModelAndIdFromIni()
{
	CString iniPath = _T("./POSSDK_PRO_Demo_Config.ini");
	CString iniModelList;
	CString model;

	const int MAX_SIZE = 1024;
	GetPrivateProfileString(_T("MODEL"), _T("List"), _T(""), iniModelList.GetBuffer(MAX_SIZE), MAX_SIZE, iniPath);
	iniModelList.ReleaseBuffer();

	while (iniModelList.Find(_T(',')) != -1)
	{
		int index = iniModelList.Find(_T(','));
		model = iniModelList.Left(index);
		m_ModelList.push_back(model);
		iniModelList = iniModelList.Right(iniModelList.GetLength() - index - 1);
	}
	if (iniModelList.Compare(_T("")) != 0)
	{
		model = iniModelList;
		m_ModelList.push_back(model);
	}
}

int CPOSSDK_PRO_DemoDlg::CStrToChar(char *dst, CString src)
{
	char *temp = NULL;
#ifdef _UNICODE
	DWORD dwLen = WideCharToMultiByte(CP_UTF8, NULL, src, -1, NULL, NULL, 0, NULL);
	if (dwLen <= 0)
	{
		return 0;
	}
	temp = new char[dwLen];
	memset(temp, 0, dwLen * sizeof(char));
	WideCharToMultiByte(CP_UTF8, NULL, src, -1, temp, dwLen, 0, NULL);

	memcpy(dst, temp, dwLen);
	if (temp)
	{
		delete[] temp;
		temp = NULL;
	}
#else
	memcpy(dst, src, src.GetLength());
#endif // _UNICODE
	return 1;
}

void CPOSSDK_PRO_DemoDlg::OnCbnEditchangeCombo2()
{
	CString tempstr;
	((CComboBox*)GetDlgItem(IDC_COMBO2))->GetWindowText(tempstr);
	if (tempstr.IsEmpty())
	{
		((CComboBox*)GetDlgItem(IDC_COMBO2))->SetCurSel(0);
	}
}

void CPOSSDK_PRO_DemoDlg::OnCbnEditchangeCombo3()
{
	CString tempstr;
	((CComboBox*)GetDlgItem(IDC_COMBO3))->GetWindowText(tempstr);
	if (tempstr.IsEmpty())
	{
		int nCount = ((CComboBox*)GetDlgItem(IDC_COMBO3))->GetCount();
		((CComboBox*)GetDlgItem(IDC_COMBO3))->SetCurSel(nCount - 1);
	}
}

void CPOSSDK_PRO_DemoDlg::OnBnClickedButton1()
{
	CString currentStatus;
	((CButton*)GetDlgItem(IDC_BUTTON1))->GetWindowText(currentStatus);
	if (currentStatus.Compare(_T("Connect Printer")) == 0)
	{
		char model[128] = { 0 };
		char portInfo[128] = { 0 };
		char tempConvert[128] = { 0 };
		CString tempstr;

		/* get Model */
		((CComboBox*)GetDlgItem(IDC_COMBO1))->GetWindowText(tempstr);
		if (tempstr.IsEmpty())
		{
			sprintf(model, "BTP");
		}
		else
		{
			CStrToChar(model, tempstr);
		}

		/* get Port info*/
		int portType = getRadioCheck();
		switch (portType)
		{
		case RADIO_USB:
			// "USBAPI"
			((CComboBox*)GetDlgItem(IDC_COMBO4))->GetWindowText(tempstr);
			if (tempstr.IsEmpty())
			{
				strcpy(portInfo, "USB");
			}
			else
			{
				CStrToChar(portInfo, tempstr);
			}
			break;
		case RADIO_COM:
			// "COM2|115200"
			((CComboBox*)GetDlgItem(IDC_COMBO2))->GetWindowText(tempstr);
			CStrToChar(tempConvert, tempstr);
			strcpy(portInfo, tempConvert);
			strcat(portInfo, "|");
			((CComboBox*)GetDlgItem(IDC_COMBO3))->GetWindowText(tempstr);
			CStrToChar(tempConvert, tempstr);
			strcat(portInfo, tempConvert);
			break;
		case RADIO_NET:
			((CComboBox*)GetDlgItem(IDC_COMBO5))->GetWindowText(tempstr);
			CStrToChar(portInfo, tempstr);
			break;
		default:
			break;
		}

		m_printerHandle = Sample_Open(model, portInfo);
		if (m_printerHandle < 0)
		{
			CString errorStr;
			errorStr.Format(_T("Connect error. [%d]"), m_printerHandle);
			MessageBox(errorStr);
			return;
		}

		((CButton*)GetDlgItem(IDC_BUTTON1))->SetWindowText(_T("Disconnect Printer"));
		((CButton*)GetDlgItem(IDC_BUTTON2))->EnableWindow(TRUE);
		((CButton*)GetDlgItem(IDC_BUTTON5))->EnableWindow(TRUE);
		((CButton*)GetDlgItem(IDC_BUTTON6))->EnableWindow(TRUE);
	}
	else if (currentStatus.Compare(_T("Disconnect Printer")) == 0)
	{
		if (m_printerHandle >= 0)
		{
			Sample_Close(m_printerHandle);
		}
		((CButton*)GetDlgItem(IDC_BUTTON1))->SetWindowText(_T("Connect Printer"));
		((CButton*)GetDlgItem(IDC_BUTTON2))->EnableWindow(FALSE);
		((CButton*)GetDlgItem(IDC_BUTTON5))->EnableWindow(FALSE);
		((CButton*)GetDlgItem(IDC_BUTTON6))->EnableWindow(FALSE);
	}
}

void CPOSSDK_PRO_DemoDlg::OnBnClickedButton2()
{
	char errorStatus[128] = { 0 };
	int nRet = SUCCESS;
	nRet = Sample_Restaurant(m_printerHandle, errorStatus);
	if (nRet != 0)
	{
		CString errorStr;
		errorStr.Format(_T("Print error.\nErrorCode [%d]\nPrinter Status [ %hs ]"), nRet, errorStatus);
		MessageBox(errorStr);
		return;
	}

	nRet = Sample_Restaurant_En(m_printerHandle, errorStatus);
	if (nRet != 0)
	{
		CString errorStr;
		errorStr.Format(_T("Print error.\nErrorCode [%d]\nPrinter Status [ %hs ]"), nRet, errorStatus);
		MessageBox(errorStr);
		return;
	}

	nRet = SampleXML(m_printerHandle);
	if (nRet != 0)
	{
		CString errorStr;
		errorStr.Format(_T("Print error.\nErrorCode [%d]\nPrinter Status [ %hs ]"), nRet, errorStatus);
		MessageBox(errorStr);
		return;
	}

	nRet = SampleXMLPageMode(m_printerHandle);
	if (nRet != 0)
	{
		CString errorStr;
		errorStr.Format(_T("Print error.\nErrorCode [%d]\nPrinter Status [ %hs ]"), nRet, errorStatus);
		MessageBox(errorStr);
		return;
	}
}

void CPOSSDK_PRO_DemoDlg::OnBnClickedButtonEu()
{
	// clear combox4
	((CComboBox*)GetDlgItem(IDC_COMBO4))->ResetContent();

	// enum usb printer
	char deviceList[1024] = { 0 };
	int numb = Sample_EnumDevice(1, deviceList, sizeof(deviceList));
	if (numb <= 0)
	{
		return;
	}

	string strDeviceList(deviceList);
	string strDevice = "";
	while (1)
	{
		int index = strDeviceList.find('@');
		if (index == -1)
		{
			break;
		}
		strDevice = strDeviceList.substr(0, index);
		strDeviceList = strDeviceList.substr(index + 1, strDeviceList.length());

		// add combox4
		CString item;
		item.Format(_T("%hs"), strDevice.c_str());
		((CComboBox*)GetDlgItem(IDC_COMBO4))->AddString(item);
	
		if (strDeviceList.empty())
		{
			break;
		}
	}

	((CComboBox*)GetDlgItem(IDC_COMBO4))->SetCurSel(0);
	
}

void CPOSSDK_PRO_DemoDlg::OnBnClickedButtonEe()
{
	// clear combox5
	((CComboBox*)GetDlgItem(IDC_COMBO5))->ResetContent();

	// enum ethnet printer
	char deviceList[1024] = { 0 };
	int numb = Sample_EnumDevice(2, deviceList, sizeof(deviceList));
	if (numb <= 0)
	{
		return;
	}

	// °´@²ð·Ö
	string strDeviceList(deviceList);
	string strDevice = "";
	while (1)
	{
		int index = strDeviceList.find('@');
		if (index == -1)
		{
			break;
		}
		strDevice = strDeviceList.substr(0, index);
		strDeviceList = strDeviceList.substr(index + 1, strDeviceList.length());

		// add combox5
		CString item;
		item.Format(_T("%hs"), strDevice.c_str());
		((CComboBox*)GetDlgItem(IDC_COMBO5))->AddString(item);

		if (strDeviceList.empty())
		{
			break;
		}
	}

	((CComboBox*)GetDlgItem(IDC_COMBO5))->SetCurSel(0);
}



void CPOSSDK_PRO_DemoDlg::OnBnClickedButtonSupermarket()
{
	char errorStatus[128] = { 0 };
	int nRet = SUCCESS;
	nRet = Sample_Supermarket(m_printerHandle, errorStatus);
	if (nRet != 0)
	{
		CString errorStr;
		errorStr.Format(_T("Print error.\nErrorCode [%d]\nPrinter Status [ %hs ]"), nRet, errorStatus);
		MessageBox(errorStr);
		return;
	}

	nRet = Sample_Supermarket_En(m_printerHandle, errorStatus);
	if (nRet != 0)
	{
		CString errorStr;
		errorStr.Format(_T("Print error.\nErrorCode [%d]\nPrinter Status [ %hs ]"), nRet, errorStatus);
		MessageBox(errorStr);
		return;
	}
}


void CPOSSDK_PRO_DemoDlg::OnBnClickedButtonBankQueue()
{
	char errorStatus[128] = { 0 };
	int nRet = SUCCESS;
	nRet = Sample_BankQueue(m_printerHandle, errorStatus);
	if (nRet != 0)
	{
		CString errorStr;
		errorStr.Format(_T("Print error.\nErrorCode [%d]\nPrinter Status [ %hs ]"), nRet, errorStatus);
		MessageBox(errorStr);
		return;
	}

	nRet = Sample_BankQueue_En(m_printerHandle, errorStatus);
	if (nRet != 0)
	{
		CString errorStr;
		errorStr.Format(_T("Print error.\nErrorCode [%d]\nPrinter Status [ %hs ]"), nRet, errorStatus);
		MessageBox(errorStr);
		return;
	}
}


void CPOSSDK_PRO_DemoDlg::OnBnClickedButtonMovieTicket()
{
	char errorStatus[128] = { 0 };
	int nRet = SUCCESS;
	nRet = Sample_MovieTicket(m_printerHandle, errorStatus);
	if (nRet != 0)
	{
		CString errorStr;
		errorStr.Format(_T("Print error.\nErrorCode [%d]\nPrinter Status [ %hs ]"), nRet, errorStatus);
		MessageBox(errorStr);
		return;
	}

	nRet = Sample_MovieTicket_En(m_printerHandle, errorStatus);
	if (nRet != 0)
	{
		CString errorStr;
		errorStr.Format(_T("Print error.\nErrorCode [%d]\nPrinter Status [ %hs ]"), nRet, errorStatus);
		MessageBox(errorStr);
		return;
	}
}


void CPOSSDK_PRO_DemoDlg::OnBnClickedButtonTrafficTicket()
{
	char errorStatus[128] = { 0 };
	int nRet = SUCCESS;
	nRet = Sample_TrafficTicket(m_printerHandle, errorStatus);
	if (nRet != 0)
	{
		CString errorStr;
		errorStr.Format(_T("Print error.\nErrorCode [%d]\nPrinter Status [ %hs ]"), nRet, errorStatus);
		MessageBox(errorStr);
		return;
	}

	nRet = Sample_TrafficTicket_En(m_printerHandle, errorStatus);
	if (nRet != 0)
	{
		CString errorStr;
		errorStr.Format(_T("Print error.\nErrorCode [%d]\nPrinter Status [ %hs ]"), nRet, errorStatus);
		MessageBox(errorStr);
		return;
	}
}
