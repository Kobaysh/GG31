#include "main.h"
#include "renderer.h"
#include <io.h>

HWND	CRenderer::m_Wnd;
HGLRC	CRenderer::m_GLRC;
HDC		CRenderer::m_DC;


void CRenderer::Init()
{
	// ウィンドウハンドル保存
	m_Wnd = GetWindow();

	// ピクセルフォーマット
	PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW |
		PFD_SUPPORT_OPENGL |
		PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		24,
		0, 0, 0, 0, 0, 0,
		0,
		0,
		0,
		0, 0, 0, 0,
		32,
		0,
		0,
		PFD_MAIN_PLANE,
		0,
		0, 0, 0
	};


	// Windowデバイスコンテキスト取得
	m_DC = GetDC(m_Wnd);

	int pixelFormat = ChoosePixelFormat(m_DC, &pfd);
	SetPixelFormat(m_DC, pixelFormat, &pfd);

	//GLコンテキスト作成
	m_GLRC = wglCreateContext(m_DC);
	wglMakeCurrent(m_DC, m_GLRC);


	// OpenGL描画設定
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
}

void CRenderer::Uninit()
{
	wglMakeCurrent(NULL, NULL);
	ReleaseDC(m_Wnd, m_DC);
	wglDeleteContext(m_GLRC);
}

void CRenderer::Begin()
{
	// 画面クリア
	glClearColor(0.0f, 0.5f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void CRenderer::End()
{
	// フロントバッファ・バックバッファ入れ替え
	SwapBuffers(m_DC);
}

void CRenderer::OpenGLSet2D()
{
	// 2Dマトリクス設定
	glMatrixMode(GL_PROJECTION);	// プロジェクション行列操作モード
	
	glLoadIdentity();				// プロジェクション行列に単位行列をセット

	glOrtho(0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 1);	// 平行投影をセット

	glMatrixMode(GL_MODELVIEW);		// モデルビュー行列操作モード

	glLoadIdentity();				// モデルビュー行列を単位行列にする
}

void CRenderer::OpenGLSet3D()
{
}


