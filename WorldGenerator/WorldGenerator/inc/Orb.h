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
    ~Orb();

    GlobalEnums::Biomes biome_;

  private:
    bool generateForegroundLayer();
    bool generateBuildingLayer();

    GlobalEnums::OrbSize size_;  //!< orb size
    int universe_x_pos_;  //!< the orb's x coordinates in the universe
    int universe_y_pos_;  //!< the orb's y coordinates in the universe
    int zero_level_land_;  //!< the zero level of the land mass in the orb
    int zero_level_liquid_;  //!< the zero level of the liquids in the orb
};

