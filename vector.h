#pragma once

// 色構造体
struct COLOR
{
	float r;
	float g;
	float b;
	float a;
};

// マテリアル構造体
struct MATERIAL
{
	COLOR Ambient;	// 環境光
	COLOR Diffuse;	// 反射光
	COLOR Specular;	// 鏡面反射
	COLOR Emission;	// 自発光
	float Shininess;// スペキュラー強度

};

// 2Dベクトル構造体
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


// 3Dベクトル構造体
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

// 4Dベクトル構造体
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
	VECTOR2D	TexCoord;	// テクスチャ座標
	COLOR		Diffuse;	// 頂点カラー
	VECTOR3D	Position;	// 座標
	VECTOR3D	Normal;		// 法線
};