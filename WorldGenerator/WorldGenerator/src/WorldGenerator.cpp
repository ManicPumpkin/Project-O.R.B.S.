// WorldGenerator.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
//#include "WorldGenerator.h"
//#include "Universe.h"
//#include "ParameterContainer.h"


// This is an example of an exported variable
WORLDGENERATOR_API int nWorldGenerator=0;

// This is an example of an exported function.
WORLDGENERATOR_API int fnWorldGenerator(void)
{
	return 42;
}

WorldGenerator* WorldGenerator::instance_ = 0;

// This is the constructor of a class that has been exported.
// see WorldGenerator.h for the class definition
WorldGenerator::WorldGenerator()
{
  std::cout << "entered: WorldGenerator::WorldGenerator()" << std::endl;
  universe_ = new Universe(this);
  world_parameters_ = NULL;
	return;
}


WorldGenerator* WorldGenerator::getInstance() {
  std::cout << "entered: WorldGenerator::getInstace()" << std::endl;
  if(instance_ == NULL) {
    instance_ = new WorldGenerator();
  }
  return instance_;
}


ParameterContainer WorldGenerator::get_world_parameters() {
  std::cout << "entered: WorldGenerator::get_world_parameters()" << std::endl;
  if(world_parameters_ == NULL) {
    world_parameters_ = new ParameterContainer();
  }
  return *world_parameters_;
}


bool WorldGenerator::set_world_parameters(ParameterContainer world_parameters) {
  std::cout << "entered: WorldGenerator::set_world_parameters()" << std::endl;
  delete world_parameters_;
  world_parameters_ = new ParameterContainer(world_parameters);
  if(world_parameters_->universe_size_ != world_parameters.universe_size_) {
    return 0;
  }
  return 1;
}


bool WorldGenerator::doTheGodJob() {
  std::cout << "entered: WorldGenerator::doTheGodJob()" << std::endl;
  get_world_parameters();
  bool result = universe_->generateWorld();
  if(result) {
    // TODO Log-Message
    std::cout << "Darwinism FTW!" << std::endl;
  }
  else {
    // TODO Log-Message
    std::cout << "Darwinism failed hard" << std::endl;
  }
  return result;
}