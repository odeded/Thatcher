#pragma once
#include "stdafx.h"
#include <thread>
#include <string>

using namespace std;

class CmdFileReader
{
private:
	thread mThread;
	wstring mPath;

public:
	CmdFileReader();
	virtual ~CmdFileReader();

	void start();

	void mainLoop();
};

