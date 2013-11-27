#pragma once

#include "Globals.h"

class Orb {
  public:
    Orb();
    ~Orb();

    GlobalEnums::Biomes biome_;

  private:
    bool generateForegroundLayer();
    bool generateBuildingLayer();

    GlobalEnums::OrbSize size_;
    int universe_x_pos_;
    int universe_y_pos_;
    int zero_level_land_;
    int zero_level_liquid_;
};

