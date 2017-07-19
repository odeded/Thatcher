// Thatcher.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <Windows.h>
#include "Types.h"
#include "WinHelper.h"


int main()
{


	smartHandle hhh = makeSmartHandle( 
		CreateFile(L"vsvds",               // file name 
		GENERIC_READ,          // open for reading 
		0,                     // do not share 
		NULL,                  // default security 
		OPEN_EXISTING,         // existing file only 
		FILE_ATTRIBUTE_NORMAL, // normal file 
		NULL)
		);
		
	WinHelper::GetProcessByName(L"explorer.exe");
    return 0;
}

