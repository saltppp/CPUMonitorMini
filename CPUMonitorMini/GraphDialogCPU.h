/**
 *----------------------------------------------------------------------------
 *
 * @file	$Id: GraphDialogCPU.h 118 2008-05-11 11:26:18Z Shiono $
 * @brief	CGraphDialog を継承した CPU 情報を取得するクラス
 *			CPU 情報と Memory 情報を返す
 *
 * @author  Salt
 *
 *----------------------------------------------------------------------------
 */

#pragma once

#include "GraphDialog.h"

class CGraphDialogCPU :	public CGraphDialog {

private:
	int m_nMinFreeMemory;	// in %
	int m_nMaxFreeMemory;	// in %

	DWORD m_dwTickPrev;
	DWORD m_dwIdlePrev;


protected:
	// message handlers
	virtual BOOL GetData(int &nBar, int &nReserved, BOOL bLine, int &nLine);		// have to return 0..100 for nBar and nLine
	virtual BOOL OnLButtonDown(HWND hWnd, POINT &point);


public:
	CGraphDialogCPU(void);
	virtual ~CGraphDialogCPU(void);

	// for user settings
	void SetMinFreeMemory(int n) { m_nMinFreeMemory = n; }
	void SetMaxFreeMemory(int n) { m_nMaxFreeMemory = n; }
	void NormalizeUserSettings(void);
};
