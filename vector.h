#pragma once

// 色構造体
struct COLOR
{
	float r;
	float g;
	float b;
	float a;
};

// 2Dベクトル構造体
struct VECTOR2D
{
	VECTOR2D operator+(VECTOR2D vec) {
		VECTOR2D temp(0.0f, 0.0f);
		temp.x = this->x + vec.x;
		temp.y = this->y + vec.y;
		return temp;
	}
	VECTOR2D operator-(VECTOR2D vec) {
		VECTOR2D temp(0.0f, 0.0f);
		temp.x = this->x - vec.x;
		temp.y = this->y - vec.y;
		return temp;
	}
	VECTOR2D operator+=(VECTOR2D vec) {
		this->x = this->x + vec.x;
		this->y = this->y + vec.y;
		return *this;
	}
	VECTOR2D operator-=(VECTOR2D vec) {
		this->x = this->x - vec.x;
		this->y = this->y - vec.y;
		return *this;
	}
	VECTOR2D()
	{
		x = 0.0f;
		y = 0.0f;
	}

	VECTOR2D(float inX, float inY)
	{
		x = inX;
		y = inY;
	}

	float x;
	float y;
};

// 3Dベクトル構造体
struct VECTOR3D
{
	VECTOR3D operator+(VECTOR3D vec) {
		VECTOR3D temp(0.0f, 0.0f, 0.0f);
		temp.x = this->x + vec.x;
		temp.y = this->y + vec.y;
		temp.z = this->z + vec.z;
		return temp;
	}
	VECTOR3D operator-(VECTOR3D vec) {
		VECTOR3D temp(0.0f, 0.0f, 0.0f);
		temp.x = this->x - vec.x;
		temp.y = this->y - vec.y;
		temp.z = this->z - vec.z;
		return temp;
	}
	VECTOR3D operator+=(VECTOR3D vec) {
		this->x = this->x + vec.x;
		this->y = this->y + vec.y;
		this->z = this->z + vec.z;
		return *this;
	}
	VECTOR3D operator-=(VECTOR3D vec) {
		this->x = this->x - vec.x;
		this->y = this->y - vec.y;
		this->z = this->z - vec.z;
		return *this;
	}

	VECTOR3D()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	VECTOR3D(float inX, float inY, float inZ)
	{
		x = inX;
		y = inY;
		z = inZ;
	}

	float x;
	float y;
	float z;
};

// 4Dベクトル構造体
struct VECTOR4D
{
	VECTOR4D operator+(VECTOR4D vec) {
		VECTOR4D temp(0.0f, 0.0f, 0.0f,0.0f);
		temp.x = this->x + vec.x;
		temp.y = this->y + vec.y;
		temp.z = this->z + vec.z;
		temp.w = this->w + vec.w;
		return temp;
	}
	VECTOR4D operator-(VECTOR4D vec) {
		VECTOR4D temp(0.0f, 0.0f, 0.0f,0.0f);
		temp.x = this->x - vec.x;
		temp.y = this->y - vec.y;
		temp.z = this->z - vec.z;
		temp.w = this->w - vec.w;
		return temp;
	}
	VECTOR4D operator+=(VECTOR4D vec) {
		this->x = this->x + vec.x;
		this->y = this->y + vec.y;
		this->z = this->z + vec.z;
		this->w = this->w + vec.w;
		return *this;
	}
	VECTOR4D operator-=(VECTOR4D vec) {
		this->x = this->x - vec.x;
		this->y = this->y - vec.y;
		this->z = this->z - vec.z;
		this->w = this->w - vec.w;
		return *this;
	}
	VECTOR4D()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
		w = 0.0f;
	}

	VECTOR4D(float inX, float inY, float inZ, float inW)
	{
		x = inX;
		y = inY;
		z = inZ;
		w = inW;
	}

	float x;
	float y;
	float z;
	float w;
};

// マテリアル構造体
struct MATERIAL
{
	COLOR		Ambient;
	COLOR		Diffuse;
	COLOR		Specular;
	COLOR		Emission;
	float		Shininess;
};

// 3D頂点構造体
struct VERTEX_3D
{
	VECTOR2D		TexCoord;
	COLOR			Diffuse;
	VECTOR3D		Normal;
	VECTOR3D		Position;
};