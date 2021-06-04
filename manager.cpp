#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "polygon3D.h"
#include "polygon2D.h"
#include "camera.h"

CPolygon3D* g_po3D;
CPolygon2D* g_po2D;
Camera* g_carema;

void CManager::Init()
{
	CRenderer::Init();

	g_po3D = new CPolygon3D;
	g_po3D->Init();

	g_po2D = new CPolygon2D;
	g_po2D->Init();


	g_carema = new Camera;
	g_carema->Init();
}

void CManager::Uninit()
{
	g_po3D->Uninit();
	delete g_po3D;
	g_po2D->Uninit();
	delete g_po2D;
	g_carema->Uninit();
	delete g_carema;

	CRenderer::Uninit();
}

void CManager::Update()
{
	g_carema->Update();
	g_po3D->Update();
	g_po2D->Update();
}

void CManager::Draw()
{
	CRenderer::Begin();

	g_carema->Draw();
	g_po3D->Draw();
	g_po2D->Draw();

	CRenderer::End();
}
