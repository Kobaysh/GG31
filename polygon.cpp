#include "main.h"
#include "renderer.h"
#include "polygon.h"
#include "textureGL.h"
//#include "vector.h"
#include "model.h"
#include "renderer.h"
#include <math.h>

#define PYRAMID_NUM 9

CModel Cube;

// テクスチャ画像のファイル名
char FileName[] = { "asset\\texture\\texture.tga" };
char ModelName[] = { "asset\\model\\sphere.obj" };

VECTOR3D Positions[PYRAMID_NUM];

CPolygon::CPolygon()
{
}

CPolygon::~CPolygon()
{
}

 void CPolygon::Init()
{
	 m_Texture = LoadTexture(FileName);
	 Cube.Load(ModelName);
	 /*float pos[] = {
		 0.0f,-1.0f,
		 -1.0f,0.0f,0.0f,0.0f,1.0f,0.0f,
		 -2.0f,1.0f, -1.0f,1.0f, 0.0f,1.0f, 1.0f,1.0f, 2.0f,1.0f
	 };
	 for (int i = 0; i < PYRAMID_NUM; i++) {
		 Positions[i].x = pos[i * 2];
		 Positions[i].y = pos[i * 2 + 1];
		 Positions[i].z = 0.0f;
	 }*/
}

 void CPolygon::Uninit()
{
	 UnloadTexture(m_Texture);
	 Cube.Unload();
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
	 const int n = PYRAMID_NUM;
	 static float rotZ = 0.0f;	// 回転角度z
	 // 表示座標
	 static VECTOR3D Position1(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, -0);


	 VECTOR3D PositionPyramid;

	 // 2dポリゴン表示
	 // 回転ポリゴンを表示
	 //for (int i = 0; i < n; i++)
	 //{
	 //	glMatrixMode(GL_MODELVIEW);	// ポリゴン描画行列の操作に切り替える
	 //	glPushMatrix();				// 現在のモデルビュー行列を保存
	 //	{
	 //		// ピラミッド位置
	 //		glTranslatef(Position1.x, Position1.y, Position1.z);
	 //		glRotatef(rotZ, 0, 0, 1.0f);	// 平行移動行列に乗算
	 //		rotZ += 0.1f;
	 //	//	glScalef(1.0f, 1.0f, 1.0f);
	 //		// 平行移動行列
	 //		glTranslatef(Positions[i].x, Positions[i].y, Positions[i].z);	// スタックに乗算
	 //		// 回転行列
	 //	

	 //		// ポリゴンセット
	 //		glBegin(GL_TRIANGLE_STRIP);			// 頂点のセット開始
	 //		{
	 //			glColor4f(1.0f, 0.0f, 0.0f, 1.0f);	// 頂点1のカラーセット
	 //			glTexCoord2f(0.0f, 0.0f);			// 頂点1のテクスチャ座標
	 //			glVertex3f(-50.0f, -50.0f, 0.0f);	// 頂点1の画面座標

	 //			glColor4f(0.0f, 1.0f, 0.0f, 1.0f);	// 頂点2のカラーセット
	 //			glTexCoord2f(0.0f, -1.0f);			// 頂点2のテクスチャ座標
	 //			glVertex3f(-50.0f, 50.0f, 0.0f);	// 頂点2の画面座標

	 //			glColor4f(0.0f, 0.0f, 1.0f, 1.0f);	// 頂点3のカラーセット
	 //			glTexCoord2f(1.0f, 0.0f);			// 頂点3のテクスチャ座標
	 //			glVertex3f(50.0f, -50.0f, 0.0f);	// 頂点3の画面座標

	 //			glColor4f(1.0f, 1.0f, 1.0f, 1.0f);	// 頂点4のカラーセット
	 //			glTexCoord2f(1.0f, -1.0f);			// 頂点4のテクスチャ座標
	 //			glVertex3f(50.0f, 50.0f, 0.0f);	// 頂点4の画面座標


	 //		}
	 //		glEnd();
	 //	}
	 //	glMatrixMode(GL_MODELVIEW);
	 //	glPopMatrix();		// 行列スタックの復帰
	 //
	 //}



	 // 3D設定
	 CRenderer::OpenGLSet3D();
	 // カメラの作成->モデルビュー行列に乗算
	 gluLookAt(
		 0.0, 0.0, 10.0,	// カメラ座標
		 0.0, 0.0, 0.0,	// 注視点
		 0.0, 1.0, 0.0);	// カメラの上方向
	 
	 /*for (int i = 0; i < n; i++)
	 {
		 glMatrixMode(GL_MODELVIEW);	// ポリゴン描画行列の操作に切り替える
		 glPushMatrix();				// 現在のモデルビュー行列を保存
		 glTranslatef(Position2.x, Position2.y, Position2.z);
		 glRotatef(rotZ2, 0.4f, 1.0f, 0.5f);
		 rotZ2 += 0.4f;
		 glScalef(1.0f, 1.0f, 1.0f);
		 // 平行移動行列
		 glTranslatef(Positions[i].x, Positions[i].y, Positions[i].z);	// スタックに乗算
		 glMatrixMode(GL_MODELVIEW);
		 glPushMatrix();
		 {
			 glScalef(0.5f, 0.5f, 0.5f);

			 glBegin(GL_TRIANGLE_STRIP); // ue
			 {// 上
				 glColor4f(1.0f, 0.0f, 0.0f, 1.0f);	// 頂点1のカラーセット
				 glTexCoord2f(0, 0);			// 頂点1のテクスチャ座標
				 glVertex3f(-1, 1, -1);	// 頂点1の画面座標

				 glColor4f(0.0f, 1.0f, 0.0f, 1.0f);	// 頂点2のカラーセット
				 glTexCoord2f(0, -1);			// 頂点2のテクスチャ座標
				 glVertex3f(-1, 1, 1);	// 頂点2の画面座標

				 glColor4f(0.0f, 0.0f, 1.0f, 1.0f);	// 頂点3のカラーセット
				 glTexCoord2f(1, 0);			// 頂点3のテクスチャ座標
				 glVertex3f(1, 1, -1);	// 頂点3の画面座標

				 glColor4f(1.0f, 1.0f, 1.0f, 1.0f);	// 頂点4のカラーセット
				 glTexCoord2f(1, -1);			// 頂点4のテクスチャ座標
				 glVertex3f(1, 1, 1);	// 頂点4の画面座標
			 }
			 glEnd();

			 glBegin(GL_TRIANGLE_STRIP); // shita
			 {// 下
				 glColor4f(1.0f, 0.0f, 0.0f, 1.0f);	// 頂点1のカラーセット
				 glTexCoord2f(0, 0);			// 頂点1のテクスチャ座標
				 glVertex3f(-1, -1, 1);	// 頂点1の画面座標

				 glColor4f(0.0f, 1.0f, 0.0f, 1.0f);	// 頂点2のカラーセット
				 glTexCoord2f(0, -1);			// 頂点2のテクスチャ座標
				 glVertex3f(-1, -1, -1);	// 頂点2の画面座標

				 glColor4f(0.0f, 0.0f, 1.0f, 1.0f);	// 頂点3のカラーセット
				 glTexCoord2f(1, 0);			// 頂点3のテクスチャ座標
				 glVertex3f(1, -1, 1);	// 頂点3の画面座標

				 glColor4f(1.0f, 1.0f, 1.0f, 1.0f);	// 頂点4のカラーセット
				 glTexCoord2f(1, -1);			// 頂点4のテクスチャ座標
				 glVertex3f(1, -1, -1);	// 頂点4の画面座標
			 }
			 glEnd();

			 glBegin(GL_TRIANGLE_STRIP); // shomen
			 {
				 glColor4f(1.0f, 0.0f, 0.0f, 1.0f);	// 頂点1のカラーセット
				 glTexCoord2f(0, 0);			// 頂点1のテクスチャ座標
				 glVertex3f(-1, 1, 1);	// 頂点1の画面座標

				 glColor4f(0.0f, 1.0f, 0.0f, 1.0f);	// 頂点2のカラーセット
				 glTexCoord2f(0, -1);			// 頂点2のテクスチャ座標
				 glVertex3f(-1, -1, 1);	// 頂点2の画面座標

				 glColor4f(0.0f, 0.0f, 1.0f, 1.0f);	// 頂点3のカラーセット
				 glTexCoord2f(1, 0);			// 頂点3のテクスチャ座標
				 glVertex3f(1, 1, 1);	// 頂点3の画面座標

				 glColor4f(1.0f, 1.0f, 1.0f, 1.0f);	// 頂点4のカラーセット
				 glTexCoord2f(1, -1);			// 頂点4のテクスチャ座標
				 glVertex3f(1, -1, 1);	// 頂点4の画面座標
			 }
			 glEnd();

			 glBegin(GL_TRIANGLE_STRIP); // ushiro
			 {// ushiro
				 glColor4f(1.0f, 0.0f, 0.0f, 1.0f);	// 頂点1のカラーセット
				 glTexCoord2f(0, 0);			// 頂点1のテクスチャ座標
				 glVertex3f(1, 1, -1);	// 頂点1の画面座標

				 glColor4f(0.0f, 1.0f, 0.0f, 1.0f);	// 頂点2のカラーセット
				 glTexCoord2f(0, -1);			// 頂点2のテクスチャ座標
				 glVertex3f(1, -1, -1);	// 頂点2の画面座標

				 glColor4f(0.0f, 0.0f, 1.0f, 1.0f);	// 頂点3のカラーセット
				 glTexCoord2f(1, 0);			// 頂点3のテクスチャ座標
				 glVertex3f(-1, 1, -1);	// 頂点3の画面座標

				 glColor4f(1.0f, 1.0f, 1.0f, 1.0f);	// 頂点4のカラーセット
				 glTexCoord2f(1, -1);			// 頂点4のテクスチャ座標
				 glVertex3f(-1, -1, -1);	// 頂点4の画面座標
			 }
			 glEnd();

			 glBegin(GL_TRIANGLE_STRIP); // migi
			 {// migi
				 glColor4f(1.0f, 0.0f, 0.0f, 1.0f);	// 頂点1のカラーセット
				 glTexCoord2f(0, 0);			// 頂点1のテクスチャ座標
				 glVertex3f(1, 1, 1);	// 頂点1の画面座標

				 glColor4f(0.0f, 1.0f, 0.0f, 1.0f);	// 頂点2のカラーセット
				 glTexCoord2f(0, -1);			// 頂点2のテクスチャ座標
				 glVertex3f(1, -1, 1);	// 頂点2の画面座標

				 glColor4f(0.0f, 0.0f, 1.0f, 1.0f);	// 頂点3のカラーセット
				 glTexCoord2f(1, 0);			// 頂点3のテクスチャ座標
				 glVertex3f(1, 1, -1);	// 頂点3の画面座標

				 glColor4f(1.0f, 1.0f, 1.0f, 1.0f);	// 頂点4のカラーセット
				 glTexCoord2f(1, -1);			// 頂点4のテクスチャ座標
				 glVertex3f(1, -1, -1);	// 頂点4の画面座標
			 }
			 glEnd();

			 glBegin(GL_TRIANGLE_STRIP); // hidari
			 {// hidari
				 glColor4f(1.0f, 0.0f, 0.0f, 1.0f);	// 頂点1のカラーセット
				 glTexCoord2f(0, 0);			// 頂点1のテクスチャ座標
				 glVertex3f(-1, 1, -1);	// 頂点1の画面座標

				 glColor4f(0.0f, 1.0f, 0.0f, 1.0f);	// 頂点2のカラーセット
				 glTexCoord2f(0, -1);			// 頂点2のテクスチャ座標
				 glVertex3f(-1, -1, -1);	// 頂点2の画面座標

				 glColor4f(0.0f, 0.0f, 1.0f, 1.0f);	// 頂点3のカラーセット
				 glTexCoord2f(1, 0);			// 頂点3のテクスチャ座標
				 glVertex3f(-1, 1, 1);	// 頂点3の画面座標

				 glColor4f(1.0f, 1.0f, 1.0f, 1.0f);	// 頂点4のカラーセット
				 glTexCoord2f(1, -1);			// 頂点4のテクスチャ座標
				 glVertex3f(-1, -1, 1);	// 頂点4の画面座標
			 }
			 glEnd();

		 }

		 glMatrixMode(GL_MODELVIEW);
		 glPopMatrix();

	 }*/
	 {
	 static float rotZ2 = 0.0f;
	 static VECTOR3D Position2(0.0f, 0.0f, 0.0f);
	 glPushMatrix();
	 float rad = (rotZ2 + 1 * 72.0f);
		 Cube.Draw();
	 }
	// ライトオン
	glEnable(GL_LIGHTING);


	//// マトリクスを最初の状態に復帰
	//glMatrixMode(GL_PROJECTION);
	//glPopMatrix();
	//glMatrixMode(GL_MODELVIEW);
	//glPopMatrix();
}
