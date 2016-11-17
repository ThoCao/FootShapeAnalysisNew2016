#pragma once

#include <Windows.h>
#include <vector>
#include "twain.h"

using namespace std;

class CTwain
{
public:
	CTwain();
	~CTwain();

	TW_UINT16 twCloseDSM();
	TW_UINT16 twCloseSource();
	TW_UINT16 twDisable();
	TW_UINT16 twPurgeTransfer();
	TW_UINT16 twRelease();
	TW_UINT16 twInitialize(int Id);
	TW_UINT16 twMakeInstance();
	TW_UINT16 twMakeInstanceA();
	TW_UINT16 twListDevices();
	TW_UINT16 twSelectDevice(int index);
	TW_UINT16 twScan(const char* fileName);
	TW_UINT16 twSetCapability(TW_UINT16 capability, TW_UINT16 type, TW_UINT16 value);
	TW_UINT16 twGetCapability(TW_UINT16 capability, pTW_CAPABILITY ptwCap);

public:
	HWND hWnd;
	HINSTANCE hTwainDLL;
	HINSTANCE hInstance;
	DSMENTRYPROC	hDSMProc;
	TW_IDENTITY	twAppID;
	TW_IDENTITY	twSource;
	bool twOpenDS;
	bool twOpenDSM;
	bool twEnabled;
	bool twTransfering;
	vector<string> twList;
};

