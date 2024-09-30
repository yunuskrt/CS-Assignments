
// ykerestecioglu_Kerestecioglu_Yunus_Tan_hw6Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "ykerestecioglu_Kerestecioglu_Yunus_Tan_hw6.h"
#include "ykerestecioglu_Kerestecioglu_Yunus_Tan_hw6Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cykerestecioglu_Kerestecioglu_Yunus_Tan_hw6Dlg dialog



Cykerestecioglu_Kerestecioglu_Yunus_Tan_hw6Dlg::Cykerestecioglu_Kerestecioglu_Yunus_Tan_hw6Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cykerestecioglu_Kerestecioglu_Yunus_Tan_hw6Dlg::IDD, pParent)
	, Radio1(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cykerestecioglu_Kerestecioglu_Yunus_Tan_hw6Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO4, Radio1);
	DDX_Control(pDX, IDC_EDIT2, operand1);
	DDX_Control(pDX, IDC_EDIT1, operand2);
	DDX_Control(pDX, IDC_COMBO1, Combo1);
	DDX_Control(pDX, IDC_CHECK1, checkShift);
	DDX_Control(pDX, IDC_BUTTON1, Button1);
	DDX_Control(pDX, IDC_EDIT3, inputBits);
	DDX_Control(pDX, IDC_LIST1, list);
}

BEGIN_MESSAGE_MAP(Cykerestecioglu_Kerestecioglu_Yunus_Tan_hw6Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Cykerestecioglu_Kerestecioglu_Yunus_Tan_hw6Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CHECK1, &Cykerestecioglu_Kerestecioglu_Yunus_Tan_hw6Dlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_RADIO5, &Cykerestecioglu_Kerestecioglu_Yunus_Tan_hw6Dlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO4, &Cykerestecioglu_Kerestecioglu_Yunus_Tan_hw6Dlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO6, &Cykerestecioglu_Kerestecioglu_Yunus_Tan_hw6Dlg::OnBnClickedRadio6)
END_MESSAGE_MAP()


// Cykerestecioglu_Kerestecioglu_Yunus_Tan_hw6Dlg message handlers

BOOL Cykerestecioglu_Kerestecioglu_Yunus_Tan_hw6Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	Combo1.SetCurSel(0);
	

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Cykerestecioglu_Kerestecioglu_Yunus_Tan_hw6Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Cykerestecioglu_Kerestecioglu_Yunus_Tan_hw6Dlg::OnPaint()
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
HCURSOR Cykerestecioglu_Kerestecioglu_Yunus_Tan_hw6Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


int maxSize = 0;// You have to keep size of the string which have maximum length.
int option = 0;
void Cykerestecioglu_Kerestecioglu_Yunus_Tan_hw6Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	CString result,op1,op2,comboText,bitText,res;

	//get a DC
	CDC *pDC = GetDC(); // This class is necessary to get the length of the string 
	CFont *pOldFont = pDC->SelectObject(GetFont());
	CSize cz; // An object which keeps the length of the string.
	
	
	operand1.GetWindowTextW(op1);
	operand2.GetWindowTextW(op2);

	if ( !(op1.GetLength() > 0) || !(op2.GetLength() > 0) ){
		result = _T("At least 1 operand was not entered");
		list.AddString(result);
	}
	else{
		// Get the num of bits
		inputBits.GetWindowTextW(bitText);
		// Convert operands to unsigned int
		unsigned int unsOp1 = _tcstoul(op1,nullptr,10);
		unsigned int unsOp2 = _tcstoul(op2,nullptr,10);
		// Update op1 and op2 in case of overflow
		op1.Format(_T("%u"), unsOp1);
		op2.Format(_T("%u"), unsOp2);

		if (checkShift.GetCheck() == 1 && !(bitText.GetLength() > 0) ){
			result = _T("Specify how many bits you want to shift");
			list.AddString(result);
		}
		else{ 
			if (checkShift.GetCheck() == 1){
				// Convert bits_to_shift to integer
				int intBit = _ttoi(bitText);

				// Get the index of the list that was selected
				int selectedIdx = Combo1.GetCurSel();
				// Get string that is stored at this index and store it
				Combo1.GetLBText(selectedIdx, comboText);
				
				if (comboText == "Left"){ // shifting operands to left
					unsOp1 = unsOp1 << intBit;
					unsOp2 = unsOp2 << intBit;
				}
				else{ // shifting operands to right
					unsOp1 = unsOp1 >> intBit;
					unsOp2 = unsOp2 >> intBit;
				}

				// updating op1 and op2 to new values after shifting
				op1.Format(_T("%u"), unsOp1);
				op2.Format(_T("%u"), unsOp2);

			}

			if (option == 0){ // and
				res.Format(_T("%u"), unsOp1 & unsOp2);
				result = op1 + _T(" AND ") + op2 + _T(" = ") + res; 
				list.AddString(result);
			}

			else if (option == 1){ // or
				res.Format(_T("%u"), unsOp1 | unsOp2);
				result = op1 + _T(" OR ") + op2 + _T(" = ") + res;
				list.AddString(result);
			}

			else if (option == 2){ // xor
				res.Format(_T("%u"), unsOp1 ^ unsOp2);
				result = op1 + _T(" XOR ") + op2 + _T(" = ") + res;
				list.AddString(result);
			}

		}
		
	}
			
	
	cz = pDC->GetTextExtent(result);
	if(cz.cx > maxSize)
		maxSize = cz.cx;
	list.SetHorizontalExtent(maxSize);
}


void Cykerestecioglu_Kerestecioglu_Yunus_Tan_hw6Dlg::OnBnClickedCheck1()
{
	// TODO: Add your control notification handler code here
	if (checkShift.GetCheck()){
		Combo1.EnableWindow(TRUE);
		inputBits.EnableWindow(TRUE);
	}
	else{
		Combo1.EnableWindow(FALSE);
		inputBits.EnableWindow(FALSE);
	}
}

void Cykerestecioglu_Kerestecioglu_Yunus_Tan_hw6Dlg::OnBnClickedRadio4()
{
	// TODO: Add your control notification handler code here
	option = 0;
	UpdateData(TRUE);
}


void Cykerestecioglu_Kerestecioglu_Yunus_Tan_hw6Dlg::OnBnClickedRadio5()
{
	// TODO: Add your control notification handler code here
	option = 1;
	UpdateData(TRUE);
}


void Cykerestecioglu_Kerestecioglu_Yunus_Tan_hw6Dlg::OnBnClickedRadio6()
{
	// TODO: Add your control notification handler code here
	option = 2;
	UpdateData(TRUE);
}
