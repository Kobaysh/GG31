#include "main.h"
#include "renderer.h"
#include "polygon.h"
#include "textureGL.h"
#include "vector.h"
#include "renderer.h"
#include <math.h>

// テクスチャ画像のファイル名
char FileName[] = { "asset/texture/texture.tga" };


CPolygon::CPolygon()
{
}

CPolygon::~CPolygon()
{
}

 void CPolygon::Init()
{
	 m_Texture = LoadTexture(FileName);
}

 void CPolygon::Uninit()
{
	 UnloadTexture(m_Texture);
}

 void CPolygon::Update()
{
}

 void CPolygon::Draw()
{
	// ライトオフ
	glDisable(GL_LIGHTING);

	CRenderer::OpenGLSet2D();
	// プロジェクション行列->2D用の行列がセットされた状態
	// モデルビュー行列->単位行列がセットされた状態
	
	// テクスチャのセット
	glBindTexture(GL_TEXTURE_2D, m_Texture);
	static float rotZ = 0.0f;	// 回転角度z
// 表示座標
	static VECTOR3D Position1(SCREEN_WIDTH * 0.25f, SCREEN_HEIGHT * 0.25f, -0);
	// 回転ポリゴンを表示
	{
		glMatrixMode(GL_MODELVIEW);	// ポリゴン描画行列の操作に切り替える
		glPushMatrix();				// 現在のモデルビュー行列を保存
		{
			// 平行移動行列
			glTranslatef(Position1.x, Position1.y, Position1.z);	// スタックに乗算
			// 回転行列
			glRotatef(rotZ, 0, 0, 1.0f);	// 平行移動行列に乗算
			rotZ += 1.1f;

			// ポリゴンセット
			glBegin(GL_TRIANGLE_STRIP);			// 頂点のセット開始
			{
				glColor4f(1.0f, 0.0f, 0.0f, 1.0f);	// 頂点1のカラーセット
				glTexCoord2f(0.0f, 0.0f);			// 頂点1のテクスチャ座標
				glVertex3f(-100.0f, -100.0f, 0.0f);	// 頂点1の画面座標

				glColor4f(0.0f, 1.0f, 0.0f, 1.0f);	// 頂点2のカラーセット
				glTexCoord2f(0.0f, -1.0f);			// 頂点2のテクスチャ座標
				glVertex3f(-100.0f, 100.0f, 0.0f);	// 頂点2の画面座標

				glColor4f(0.0f, 0.0f, 1.0f, 1.0f);	// 頂点3のカラーセット
				glTexCoord2f(1.0f, 0.0f);			// 頂点3のテクスチャ座標
				glVertex3f(100.0f, -100.0f, 0.0f);	// 頂点3の画面座標

				glColor4f(1.0f, 1.0f, 1.0f, 1.0f);	// 頂点4のカラーセット
				glTexCoord2f(1.0f, -1.0f);			// 頂点4のテクスチャ座標
				glVertex3f(100.0f, 100.0f, 0.0f);	// 頂点4の画面座標


			}
			glEnd();
		}
		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();		// 行列スタックの復帰
	
	}

	{
		glPushMatrix();				// 現在のモデルビュー行列を保存
		{
			// 平行移動行列
			glTranslatef(Position1.x * 2, Position1.y * 2, Position1.z * 2);	// スタックに乗算
			// 回転行列
			glRotatef(rotZ, 0, 0, 1.0f);	// 平行移動行列に乗算
			rotZ += 1.1f;

			// ポリゴンセット
			glBegin(GL_TRIANGLE_STRIP);			// 頂点のセット開始
			{
				glColor4f(1.0f, 0.0f, 0.0f, 1.0f);	// 頂点1のカラーセット
				glTexCoord2f(0.0f, 0.0f);			// 頂点1のテクスチャ座標
				glVertex3f(-100.0f, -100.0f, 0.0f);	// 頂点1の画面座標

				glColor4f(0.0f, 1.0f, 0.0f, 1.0f);	// 頂点2のカラーセット
				glTexCoord2f(0.0f, -1.0f);			// 頂点2のテクスチャ座標
				glVertex3f(-100.0f, 100.0f, 0.0f);	// 頂点2の画面座標

				glColor4f(0.0f, 0.0f, 1.0f, 1.0f);	// 頂点3のカラーセット
				glTexCoord2f(1.0f, 0.0f);			// 頂点3のテクスチャ座標
				glVertex3f(100.0f, -100.0f, 0.0f);	// 頂点3の画面座標

				glColor4f(1.0f, 1.0f, 1.0f, 1.0f);	// 頂点4のカラーセット
				glTexCoord2f(1.0f, -1.0f);			// 頂点4のテクスチャ座標
				glVertex3f(100.0f, 100.0f, 0.0f);	// 頂点4の画面座標


			}
			glEnd();
		}
		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();		// 行列スタックの復帰
	}

	/*
	// ポリゴンの描画
	glBegin(GL_TRIANGLE_STRIP);			// 頂点のセット開始
	{
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);	// 頂点1のカラーセット
		glTexCoord2f(0.0f, 0.0f);			// 頂点1のテクスチャ座標
		glVertex3f(100.0f, 100.0f, 0.0f);	// 頂点1の画面座標

		glColor4f(0.0f, 1.0f, 0.0f, 1.0f);	// 頂点2のカラーセット
		glTexCoord2f(0.0f, -1.0f);			// 頂点2のテクスチャ座標
		glVertex3f(100.0f, 300.0f, 0.0f);	// 頂点2の画面座標

		glColor4f(0.0f, 0.0f, 1.0f, 1.0f);	// 頂点3のカラーセット
		glTexCoord2f(1.0f, 0.0f);			// 頂点3のテクスチャ座標
		glVertex3f(300.0f, 100.0f, 0.0f);	// 頂点3の画面座標

		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);	// 頂点4のカラーセット
		glTexCoord2f(1.0f, -1.0f);			// 頂点4のテクスチャ座標
		glVertex3f(300.0f, 300.0f, 0.0f);	// 頂点4の画面座標


	}
	glEnd();

	glBegin(GL_TRIANGLES);			// 頂点のセット開始
	{
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);	// 頂点1のカラーセット
		glTexCoord2f(0.0f, 0.0f);			// 頂点1のテクスチャ座標
		glVertex3f(400.0f, 200.0f, 0.0f);	// 頂点1の画面座標

		glColor4f(0.0f, 1.0f, 0.0f, 1.0f);	// 頂点2のカラーセット
		glTexCoord2f(0.0f, -1.0f);			// 頂点2のテクスチャ座標
		glVertex3f(400.0f, 400.0f, 0.0f);	// 頂点2の画面座標

		glColor4f(0.0f, 0.0f, 1.0f, 1.0f);	// 頂点3のカラーセット
		glTexCoord2f(1.0f, 0.0f);			// 頂点3のテクスチャ座標
		glVertex3f(600.0f, 200.0f, 0.0f);	// 頂点3の画面座標

	}
	glEnd();

	glBegin(GL_LINES);
	{
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);	// 頂点1のカラーセット
		glTexCoord2f(0.0f, 0.0f);			// 頂点1のテクスチャ座標
		glVertex3f(050.0f, 050.0f, 0.0f);	// 頂点1の画面座標

		glColor4f(0.0f, 0.0f, 0.0f, 1.0f);	// 頂点2のカラーセット
		glTexCoord2f(0.0f, -1.0f);			// 頂点2のテクスチャ座標
		glVertex3f(500.0f, 020.0f, 0.0f);	// 頂点2の画面座標

	}
	glEnd();

	glLineWidth(5);

	glBegin(GL_LINE_STRIP);
	{
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);	// 頂点1のカラーセット
		glTexCoord2f(0.0f, 0.0f);			// 頂点1のテクスチャ座標
		glVertex3f(600.0f, 010.0f, 0.0f);	// 頂点1の画面座標

		glColor4f(0.0f, 0.0f, 0.0f, 1.0f);	// 頂点2のカラーセット
		glTexCoord2f(0.0f, -1.0f);			// 頂点2のテクスチャ座標
		glVertex3f(700.0f, 300.0f, 0.0f);	// 頂点2の画面座標

		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);	// 頂点1のカラーセット
		glTexCoord2f(0.0f, 0.0f);			// 頂点1のテクスチャ座標
		glVertex3f(850.0f, 250.0f, 0.0f);	// 頂点1の画面座標

		glColor4f(0.0f, 0.0f, 1.0f, 1.0f);	// 頂点2のカラーセット
		glTexCoord2f(0.0f, -1.0f);			// 頂点2のテクスチャ座標
		glVertex3f(450.0f, 520.0f, 0.0f);	// 頂点2の画面座標

	}
	glEnd();

	glPointSize(20);
	glBegin(GL_POINTS);
	{
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);	// 頂点1のカラーセット
		glTexCoord2f(0.0f, 0.0f);			// 頂点1のテクスチャ座標
		glVertex3f(500.0f, 100.0f, 0.0f);	// 頂点1の画面座標

		glColor4f(0.0f, 1.0f, 0.0f, 1.0f);	// 頂点2のカラーセット
		glTexCoord2f(0.0f, -1.0f);			// 頂点2のテクスチャ座標
		glVertex3f(100.0f, 500.0f, 0.0f);	// 頂点2の画面座標

		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);	// 頂点1のカラーセット
		glTexCoord2f(0.0f, 0.0f);			// 頂点1のテクスチャ座標
		glVertex3f(350.0f, 250.0f, 0.0f);	// 頂点1の画面座標
	}
	glEnd();
	*/




	// ライトオン
	glEnable(GL_LIGHTING);


	CRenderer::OpenGLSet3D();
	//// マトリクスを最初の状態に復帰
	//glMatrixMode(GL_PROJECTION);
	//glPopMatrix();
	//glMatrixMode(GL_MODELVIEW);
	//glPopMatrix();
}
