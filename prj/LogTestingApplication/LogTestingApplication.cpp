// LogTestingApplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include "Log.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
  cout << "Log Testing Application started" << endl;

  Log *log = new Log(string("log\\\\\\\\"), string("test.log"));

  log->LOG_DEBUG("debug message");
  log->LOG_INFO("info message");
  log->LOG_WARNING("warning");
  log->LOG_ERROR("error", "1");


  getchar();
  
  delete log;

	return 0;
}

