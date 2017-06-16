#include "stdafx.h"
#include "Types.h"

std::unique_ptr<HANDLE, smartHandleDeleter> makeSmartHandle(HANDLE h)
{
	return smartHandle((HANDLE*)h);
}
