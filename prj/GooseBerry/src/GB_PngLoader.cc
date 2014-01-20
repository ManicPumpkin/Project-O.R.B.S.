#include "GB_PngLoader.h"
//#include "gooseberry.h"

//GOOSEBERRY_API GB_Enum::gbResult LoadPngImage(char *name, int &outer_width, int &outer_height, bool &has_alpha, GLubyte **out_data)
GOOSEBERRY_API GB_Enum::gbResult LoadPngImage(char * name, int * width, int * height, GLuint * texture)
{
	GB_LINFO("Loading texture: " + (string)name);
	png_byte		png_header[8];
	png_structp		png_ptr;
	png_infop		info_ptr, end_ptr;
	FILE			*file_ptr;

	fopen_s(&file_ptr, name, "rb");
	if (file_ptr == NULL)
	{
		GB_LERROR("Could not find texture file to load (" + (string)name + ")", "Unknown");
		return GB_Enum::GB_ERROR;
	}

	fread(png_header, 1, 8, file_ptr);
	if (png_sig_cmp(png_header, 0, 8))
	{
		GB_LERROR("Texture file is not a PNG file", "Unknown");
		fclose(file_ptr);
		return GB_Enum::GB_ERROR;
	}

	png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!png_ptr)
	{
		GB_LERROR("PNG_CREATE_READ_STRUCT returned 0", "Unknown");
		fclose(file_ptr);
		return GB_Enum::GB_ERROR;
	}

	info_ptr = png_create_info_struct(png_ptr);
	if (!info_ptr)
	{
		GB_LERROR("PNG_CREATE_INFO_STRUCT returned 0", "Unknown");
		png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
		fclose(file_ptr);
		return GB_Enum::GB_ERROR;
	}

	end_ptr = png_create_info_struct(png_ptr);
	if (!end_ptr)
	{
		GB_LERROR("LibPNG error", "Unknown");
		png_destroy_read_struct(&png_ptr, &info_ptr, &end_ptr);
		fclose(file_ptr);
		return GB_Enum::GB_ERROR;
	}

	png_init_io(png_ptr, file_ptr);
	png_set_sig_bytes(png_ptr, 8);
	png_read_info(png_ptr, info_ptr);

	int bit_depth, color_type;
	png_uint_32 temp_width, temp_height;

	png_get_IHDR(png_ptr, info_ptr, &temp_width, &temp_height, &bit_depth, &color_type, NULL, NULL, NULL);
	if (width)	
		*width = temp_width;
	if (height)
		*height = temp_height;

	png_read_update_info(png_ptr, info_ptr);
	int row_bytes = png_get_rowbytes(png_ptr, info_ptr);
	row_bytes += 3 - ((row_bytes - 1) % 4);

	png_byte * image_data;
	image_data = (unsigned char *)malloc(row_bytes * temp_height * sizeof(png_byte)+15);
	if (image_data == NULL)
	{
		GB_LERROR("Couldn't allocate memory for PNG image data", "Unknown");
		png_destroy_read_struct(&png_ptr, &info_ptr, &end_ptr);
		fclose(file_ptr);
		return GB_Enum::GB_ERROR;
	}

	png_bytep * row_pointers = (png_bytep *)malloc(temp_height * sizeof(png_bytep));
	if (row_pointers == NULL)
	{
		GB_LERROR("Couldn't allocate memory for PNG row pointers", "Unknown");
		png_destroy_read_struct(&png_ptr, &info_ptr, &end_ptr);
		free(image_data);
		fclose(file_ptr);
		return GB_Enum::GB_ERROR;
	}

	for (unsigned int i = 0; i < temp_height; i++)
		row_pointers[temp_height - 1 - i] = image_data + i * row_bytes;

	png_read_image(png_ptr, row_pointers);
	GB_LDEBUG("Loading texture " + (string)name + " done.");

	GLuint temp_texture;
	glGenTextures(1, &temp_texture);
	glBindTexture(GL_TEXTURE_2D, temp_texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, temp_width, temp_height, 0, GL_RGB, GL_UNSIGNED_BYTE, image_data);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	*texture = temp_texture;

	png_destroy_read_struct(&png_ptr, &info_ptr, &end_ptr);
	free(image_data);
	free(row_pointers);
	fclose(file_ptr);
	return GB_Enum::GB_OK;

	/*
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
	outer_width = width;
	outer_height = height;
	unsigned int row_bytes = png_get_rowbytes(png_ptr, info_ptr);
	*out_data = (unsigned char*)malloc(row_bytes * outer_height);
	png_bytepp row_ptrs = png_get_rows(png_ptr, info_ptr);

	for (int i = 0; i < outer_height; i++)
		memcpy(*out_data + (row_bytes * (outer_height - 1 - i)), row_ptrs[i], row_bytes);

	png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
	fclose(file_ptr);

	return GB_Enum::GB_OK;
	*/
}