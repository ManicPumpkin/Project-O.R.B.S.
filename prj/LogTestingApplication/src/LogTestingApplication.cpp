// LogTestingApplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include "..\..\Log\inc\Log.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
  cout << "Log Testing Application started" << endl;

  //Log *log = new Log(string("log\\\\\\\\"), string("test.html"));
  Log *log = Log::getInstance();
  cout << "writing debug message (shouldn't work) " << LOG_DEBUG("this debug message shouldn't be here") << endl;
  log->set_file_path_and_name(string("log\\\\\\\\\\\\\\"), string("test.html"));

  cout << "writing debug message " << log->LOG_DEBUG("this debug message shouldn't be here") << endl;
  cout << "writing info message " << log->LOG_INFO("info message") << endl;
  cout << "writing warning " << log->LOG_WARNING("warning") << endl;
  cout << "writing error message " << log->LOG_ERROR("error", "1") << endl;

  log->debug_mode_ = true;
  cout << "writing debug message " << log->LOG_DEBUG("this should be the first debug message in this file") << endl;
  log->debug_mode_ = false;
  cout << "writing debug message " << log->LOG_DEBUG("this debug message shouldn't be here") << endl;
  log->debug_mode_ = true;

  cout << "writing debug message " << LOG_DEBUG("this should be the last debug message in this file") << endl;
  cout << "writing info message " << LOG_INFO("info message") << endl;
  cout << "writing warning " << LOG_WARNING("warning") << endl;
  cout << "writing error message " << LOG_ERROR("error", "1") << endl;  
  
  getchar();
  
  delete log;

	return 0;
}

