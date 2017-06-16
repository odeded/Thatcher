#pragma once
#include <Windows.h>
#include <string>
class WinHelper
{
public:
	static BOOL GetProcessByName(std::wstring processName);

	WinHelper();
	~WinHelper();
};

