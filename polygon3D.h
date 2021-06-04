#pragma once

class  CPolygon3D
{
public:
	 CPolygon3D();
	~ CPolygon3D();

	void Init();
	void Uninit();
	void Update();
	void Draw();

private:
	int m_Texture;
};

