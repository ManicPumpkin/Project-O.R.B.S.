/**
  @file   Orb.cpp
  @brief  contains the function definitions of the class Orb
  @author mwilhelm
  @date   2013-11-27
**/

#include "stdafx.h"

using namespace GlobalEnums;

/**
  @fn     Orb :: Orb
  @brief  default constructor
**/
Orb::Orb() {
#ifdef DEBUG_MODE
  std::cout << "entered Orb::Orb()" << std::endl;
#endif
}

/**
  @fn     Orb :: Orb
  @brief  constructor
  @param  biome    holds the biome
**/
Orb::Orb(Biomes biome) {
#ifdef DEBUG_MODE
  std::cout << "entered Orb::Orb(Biomes " << (int)biome << ")" << std::endl;
#endif
  biome_ = biome;
}

/**
  @fn     Orb :: ~Orb
  @brief  destructor
**/
Orb::~Orb() {
#ifdef DEBUG_MODE
  std::cout << "entered Orb::~Orb()" << std::endl;
#endif
}

/**
  @fn     Orb :: generateForegroundLayer
  @brief  
  @return 1 = OK; 0 = Error
**/
bool Orb::generateForegroundLayer() {
#ifdef DEBUG_MODE
  std::cout << "entered Orb::generateForegroundLayer()" << std::endl;
#endif
  return 0;
}

/**
  @fn     Orb :: generateBackgroundLayer
  @brief
  @return 1 = OK; 0 = Error
**/
bool Orb::generateBuildingLayer() {
#ifdef DEBUG_MODE
  std::cout << "entered Orb::generateBuildingLayer()" << std::endl;
#endif
  return 0;
}