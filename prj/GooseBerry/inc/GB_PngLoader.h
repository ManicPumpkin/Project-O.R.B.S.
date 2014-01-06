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
#include "png.h"
#include "gooseberry.h"

GB_Enum::gbResult LoadPngImage(char *name, int &outer_width, int &outer_height, bool &has_alpha, GLubyte **out_data)
{
	png_structp		png_ptr;
	png_infop		info_ptr;
	unsigned int	sig_read;
	int				color_type;
	int				interlace_type;
	FILE			*file_ptr;

	if ((file_ptr = fopen(name, "rb")) == NULL)
		return GB_Enum::GB_NOTFOUND;

	png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (png_ptr == NULL)
	{
		fclose(file_ptr);
		return GB_Enum::GB_ERROR;
	}

	info_ptr = png_create_info_struct(png_ptr);
	if (info_ptr == NULL)
	{
		fclose(file_ptr);
		return GB_Enum::GB_ERROR;
	}

	if (setjmp(png_jmpbuf(png_ptr)))
	{
		png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
		fclose(file_ptr);
		return GB_Enum::GB_ERROR;
	}

	png_init_io(png_ptr, file_ptr);
	png_set_sig_bytes(png_ptr, sig_read);

	png_read_png(png_ptr, info_ptr, PNG_TRANSFORM_STRIP_16 | PNG_TRANSFORM_PACKING | PNG_TRANSFORM_EXPAND, NULL);
	png_uint_32 width, height;
	int bit_depth;
	png_get_IHDR(png_ptr, info_ptr, &width, &height, &bit_depth, &color_type, &interlace_type, NULL, NULL);
	outer_width				= width;
	outer_height			= height;
	unsigned int row_bytes	= png_get_rowbytes(png_ptr, info_ptr);
	*out_data				= (unsigned char*)malloc(row_bytes * outer_height);
	png_bytepp row_ptrs		= png_get_rows(png_ptr, info_ptr);

	for (int i = 0; i < outer_height; i++)
		memcpy(*out_data + (row_bytes * (outer_height - 1 - i)), row_ptrs[i], row_bytes);

	png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
	fclose(file_ptr);

	return GB_Enum::GB_OK;
}