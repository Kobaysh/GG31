#pragma once

class CRenderer
{
private:
	static HWND		m_Wnd;
	static HGLRC	m_GLRC;
	static HDC		m_DC;

public:
	static void Init();
	static void Uninit();
	static void Begin();
	static void End();

	static void OpenGLSet2D();	// 2D描画モードへ切り替え
	static void OpenGLSet3D();	// 3D描画モードへ切り替え
};
