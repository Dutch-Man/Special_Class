
// CvvImage_Test.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCvvImage_TestApp: 
// �йش����ʵ�֣������ CvvImage_Test.cpp
//

class CCvvImage_TestApp : public CWinApp
{
public:
	CCvvImage_TestApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCvvImage_TestApp theApp;