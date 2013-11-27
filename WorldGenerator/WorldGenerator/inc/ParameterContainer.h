#pragma once

#include "Globals.h"

struct ParameterContainer {
  GlobalEnums::UniverseSize universe_size_ = GlobalEnums::UniverseSize::kMedium;

  ParameterContainer() {
  }

  ParameterContainer(ParameterContainer &original) {
    universe_size_ = original.universe_size_;
  }
};