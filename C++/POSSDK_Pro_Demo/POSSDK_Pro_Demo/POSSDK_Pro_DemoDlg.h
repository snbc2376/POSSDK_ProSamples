
// POSSDK_PRO_DemoDlg.h : header file
//

#pragma once
#include <vector>
using namespace std;

const int RADIO_USB = 0;
const int RADIO_COM = 1;
const int RADIO_NET = 2;

// CPOSSDK_PRO_DemoDlg dialog
class CPOSSDK_PRO_DemoDlg : public CDialogEx
{
// Construction
public:
	CPOSSDK_PRO_DemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_POSSDK_PRO_DEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	void updateUIByRadio();
	int getRadioCheck();
	void initUIValue();
	void getModelAndIdFromIni();
	int CStrToChar(char *dst, CString src);

private:
	vector<CString> m_ModelList;
	int m_printerHandle;

public:
	afx_msg void OnBnClickedRadio1();//update ratio button
	afx_msg void OnBnClickedRadio2();//update ratio button
	afx_msg void OnBnClickedRadio4();//update ratio button
	afx_msg void OnBnClickedButton1();//Connect the printer
	afx_msg void OnBnClickedButton2();//Dining ticket sample
	afx_msg void OnCbnEditchangeCombo2();
	afx_msg void OnCbnEditchangeCombo3();
	afx_msg void OnBnClickedButtonEu();//Enumerate printer list
	afx_msg void OnBnClickedButtonEe();//Enumerate printer list
	afx_msg void OnBnClickedButton5();//Barcode print sample
	afx_msg void OnBnClickedButton6();//Image print sample
};
