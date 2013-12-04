/**
  @file   Orb.h
  @brief  contains the definition of the class Orb
  @author mwilhelm
  @date   2013-11-27
**/

#pragma once

#include "Globals.h"

/**
  @class Orb
  @brief contains functions for the creation of one orb
**/
class Orb {
  public:
    Orb();
    Orb(GlobalEnums::Biomes biome);
    ~Orb();

  private:
    bool generateForegroundLayer();
    bool generateBuildingLayer();

    GlobalEnums::OrbSize size_ = GlobalEnums::OrbSize::kMedium;  //!< orb size
    GlobalEnums::Biomes biome_ = GlobalEnums::Biomes::kGrass; //!< orb biome
    int universe_x_pos_ = 0;  //!< the orb's x coordinates in the universe
    int universe_y_pos_ = 0;  //!< the orb's y coordinates in the universe
    int zero_level_land_ = 0;  //!< the zero level of the land mass in the orb
    int zero_level_liquid_ = -3;  //!< the zero level of the liquids in the orb
    bool isStartOrb_ = 0; //!< 1 = start orb; 0 = ordinary orb
    bool containsBoss_ = 0; //!< 0 = no boss; >0 boss ID
    //bool containsEvent_ = 0; //!< 0 = no event; >0 event ID
};

