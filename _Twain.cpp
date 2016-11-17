#include "_Twain.h"

LRESULT CALLBACK TwainWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK TwainWndProcA(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

CTwain::CTwain()
{
	hWnd = NULL;
	hTwainDLL = NULL;
	hInstance = NULL;
	hDSMProc = NULL;
	twOpenDS = false;
	twOpenDSM = false;
	twEnabled = false;
	twTransfering = false;
}

CTwain::~CTwain()
{
	twRelease();
}

TW_UINT16 CTwain::twPurgeTransfer(){
	TW_PENDINGXFERS twXfers;
	TW_UINT16 rc;
	if (hTwainDLL == NULL || hDSMProc == NULL || twOpenDS == false || twOpenDSM == false || twEnabled == false)
		return TWRC_SUCCESS;
	rc = (*hDSMProc)(&twAppID, &twSource, DG_CONTROL, DAT_PENDINGXFERS, MSG_ENDXFER, (TW_MEMREF)&twXfers);
	rc = (*hDSMProc)(&twAppID, &twSource, DG_CONTROL, DAT_PENDINGXFERS, MSG_RESET, (TW_MEMREF)&twXfers);
	return rc;
}

TW_UINT16 CTwain::twDisable(){
	TW_USERINTERFACE twUI;
	TW_UINT16 rc;
	rc = twPurgeTransfer();
	if (hTwainDLL == NULL || hDSMProc == NULL || twOpenDS == false || twOpenDSM == false){
		twEnabled = false;
		return TWRC_SUCCESS;
	}
	if (twEnabled == true){
		rc = (*hDSMProc)(&twAppID, &twSource, DG_CONTROL, DAT_USERINTERFACE, MSG_DISABLEDS, &twUI);
		twEnabled = false;
	}
	return rc;
}

TW_UINT16 CTwain::twCloseSource(){
	TW_UINT16 rc;
	rc = twDisable();
	if (hTwainDLL == NULL || hDSMProc == NULL || twOpenDSM == false){
		twOpenDS = false;
		return TWRC_SUCCESS;
	}
	if (twOpenDS = true){
		rc = (*hDSMProc)(&twAppID, NULL, DG_CONTROL, DAT_IDENTITY, MSG_CLOSEDS, &twSource);
		twSource.Id = 0;
		twOpenDS = false;
	}
	return rc;
}

TW_UINT16 CTwain::twCloseDSM(){
	TW_UINT16 rc = twCloseSource();
	if (hTwainDLL == NULL || hDSMProc == NULL){
		twOpenDSM = false;
		return TWRC_SUCCESS;
	}
	if (twOpenDSM = true){
		rc = (*hDSMProc)(&twAppID, NULL, DG_CONTROL, DAT_PARENT, MSG_CLOSEDS, &hWnd);
		twOpenDSM = false;
	}
	return rc;
}

TW_UINT16 CTwain::twRelease(){
	TW_UINT16 rc = twCloseDSM();
	if (hTwainDLL != NULL) FreeLibrary(hTwainDLL);
	hTwainDLL = NULL;
	hDSMProc = NULL;
	twAppID.Id = 0;
	return rc;
}


LRESULT CALLBACK TwainWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
	CTwain ctwain;
	TW_EVENT twEvent;
	TW_UINT16 rc = TWRC_NOTDSEVENT;
	if (ctwain.twEnabled){
		twEvent.pEvent = (TW_MEMREF)&uMsg;
		twEvent.TWMessage = MSG_NULL;
		rc = (*ctwain.hDSMProc)(&ctwain.twAppID, &ctwain.twSource,
			DG_CONTROL, DAT_EVENT, MSG_PROCESSEVENT, (TW_MEMREF)&twEvent);
		switch (twEvent.TWMessage){
		case MSG_XFERREADY:
			return 0;
			break;
		case MSG_CLOSEDSREQ:
			ctwain.twTransfering = false;
			ctwain.twCloseSource();
			return 0;
			break;
		case MSG_CLOSEDSOK:
			ctwain.twTransfering = false;
			ctwain.twCloseSource();
			return 0;
			break;
		case MSG_NULL:
			break;
		}
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

LRESULT CALLBACK TwainWndProcA(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
	CTwain ctwain;
	TW_EVENT twEvent;
	TW_UINT16 rc = TWRC_NOTDSEVENT;
	if (ctwain.twEnabled){
		twEvent.pEvent = (TW_MEMREF)&uMsg;
		twEvent.TWMessage = MSG_NULL;
		rc = (*ctwain.hDSMProc)(&ctwain.twAppID, &ctwain.twSource,
			DG_CONTROL, DAT_EVENT, MSG_PROCESSEVENT, (TW_MEMREF)&twEvent);
		switch (twEvent.TWMessage){
		case MSG_XFERREADY:
			return 0;
			break;
		case MSG_CLOSEDSREQ:
			ctwain.twTransfering = false;
			ctwain.twCloseSource();
			return 0;
			break;
		case MSG_CLOSEDSOK:
			ctwain.twTransfering = false;
			ctwain.twCloseSource();
			return 0;
			break;
		case MSG_NULL:
			break;
		}
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}


TW_UINT16 CTwain::twMakeInstance(){
	WNDCLASS wc;
	if (hInstance == NULL){
		hInstance = (HINSTANCE)GetModuleHandle(NULL);
		if (hInstance == NULL) return TWRC_FAILURE;
		wc.style = 0;
		wc.lpfnWndProc = TwainWndProc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = hInstance;
		wc.hIcon = NULL;
		wc.hCursor = NULL;
		wc.hbrBackground = NULL;
		wc.lpszMenuName = NULL;
		wc.lpszClassName = "TWAIN";
		if (!RegisterClass(&wc)) return TWRC_FAILURE;
		if (hWnd == NULL){
			hWnd = CreateWindowA("TWAIN", "TWAIN", WS_OVERLAPPEDWINDOW,
				CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
				NULL, NULL, hInstance, NULL);
			if (!hWnd) return TWRC_FAILURE;
		}
		ShowWindow(hWnd, SW_HIDE);
		UpdateWindow(hWnd);
	}
}

TW_UINT16 CTwain::twMakeInstanceA(){
	WNDCLASS wc;
	if (hInstance == NULL){
		hInstance = (HINSTANCE)GetModuleHandle(NULL);
		if (hInstance == NULL) return TWRC_FAILURE;
		wc.style = 0;
		wc.lpfnWndProc = TwainWndProcA;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = hInstance;
		wc.hIcon = NULL;
		wc.hCursor = NULL;
		wc.hbrBackground = NULL;
		wc.lpszMenuName = NULL;
		wc.lpszClassName = "TWAINA";
		if (!RegisterClass(&wc)) return TWRC_FAILURE;
		if (hWnd == NULL){
			hWnd = CreateWindowA("TWAINA", "TWAINA", WS_OVERLAPPEDWINDOW,
				CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
				NULL, NULL, hInstance, NULL);
			if (!hWnd) return TWRC_FAILURE;
		}
		ShowWindow(hWnd, SW_HIDE);
		UpdateWindow(hWnd);
	}
}


TW_UINT16 CTwain::twInitialize(int Id){
	TW_UINT16 rc = twRelease();
	hTwainDLL = LoadLibrary("twain_32.dll");
	if (hTwainDLL == NULL) return TWRC_FAILURE;
	// Find DSM entry
	hDSMProc = (DSMENTRYPROC)GetProcAddress(hTwainDLL, MAKEINTRESOURCEA(1));
	if (hDSMProc == NULL) return TWRC_FAILURE;
	// Fill in AppId information
	twAppID.Id = 0;
	twAppID.Version.MajorNum = 1;
	twAppID.Version.MinorNum = 4;
	twAppID.Version.Language = TWLG_USA;
	twAppID.Version.Country = TWCY_KOREA;
	strcpy_s(twAppID.Version.Info, "v1.0");
	twAppID.ProtocolMajor = TWON_PROTOCOLMAJOR;
	twAppID.ProtocolMinor = TWON_PROTOCOLMINOR;
	twAppID.SupportedGroups = DG_IMAGE | DG_CONTROL;
	strcpy_s(twAppID.Manufacturer, "Kang Yeon Kim");
	strcpy_s(twAppID.ProductFamily, "GoodBody Project");
	strcpy_s(twAppID.ProductName, "Foot Measurement System");

	if (Id)	twMakeInstanceA();
	else twMakeInstance();

	// Send AppID Query
	rc = (*hDSMProc)(&twAppID, NULL, DG_CONTROL, DAT_PARENT, MSG_OPENDSM, (TW_MEMREF)&hWnd);
	if (rc != TWRC_SUCCESS) return rc;
	twOpenDSM = true;
	return rc;
}

TW_UINT16 CTwain::twListDevices(){
	TW_IDENTITY twTemp;
	TW_UINT16 rc;
	twList.clear();
	twTemp.Id = 0;
	twTemp.ProductName[0] = '\0';
	rc = (*hDSMProc)(&twAppID, NULL, DG_CONTROL, DAT_IDENTITY, MSG_GETFIRST, &twTemp);
	if (rc == TWRC_ENDOFLIST || twTemp.Id == 0){
		twRelease();
		return TWRC_FAILURE;
	}

	while (rc != TWRC_ENDOFLIST){
		twList.push_back(twTemp.ProductName);
		// Grab next one
		twTemp.Id = 0;
		twTemp.ProductName[0] = '\0';
		rc = (*hDSMProc)(&twAppID, NULL, DG_CONTROL, DAT_IDENTITY, MSG_GETNEXT, &twTemp);
	}
}

TW_UINT16 CTwain::twSetCapability(TW_UINT16 cap, TW_UINT16 type, TW_UINT16 value){
	TW_CAPABILITY twCap;
	pTW_ONEVALUE pVal;
	twCap.hContainer = GlobalAlloc(GHND, sizeof(TW_ONEVALUE));
	pVal = (pTW_ONEVALUE)GlobalLock(twCap.hContainer);
	twCap.Cap = cap;
	twCap.ConType = TWON_ONEVALUE;
	pVal->ItemType = type;
	pVal->Item = value;
	TW_UINT16 rc = (*hDSMProc)(&twAppID, &twSource, DG_CONTROL, DAT_CAPABILITY, MSG_SET, (TW_MEMREF)&twCap);
	GlobalUnlock(twCap.hContainer);
	GlobalFree((HANDLE)twCap.hContainer);
	return rc;
}

TW_UINT16 CTwain::twGetCapability(TW_UINT16 cap, pTW_CAPABILITY ptwCap){
	ptwCap->Cap = cap;
	ptwCap->ConType = TWON_DONTCARE16;
	ptwCap->hContainer = NULL;
	TW_UINT16 rc = (*hDSMProc)(&twAppID, &twSource, DG_CONTROL, DAT_CAPABILITY, MSG_GET, (TW_MEMREF)&ptwCap);
	return rc;
}

TW_UINT16 CTwain::twSelectDevice(int index){
	//	TW_CAPABILITY twCap;
	TW_UINT16 rc;
	//	pTW_ONEVALUE pval;
	int count = 0;
	// If someone has already been selected, deselect it first
	if (twOpenDS)
		twCloseSource();

	twSource.Id = 0;
	twSource.ProductName[0] = '\0';

	rc = (*hDSMProc)(&twAppID, NULL, DG_CONTROL, DAT_IDENTITY, MSG_GETFIRST, &twSource);
	if (rc == TWRC_ENDOFLIST || twSource.Id == 0){
		twRelease();
		return TWRC_FAILURE;
	}

	while (rc != TWRC_ENDOFLIST){
		// We found the device
		if (count == index){
			// Attempt to establish a connection
			rc = (*hDSMProc)(&twAppID, NULL, DG_CONTROL, DAT_IDENTITY, MSG_OPENDS, &twSource);

			if (rc != TWRC_SUCCESS) return rc;

			twOpenDS = TRUE;

			// Negotiate capabilities
			//twCap.Cap = CAP_XFERCOUNT;
			//twCap.ConType = TWON_ONEVALUE;
			//twCap.hContainer = GlobalAlloc(GHND, sizeof(TW_ONEVALUE));
			//pval = (pTW_ONEVALUE)GlobalLock(twCap.hContainer);
			//pval->ItemType = TWTY_INT16;
			//pval->Item = 1;
			//GlobalUnlock(twCap.hContainer);
			//rc = (*hDSMProc)(&twAppID, &twSource, DG_CONTROL, DAT_CAPABILITY, MSG_SET, (TW_MEMREF)&twCap);
			//GlobalFree((HANDLE)twCap.hContainer);

			//		rc = twSetCapability(CAP_XFERCOUNT, TWTY_INT16, 1);

			return rc;
		}
		count++;
		// Grab the next one
		twSource.Id = 0;
		twSource.ProductName[0] = '\0';
		rc = (*hDSMProc)(&twAppID, NULL, DG_CONTROL, DAT_IDENTITY, MSG_GETNEXT, &twSource);
	}
	twSource.Id = 0;
	return TWRC_FAILURE;
}

TW_UINT16 CTwain::twScan(const char *fileName){
	TW_USERINTERFACE twUI;
	TW_IMAGEINFO info;
	TW_UINT16 rc;
	HANDLE bitmap;
	MSG msg;
	FILE *f;
	BITMAPFILEHEADER hdr;
	LPBITMAPINFOHEADER lpbi;

	if (twEnabled) twDisable();

	if (!twOpenDS)	return TWRC_FAILURE;

	twUI.ShowUI = FALSE;
	twUI.ModalUI = TRUE;
	twUI.hParent = (TW_HANDLE)hWnd;

	twTransfering = TRUE;
	twEnabled = TRUE;

	// show UI scanning
	rc = (*hDSMProc)(&twAppID, &twSource, DG_CONTROL, DAT_USERINTERFACE, MSG_ENABLEDS, &twUI);

	GetMessage(&msg, NULL, 0, 0);
	TranslateMessage(&msg);
	DispatchMessage(&msg);

	f = fopen(fileName, "wb");
	if (f == NULL){
		twDisable();
		return TWRC_FAILURE;
	}

	rc = (*hDSMProc)(&twAppID, &twSource, DG_IMAGE, DAT_IMAGEINFO, MSG_GET, (TW_MEMREF)&info);
	if (rc != TWRC_SUCCESS){
		twDisable();
		return TWRC_FAILURE;
	}

	// We ready to get the image
	bitmap = NULL;
	rc = (*hDSMProc)(&twAppID, &twSource, DG_IMAGE, DAT_IMAGENATIVEXFER, MSG_GET, (TW_MEMREF)&bitmap);
	if (rc != TWRC_XFERDONE){
		twDisable();
		return TWRC_FAILURE;
	}

	// We got the image
	lpbi = (LPBITMAPINFOHEADER)GlobalLock(bitmap);
	hdr.bfType = ((WORD)('M' << 8 | 'B'));  // is always "BM"
	hdr.bfSize = GlobalSize(bitmap) + sizeof(hdr);
	hdr.bfReserved1 = 0;
	hdr.bfReserved2 = 0;

	// Calculate number of colors, size of color table, offset to the actual bits
	hdr.bfOffBits = (DWORD)(sizeof(hdr)+(GlobalSize(bitmap) - (lpbi->biWidth*lpbi->biHeight*lpbi->biBitCount / 8)));

	fwrite(&hdr, sizeof(hdr), 1, f);
	fwrite(lpbi, GlobalSize(bitmap), 1, f);
	fclose(f);
	// free the bitmap
	GlobalFree(bitmap);
	twTransfering = FALSE;
	// Kill all other transfers
	twDisable();
	return TWRC_SUCCESS;
}
