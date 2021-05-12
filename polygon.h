#pragma once

class  CPolygon
{
public:
	 CPolygon();
	~ CPolygon();

	void Init();
	void Uninit();
	void Update();
	void Draw();

private:
	int m_Texture;
};

