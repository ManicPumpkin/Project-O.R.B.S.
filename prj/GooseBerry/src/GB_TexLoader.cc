/**
@file	GB_TexLoader.cc
@brief	Includes texture loader function
@author	drubner
@date	2014-01-10
**/
//==================================================================
//	PRAGMA
//==================================================================

//==================================================================
//	INCLUDE
//==================================================================
#include "GB_TexLoader.h"

//==================================================================
//	FUNCTION
//==================================================================
GOOSEBERRY_API GLuint LoadTextureGB(const char * file_name, int width, int height)
{
	GLuint texture;
	unsigned char * data;
	FILE * file;

	fopen_s(&file, file_name, "rb");
	if (!file)
		return GB_ERROR;

	data = (unsigned char*)malloc(width * height * 4);
	fread(data, width * height * 4, 1, file);
	fclose(file);

	// create 1 texture with name (&texture)
	glGenTextures(1, &texture);

	// specify the target to which the texture is bound and specifies 
	// the name of a texture (texture var)
	glBindTexture(GL_TEXTURE_2D, texture);

	// select modulate to mix texture with color for shading
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	// specifiy the teaget texture (GL_TEXTURE_2D), the symbolic name of a single-valued
	// texture parameter (GL_TEXTURE_MAG_FILTER/GL_TEXTURE_MIN_FILTER) and some scalar
	// comments (GL_DECAL)
	// see also: http://wiki.delphigl.com/index.php/glTexParameter
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_DECAL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_DECAL);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// build texture mipmaps
	gluBuild2DMipmaps(GL_TEXTURE_2D, 4, width, height, GL_RGBA, GL_UNSIGNED_BYTE, data);

	free(data);
	return texture;
}