#pragma once

#include <unordered_map>
#include <cstdint>

#include "Globals.h"

class WorldGenerator;
class Orb;

class Universe {
  public:
    //Universe();
    explicit /*inline*/ Universe(WorldGenerator *parent);
    ~Universe();
    bool generateWorld();

  private:
    bool init();
    Orb& generateOrb();
    bool generateOrbConnection();
    bool setStartOrb();
    bool insertBosses();
    bool insertEvents();

    WorldGenerator *parent_;
    GlobalEnums::UniverseSize size_;
    uint32_t orb_count_;
    std::unordered_map<uint32_t, Orb> orbs_;
    std::pair<uint32_t, Orb> *start_orb_;
};

