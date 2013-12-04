/**
  @file   Universe.h
  @brief  contains the definition of the class Orb
  @author mwilhelm
  @date   2013-11-27
**/

#pragma once

#include <unordered_map>
#include <cstdint>

#include "GlobalEnums.h"

class WorldGenerator;
class Orb;

/**
  @class Universe
  @brief contains functions for the creation of the universe
**/
class Universe {
  public:
    //Universe();
    explicit Universe(WorldGenerator *parent);
    ~Universe();
    bool generateWorld();

  private:
    bool init();
    Orb* generateOrb();
    bool generateOrbConnection();
    bool setStartOrb();
    bool insertBosses();
    bool insertEvents();

    WorldGenerator *parent_;  //!< points to the parent instance
    GlobalEnums::UniverseSize size_;  //!< specifies the size of the universe
    uint32_t orb_count_;  //!< holds the amount of orbs for the universe
    std::unordered_map<uint32_t, Orb*> orbs_;  //!< holds all orbs and their IDs
    //std::pair<uint32_t, Orb*> *start_orb_;  //!< specifies which orb is the start orb
    uint32_t start_orb_; //!< holds the start orb's ID
};

