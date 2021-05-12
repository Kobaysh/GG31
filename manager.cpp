#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "polygon.h"

CPolygon* g_po;

void CManager::Init()
{
	CRenderer::Init();

	g_po = new CPolygon;
	g_po->Init();
}

void CManager::Uninit()
{
	g_po->Uninit();
	delete g_po;

	CRenderer::Uninit();
}

void CManager::Update()
{
	g_po->Update();
}

void CManager::Draw()
{
	CRenderer::Begin();

	g_po->Draw();

	CRenderer::End();
}
