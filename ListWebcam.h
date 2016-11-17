#pragma once

#include <windows.h>
#include <dshow.h>
#include <comutil.h>
#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <QStringListModel>

#pragma comment(lib, "strmiids")
#pragma comment(lib, "comsuppwd")
#pragma comment(lib, "comsupp")

class ListWebcam
{
public:
	ListWebcam();
	~ListWebcam();

public:
	std::vector<std::string> List_of_Webcam_std;
	QStringList List_of_Webcam_QT;

private:
	HRESULT EnumerateDevices(REFGUID category, IEnumMoniker **ppEnum);

	void DisplayDeviceInformation(IEnumMoniker *pEnum);

};

