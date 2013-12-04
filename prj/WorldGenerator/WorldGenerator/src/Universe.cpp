/**
  @file   Unvierse.cpp
  @brief  contains the function definitions of the class Universe
  @author mwilhelm
  @date   2013-11-27
**/

#include "stdafx.h"
//#include <ctime>
#include <random>
//#include <iterator>

using namespace GlobalEnums;
using namespace std;

/**
  @fn     Universe :: Universe
  @brief  default constructor
**/
/*Universe::Universe() {
#ifdef DEBUG_MODE
  std::cout << "entered Universe::Universe()" << std::endl;
#endif
}*/

/**
  @fn     Universe :: Universe
  @brief  constructor
  @param  *parent    pointer to parent
**/
/*inline*/ Universe::Universe(WorldGenerator *parent) {
#ifdef DEBUG_MODE
  std::cout << "entered: Universe::Universe(WorldGenerator *parent)" << std::endl;
#endif
  parent_ = parent;
  init();
}

/**
  @fn     Universe :: ~Universe
  @brief  destructor
**/
Universe::~Universe() {
#ifdef DEBUG_MODE
  std::cout << "entered Universe::~Universe()" << std::endl;
#endif

  //delete start_orb_;
  orbs_.clear();
  //delete parent_;
  parent_ = NULL;
}

/**
  @fn     Universe ::generateWorld
  @brief  starts the world generation routine
  @return 1 = OK; 0 = Error
**/
bool Universe::generateWorld() {
#ifdef DEBUG_MODE
  std::cout << "entered Universe::generateWorld()" << std::endl;
#endif

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
#ifdef DEBUG_MODE
    std::cout << i << " ";
#endif

    orbs_.insert(pair<uint32_t, Orb*>(i, generateOrb()));
  }

  return 0; // TODO correct it
}

/**
@fn     Universe :: init
@brief  initializes members
@return 1 = OK; 0 = Error
**/
bool Universe::init() {
#ifdef DEBUG_MODE
  std::cout << "entered Universe::init()" << std::endl;
#endif
  bool result = 1;
  
  size_ = UniverseSize::kMedium;
  
  orb_count_ = 40;

  //orbs_;

  //start_orb_ = new std::pair<uint32_t, Orb>();

  start_orb_ = 0;

  return result;
}

/**
@fn     Universe :: generateOrb
@brief  generate a instance of class Orb
@return the new instance of class Orb
**/
Orb* Universe::generateOrb() {
#ifdef DEBUG_MODE
  std::cout << "entered Universe::generateOrb()" << std::endl;
#endif
  
  std::random_device generator;
  std::uniform_int_distribution<int> distribution(0, sizeof(Biomes)-1);
  

  Biomes random_biome = static_cast<Biomes>(distribution(generator));

  return new Orb(random_biome);
}

/**
@fn     Universe :: generateOrbConnections
@brief  generates connections between orbs
@return 1 = OK; 0 = Error
**/
bool Universe::generateOrbConnection() {
#ifdef DEBUG_MODE
  std::cout << "entered Universe::generateOrbConnection()" << std::endl;
#endif

  return 0; //TODO  implement
}

/**
@fn     Universe :: setStartOrb
@brief  defines which orb should be the start orb
@return 1 = OK; 0 = Error
**/
bool Universe::setStartOrb() {
#ifdef DEBUG_MODE
  std::cout << "entered Universe::setStartOrb()" << std::endl;
#endif

  return 0;  //TODO  implement
}

/**
@fn     Universe :: insertBosses
@brief  places bosses in orbs
@return 1 = OK; 0 = Error
**/
bool Universe::insertBosses() {
#ifdef DEBUG_MODE
  std::cout << "entered Universe::insertBosses()" << std::endl;
#endif

  return 0; //TODO  implement
}

/**
@fn     Universe :: insertEvents
@brief  places events in orbs
@return 1 = OK; 0 = Error
**/
bool Universe::insertEvents() {
#ifdef DEBUG_MODE
  std::cout << "entered Universe::insertEvents()" << std::endl;
#endif

  return 0; //TODO  implement
}

