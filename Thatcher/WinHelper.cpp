#include "stdafx.h"
#include <Windows.h>
#include <tlhelp32.h>
#include <exception>
#include <memory>
#include "Types.h"
#include "WinHelper.h"



WinHelper::WinHelper()
{
}


WinHelper::~WinHelper()
{
}

BOOL WinHelper::GetProcessByName(std::wstring processName)
{

	PROCESSENTRY32 pe32;

	// Take a snapshot of all processes in the system.
	smartHandle hProcessSnap = makeSmartHandle(CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0));
	if (hProcessSnap.get() == INVALID_HANDLE_VALUE)
	{
		throw std::exception("CreateToolhelp32Snapshot (of processes)");
		return(FALSE);
	}

	// Set the size of the structure before using it.
	pe32.dwSize = sizeof(PROCESSENTRY32);

	// Retrieve information about the first process,
	// and exit if unsuccessful
	if (!Process32First(*hProcessSnap, &pe32))
	{
		throw std::exception("Process32First"); // show cause of failure
		CloseHandle(*hProcessSnap);          // clean the snapshot object
		return(FALSE);
	}

	// Now walk the snapshot of processes, and
	// display information about each process in turn
	do
	{
		if (processName.compare(pe32.szExeFile) == 0)
		{
			return pe32.th32ProcessID;
		}
	} while (Process32Next(*hProcessSnap, &pe32));

	return 0;
}
