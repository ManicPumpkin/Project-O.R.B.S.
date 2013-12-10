//=============================================================================
/**
  @file   Orb.cpp
  @brief  contains the function definitions of the class Orb
  @author mwilhelm
  @date   2013-11-27
**/
//=============================================================================
// INCLUDES
//=============================================================================
#include "stdafx.h"
#include <string>

//=============================================================================
// NAMESPACES
//=============================================================================
using namespace GlobalEnums;

//=============================================================================
// (DE)CONSTRUCTOR
//=============================================================================
/**
  @fn     Orb::Orb()
  @brief  default constructor
**/
//=============================================================================
Orb::Orb() {
  LOG_DEBUG("entered Orb::Orb()");
}

//=============================================================================
/**
  @fn     Orb::Orb()
  @brief  constructor
  @param  biome    holds the biome
**/
//=============================================================================
Orb::Orb(Biomes biome) {
  LOG_DEBUG("entered Orb::Orb(Biomes biome)");
  LOG_DEBUG("biome = " + std::to_string((int)biome));
  biome_ = biome;
}

//=============================================================================
/**
  @fn     Orb::~Orb()
  @brief  destructor
**/
//=============================================================================
Orb::~Orb() {
  LOG_DEBUG("entered Orb::~Orb()");
}

//=============================================================================
// FUNCTIONS
//=============================================================================
/**
  @fn     Orb::generateForegroundLayer()
  @brief  Generates the foreground layer. 
  
  The foreground layer is the layer, which contains the editable tiles like
  wood, ore, stone etc.
  @return 1 = OK; 0 = Error
**/
//=============================================================================
bool Orb::generateForegroundLayer() {
  LOG_DEBUG("entered Orb::generateForegroundLayer()");

  return 0;
}

//=============================================================================
/**
  @fn     Orb::generateBackgroundLayer()
  @brief  Generates the background layer.

  The background layer contains walls etc.
  @return 1 = OK; 0 = Error
**/
//=============================================================================
bool Orb::generateBuildingLayer() {
  LOG_DEBUG("entered Orb::generateBuildingLayer()");
  return 0;
}