#include "main.h"
#include "renderer.h"
#include "camera.h"

#define CAMERA_SPEED 0.5f

void Camera::Init()
{
	m_positon = VECTOR3D(0.0f, 0.0f, 10.0f);
	m_front = VECTOR3D(0.0f, 0.0f, -1.0f);
	m_right = VECTOR3D(1.0f, 0.0f, 0.0f);
	m_up = VECTOR3D(0.0f, 1.0f, 0.0f);
	m_lookAt = m_positon + m_front;
}

void Camera::Uninit()
{
}

void Camera::Update()
{
	VECTOR3D temp;
	if (0x8000 & GetAsyncKeyState('W') &  GetAsyncKeyState(VK_CONTROL)) {
		temp.z -= CAMERA_SPEED;
	}
	else if (0x8000 & GetAsyncKeyState('S') &  GetAsyncKeyState(VK_CONTROL)) {
		temp.z += CAMERA_SPEED;
	}
	else if (0x8000 & GetAsyncKeyState('D') &  GetAsyncKeyState(VK_CONTROL)) {
		temp.x += CAMERA_SPEED;
	}
	else if (0x8000 & GetAsyncKeyState('A') &  GetAsyncKeyState(VK_CONTROL)) {
		temp.x -= CAMERA_SPEED;
	}
	else if (0x8000 & GetAsyncKeyState('E') &  GetAsyncKeyState(VK_CONTROL)) {
		temp.y += CAMERA_SPEED;
	}
	else if (0x8000 & GetAsyncKeyState('Q') &  GetAsyncKeyState(VK_CONTROL)) {
		temp.y -= CAMERA_SPEED;
	}
	m_positon += temp;
	//m_positon = m_positon + temp;
	m_lookAt = m_positon + m_front;
}

void Camera::Draw()
{
	// 3D設定
	CRenderer::OpenGLSet3D();
	// カメラの作成->モデルビュー行列に乗算
	gluLookAt(
		m_positon.x, m_positon.y, m_positon.z,	// カメラ座標
		m_lookAt.x, m_lookAt.y, m_lookAt.z,	// 注視点
		//m_front.x, m_front.y, m_front.z,	// 注視点
		m_up.x, m_up.y, m_up.z);	// カメラの上方向
}
