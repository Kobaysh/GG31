#pragma once
#include "vector.h"
class Camera{
public:
	void Init();
	void Uninit();
	void Update();
	void Draw();

private:
	VECTOR3D m_positon;
	VECTOR3D m_front;
	VECTOR3D m_right;
	VECTOR3D m_up;
	VECTOR3D m_lookAt;

};