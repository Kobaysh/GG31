//=============================================================================
//
// �e�N�X�`���ǂݍ��� [textureGL.cpp]
//
//=============================================================================
#define _CRT_SECURE_NO_WARNINGS	//<<<<<<

#include "main.h"
#include <stdio.h>

#pragma comment(lib, "glu32.lib")//<<<<<<

//*****************************************************************************
// �e�N�X�`���ǂݍ���
//*****************************************************************************
unsigned int LoadTexture( char *FileName )
{
	unsigned int	texture;
	unsigned char	header[18]; 
	unsigned char	*image;
	FILE			*file;
	unsigned int	width, height;

	file = fopen( FileName, "rb" );
	if( file == NULL )
	{
		return 0;
	}

	// �w�b�_�ǂݍ���
	fread( header, 1, sizeof(header), file );

	// �摜�T�C�Y�擾
    width = header[13] * 256 + header[12];
    height = header[15] * 256 + header[14];

	// �������m��
	image = new unsigned char[ width * height * 4 ];

	// �摜�ǂݍ���
	for( unsigned int y = 0; y < height; y++ )
	{
		for( unsigned int x = 0; x < width; x++ )
		{
			image[(y * width + x) * 4 + 2] = fgetc( file );
			image[(y * width + x) * 4 + 1] = fgetc( file );
			image[(y * width + x) * 4 + 0] = fgetc( file );
			image[(y * width + x) * 4 + 3] = fgetc( file );
		}
	}

	fclose( file );
	
	// �e�N�X�`������
	glGenTextures( 1, &texture );
	glBindTexture( GL_TEXTURE_2D, texture );

	glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
/*
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, 256, 256, 0, GL_RGBA, GL_UNSIGNED_BYTE, image );
*/
	//�~�b�v�}�b�v
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
	gluBuild2DMipmaps( GL_TEXTURE_2D, GL_RGBA, width, height, GL_RGBA, GL_UNSIGNED_BYTE, image );

	glBindTexture( GL_TEXTURE_2D, 0 );

	// ���������
	delete[] image;

	return texture;
}


void UnloadTexture(unsigned int Texture)
{
	glDeleteTextures(1, &Texture);
}