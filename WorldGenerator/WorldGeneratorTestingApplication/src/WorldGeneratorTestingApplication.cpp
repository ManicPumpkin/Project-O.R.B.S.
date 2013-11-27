// WorldGeneratorTestingApplication.cpp : Defines the entry point for the console application.
//

#include "..\inc\stdafx.h"

#include "..\..\WorldGenerator\inc\stdafx.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
  cout << "whooot whooot";

  getchar();

  WorldGenerator *wg = WorldGenerator::getInstance();

  ParameterContainer universe_parameters = wg->get_world_parameters();
  universe_parameters.universe_size_ = GlobalEnums::UniverseSize::kHuge;
  wg->set_world_parameters(universe_parameters);

  wg->doTheGodJob();

  cout << "finished!";

  getchar();

	return 0;
}

