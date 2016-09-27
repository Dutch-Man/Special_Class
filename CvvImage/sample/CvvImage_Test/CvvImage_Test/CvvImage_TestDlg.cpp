
// CvvImage_TestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CvvImage_Test.h"
#include "CvvImage_TestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CCvvImage_TestDlg �Ի���



CCvvImage_TestDlg::CCvvImage_TestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCvvImage_TestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCvvImage_TestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCvvImage_TestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_TEST, &CCvvImage_TestDlg::OnBnClickedTest)
END_MESSAGE_MAP()


// CCvvImage_TestDlg ��Ϣ�������

BOOL CCvvImage_TestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CCvvImage_TestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCvvImage_TestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCvvImage_TestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
//��ͼƬ��������ı�
void My_putText(Mat& img, const string& text, int fontFace, double fontScale, Scalar color, int thickness, int lineType)
{
	Size text_size = getTextSize(text, fontFace, fontScale, thickness, NULL);
	//printf("width = %d", text_size.width);
	putText(img, text, Point((img.cols - text_size.width) / 2, (img.rows + text_size.height) / 2), fontFace, fontScale, color, thickness);  //��ʾ����

}


void CCvvImage_TestDlg::OnBnClickedTest()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������CvvImage Test
	Mat img(200, 200, CV_8UC3, CV_RGB(120, 120, 120));
	My_putText(img, "Test", CV_FONT_HERSHEY_COMPLEX, 1.0, CV_RGB(255, 255, 255), 1,1);  //��ʾ����
	Draw(IDC_IMG, img);
}

void CCvvImage_TestDlg::Draw(int ID, Mat img)
{
	HDC hdc;
	CDC *pCDC;
	CRect rect;
	pCDC = GetDlgItem(ID)->GetDC();//����ID��ô���ָ���ٻ�ȡ��ô��ڹ�����������ָ��
	hdc = pCDC->GetSafeHdc();
	GetDlgItem(ID)->GetClientRect(&rect);
	IplImage src = img; // ����IplImageָ�����src
	CvvImage cimg;
	cimg.CopyOf(&src, src.nChannels);
	cimg.DrawToHDC(hdc, &rect);
}