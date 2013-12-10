// WorldGeneratorTestingApplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include "..\..\WorldGenerator\inc\WorldGenerator.h"
#include "..\..\Log\inc\Log.h"


using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
  Log::getInstance()->set_file_path_and_name(string("log"), string("log.html"));
  Log::getInstance()->debug_mode_ = true;
  LOG_DEBUG("WorldGeneratorTestingApplication started");
  LOG_DEBUG("Log system initialized succesfully");
  getchar();

  WorldGenerator *wg = WorldGenerator::getInstance();
  wg->doTheGodJob();

  LOG_DEBUG("WorldGeneratorTestingApplication finished");
  getchar();

  delete wg;
  delete Log::getInstance();
  getchar();

	return 0;
}

