
// SelectFolderDir.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSelectFolderDirApp: 
// �йش����ʵ�֣������ SelectFolderDir.cpp
//

class CSelectFolderDirApp : public CWinApp
{
public:
	CSelectFolderDirApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSelectFolderDirApp theApp;