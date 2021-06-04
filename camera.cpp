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
}

void Camera::Draw()
{
	// 3D�ݒ�
	CRenderer::OpenGLSet3D();
	// �J�����̍쐬->���f���r���[�s��ɏ�Z
	gluLookAt(
		m_positon.x, m_positon.y, m_positon.z,	// �J�������W
		m_lookAt.x, m_lookAt.y, m_lookAt.z,	// �����_
		m_up.x, m_up.y, m_up.z);	// �J�����̏����
}