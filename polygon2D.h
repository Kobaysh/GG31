#pragma once

class  CPolygon2D
{
public:
	 CPolygon2D();
	~ CPolygon2D();

	void Init();
	void Uninit();
	void Update();
	void Draw();

private:
	int m_Texture;
};

