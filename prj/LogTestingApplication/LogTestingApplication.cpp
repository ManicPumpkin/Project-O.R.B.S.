// LogTestingApplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include "Log.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
  cout << "Log Testing Application started" << endl;

  InitializeLog();

  LOG_DEBUG("test");

  getchar();
  
  StopLog();

	return 0;
}

