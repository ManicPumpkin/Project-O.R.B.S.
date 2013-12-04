/**
@file   GlobalEnums.h
@brief  Defines the namespace GlobalEnum and some enumerations, which should 
        get an own dll project later.
@author mwilhelm
@date   2013-12-04
**/

#pragma once

namespace GlobalEnums {

/**
@enum   GlobalEnums::Biomes
@brief  an enum with biome names
**/
enum class Biomes {
  kForest,
  kOzean,
  kHell,
  kGrass
};


/**
@enum   GlobalEnums::OrbSize
@brief  an enum with orb sizes
**/
enum class OrbSize {
  kSmall,
  kMedium,
  kLarge
};


/**
@enum   GlobalEnums::UniverseSize
@brief  an enum with universe sizes
**/
enum class UniverseSize {
  kTiny,
  kSmall,
  kMedium,
  kLarge,
  kHuge
};

}