/**
  @file   Unvierse.cpp
  @brief  contains the function definitions of the class Universe
  @author mwilhelm
  @date   2013-11-27
**/

#include "stdafx.h"

using namespace GlobalEnums;
using namespace std;

/**
  @fn     Universe :: Universe
  @brief  default constructor
**/
/*Universe::Universe() {
}*/

/**
  @fn     Universe :: Universe
  @brief  constructor
  @param  *parent    pointer to parent
**/
/*inline*/ Universe::Universe(WorldGenerator *parent) {
  std::cout << "entered: Universe::Universe(WorldGenerator *parent)" << std::endl;
  parent_ = parent;
  init();
}

/**
  @fn     Universe :: ~Universe
  @brief  destructor
**/
Universe::~Universe() {
  std::cout << "entered: Universe::~Universe()" << std::endl;
  delete this->start_orb_;
  delete parent_;
}

/**
  @fn     Universe ::generateWorld
  @brief  starts the world generation routine
  @return 1 = OK; 0 = Error
**/
bool Universe::generateWorld() {
  std::cout << "entered: Universe::generateWorld()" << std::endl;

  size_ = parent_->get_world_parameters().universe_size_;

  switch(size_) {
    case UniverseSize::kTiny:
      orb_count_ = 10;
      break;
    case UniverseSize::kSmall:
      orb_count_ = 20;
      break;
    case UniverseSize::kMedium:
      orb_count_ = 40;
      break;
    case UniverseSize::kLarge:
      orb_count_ = 80;
      break;
    case UniverseSize::kHuge:
      orb_count_ = 200;
      break;
    default:
      orb_count_ = 40;
      //TODO Log-Error-Message
      break;
  }

  for(uint32_t i = 0; i < orb_count_; i++) {
    std::cout << i << " ";
    orbs_.insert(pair<uint32_t, Orb>(i, generateOrb()));
  }

  return 0; // TODO correct it
}

/**
@fn     Universe :: init
@brief  initializes members
@return 1 = OK; 0 = Error
**/
bool Universe::init() {
  std::cout << "entered: Universe::init()" << std::endl;
  bool result = 1;
  
  size_ = UniverseSize::kMedium;
  
  orb_count_ = 40;

  //orbs_;

  start_orb_ = new std::pair<uint32_t, Orb>();

  return result;
}

/**
@fn     Universe :: generateOrb
@brief  generate a instance of class Orb
@return the new instance of class Orb
**/
Orb& Universe::generateOrb() {
  std::cout << "entered: Universe::generateOrb()" << std::endl;
  return *new Orb();
}

/**
@fn     Universe :: generateOrbConnections
@brief  generates connections between orbs
@return 1 = OK; 0 = Error
**/
bool Universe::generateOrbConnection() {
  std::cout << "entered: Universe::generatteOrbConnection()" << std::endl;
  return 0;
}

/**
@fn     Universe :: setStartOrb
@brief  defines which orb should be the start orb
@return 1 = OK; 0 = Error
**/
bool Universe::setStartOrb() {
  std::cout << "entered: Universe::setStartOrb()" << std::endl;
  return 0;
}

/**
@fn     Universe :: insertBosses
@brief  places bosses in orbs
@return 1 = OK; 0 = Error
**/
bool Universe::insertBosses() {
  std::cout << "entered: Universe::insertBosses()" << std::endl;
  return 0;
}

/**
@fn     Universe :: insertEvents
@brief  places events in orbs
@return 1 = OK; 0 = Error
**/
bool Universe::insertEvents() {
  std::cout << "entered: Universe::insertEvents()" << std::endl;
  return 0;
}

