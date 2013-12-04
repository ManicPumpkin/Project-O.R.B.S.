// WorldGeneratorTestingApplication.cpp : Defines the entry point for the console application.
//

#include "..\inc\stdafx.h"

#include "..\..\WorldGenerator\inc\stdafx.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
  cout << "whooot whooot\t Testing application started";

  getchar();

  WorldGenerator *wg = WorldGenerator::getInstance();

  /*ParameterContainer universe_parameters = wg->get_world_parameters();
  universe_parameters.universe_size_ = GlobalEnums::UniverseSize::kHuge;
  wg->set_world_parameters(universe_parameters);*/

  wg->doTheGodJob();

  cout << "testing application finished!";

  getchar();

  delete wg;

  flushall;
  getchar();

	return 0;
}

