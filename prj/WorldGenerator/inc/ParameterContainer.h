//=============================================================================
/**
  @file   ParameterContainer.h
  @brief  Contains a struct of parameters to make the accessible from outside 
          the dll.
  @author mwilhelm
  @date   2013-11-27
**/
//=============================================================================
// INCLUDE GUARD
//=============================================================================
#pragma once

//=============================================================================
// INCLUDES
//=============================================================================
#include "GlobalEnums.h"

//=============================================================================
// STRUCTS
//=============================================================================
/**
  @struct ParameterContainer
  @brief  A struct of parameters, which are needed for world generation.
**/
struct ParameterContainer {
  GlobalEnums::UniverseSize universe_size_ = 
      GlobalEnums::UniverseSize::kMedium;
  //===========================================================================
  /**
    @fn     ParameterContainer::ParameterContainer()
    @brief  default constructor
  **/
  //===========================================================================
  ParameterContainer() {
  }

  //===========================================================================
  /**
    @overload ParameterContainer::ParameterContainer()
    @brief  copy constructor
    @param  &original    original that should get copied
  **/
  //===========================================================================
  ParameterContainer(ParameterContainer &original) {
    universe_size_ = original.universe_size_;
  }
};