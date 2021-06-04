#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "polygon.h"
#include "camera.h"

CPolygon3D* g_po;
Camera* g_carema;

void CManager::Init()
{
	CRenderer::Init();

	g_po = new CPolygon3D;
	g_po->Init();

	g_carema = new Camera;
	g_carema->Init();
}

void CManager::Uninit()
{
	g_po->Uninit();
	delete g_po;
	g_carema->Uninit();
	delete g_carema;

	CRenderer::Uninit();
}

void CManager::Update()
{
	g_carema->Update();
	g_po->Update();
}

void CManager::Draw()
{
	CRenderer::Begin();

	g_carema->Draw();
	g_po->Draw();

	CRenderer::End();
}
