#pragma once

#include <memory>
#include <Windows.h>

class smartHandleDeleter
{
public:
	void operator()(HANDLE* h)
	{
		if (h && h != INVALID_HANDLE_VALUE)
		{
			CloseHandle(h);
		}
	}
};

using smartHandle = std::unique_ptr<HANDLE,smartHandleDeleter>;

std::unique_ptr<HANDLE, smartHandleDeleter> makeSmartHandle(HANDLE h);
