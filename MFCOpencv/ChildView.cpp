
// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "MFCOpencv.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_MESSAGE(WM_SHOWIMAGE, &CChildView::OnShowimage)
	ON_WM_TIMER()
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;
	
	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	ChildViewParams.winName = "Main Window";
	ChildViewParams.winSize.height = 250;
	ChildViewParams.winSize.width = 1000;

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	// Do not call CWnd::OnPaint() for painting messages
}

int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	CRect MainRect;
	AfxGetMainWnd()->GetClientRect(&MainRect);
	
	staticWnd.Create(ChildViewParams.winName, WS_CHILD | WS_VISIBLE | SS_BITMAP, MainRect, this);
	
	cv::namedWindow(ChildViewParams.winName.GetBuffer());
	HWND hWnd = (HWND)cvGetWindowHandle(ChildViewParams.winName);
	HWND hParent = ::GetParent(hWnd);
	::SetParent(hWnd, staticWnd.m_hWnd);
	::ShowWindow(hParent, SW_HIDE);

	SetTimer(1, 500, NULL);

	return 0;
}


void CChildView::OnDestroy()
{
	CWnd::OnDestroy();
	staticWnd.DestroyWindow();
}


afx_msg LRESULT CChildView::OnShowimage(WPARAM wParam, LPARAM lParam)
{
	CString t = CTime::GetCurrentTime().Format("%H:%M:%S");
	cv::Mat im(ChildViewParams.winSize, CV_8UC1);
	im.setTo(cv::Scalar(255));
	cv::putText(im, t.GetBuffer(), cv::Point(50, 50), CV_FONT_HERSHEY_PLAIN, 1.0, cv::Scalar(0));
	cv::imshow(ChildViewParams.winName.GetBuffer(), im);
	return 0;
}

void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if (nIDEvent == 1)
		SendMessage(WM_SHOWIMAGE);
	else
		CWnd::OnTimer(nIDEvent);
}
