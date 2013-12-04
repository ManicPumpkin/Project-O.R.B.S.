/**
  @file   ParameterContainer.h
  @brief  contains a struct of parameters to make the accessible from outside 
          the dll
  @author mwilhelm
  @date   2013-11-27
**/

#pragma once

#include "GlobalEnums.h"


/**
  @struct ParameterContainer
  @brief  a struct parameters, which are needed for world generation
**/
struct ParameterContainer {
  GlobalEnums::UniverseSize universe_size_ = 
      GlobalEnums::UniverseSize::kMedium;

  /**
    @fn     ParameterContainer :: ParameterContainer
    @brief  default constructor
  **/
  ParameterContainer() {
  }

  /**
    @fn     ParameterContainer :: ParameterContainer
    @brief  copy constructor
    @param  &original    original that should get copied
  **/
  ParameterContainer(ParameterContainer &original) {
    universe_size_ = original.universe_size_;
  }
};