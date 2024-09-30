
// ykerestecioglu_Kerestecioglu_Yunus_Tan_hw6Dlg.h : header file
//

#pragma once
#include "afxwin.h"


// Cykerestecioglu_Kerestecioglu_Yunus_Tan_hw6Dlg dialog
class Cykerestecioglu_Kerestecioglu_Yunus_Tan_hw6Dlg : public CDialogEx
{
// Construction
public:
	Cykerestecioglu_Kerestecioglu_Yunus_Tan_hw6Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_YKERESTECIOGLU_KERESTECIOGLU_YUNUS_TAN_HW6_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnEnChangeEdit2();
	int Radio1;
	CEdit operand1;
	CEdit operand2;
	CComboBox Combo1;
	CButton checkShift;
	CButton Button1;
	CEdit inputBits;
	CListBox list;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio6();
};
