#pragma once

// �F�\����
struct COLOR
{
	float r;
	float g;
	float b;
	float a;
};

// �}�e���A���\����
struct MATERIAL
{
	COLOR Ambient;	// ����
	COLOR Diffuse;	// ���ˌ�
	COLOR Specular;	// ���ʔ���
	COLOR Emission;	// ������
	float Shininess;// �X�y�L�����[���x

};

// 2D�x�N�g���\����
struct VECTOR2D
{
	VECTOR2D()
	{
		x = 0;
		y = 0;
	}
	VECTOR2D(float inX, float inY)
	{
		x = inX;
		y = inY;
	}


	float x, y;
};


// 3D�x�N�g���\����
struct VECTOR3D
{
	VECTOR3D()
	{
		x = 0;
		y = 0;
		z = 0;
	}
	VECTOR3D(float inX, float inY, float inZ)
	{
		x = inX;
		y = inY;
		z = inZ;
	}


	float x, y,z;
};

// 4D�x�N�g���\����
struct VECTOR4D
{
	VECTOR4D()
	{
		x = 0;
		y = 0;
		z = 0;
		w = 0;
	}
	VECTOR4D(float inX, float inY, float inZ, float inW)
	{
		x = inX;
		y = inY;
		z = inZ;
		w = inW;
	}


	float x, y, z, w;
};

struct VERTEX_3D
{
	VECTOR2D	TexCoord;	// �e�N�X�`�����W
	COLOR		Diffuse;	// ���_�J���[
	VECTOR3D	Position;	// ���W
	VECTOR3D	Normal;		// �@��
};