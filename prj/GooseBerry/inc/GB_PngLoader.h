/**
@file	GB_PngLoader.h
@brief	Includes png loader
@author	drubner
@date	2014-01-03
**/
//==================================================================
//	PRAGMA ONCE
//==================================================================
#pragma once

//==================================================================
//	INCLUDE
//==================================================================
#include "..\ext\libpng-1.6.8\png.h"
#include "gooseberry.h"

//GOOSEBERRY_API GB_Enum::gbResult LoadPngImage(char *name, int &outer_width, int &outer_height, bool &has_alpha, GLubyte **out_data);
GOOSEBERRY_API GB_Enum::gbResult LoadPngImage(char * name, int * width, int * height, GLuint * texture);