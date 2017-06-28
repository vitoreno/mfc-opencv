
// ChildView.h : interface of the CChildView class
//


#pragma once


// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

private:
	CStatic staticWnd;
public:
	afx_msg void OnDestroy();
protected:
	afx_msg LRESULT OnShowimage(WPARAM wParam, LPARAM lParam);
private:
	params ChildViewParams;
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

