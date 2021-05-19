#include "main.h"
#include "renderer.h"
#include "polygon.h"
#include "textureGL.h"
#include "vector.h"
#include "renderer.h"
#include <math.h>

#define PYRAMID_NUM 9

// �e�N�X�`���摜�̃t�@�C����
char FileName[] = { "asset/texture/texture.tga" };

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
	 float pos[] = {
		 0.0f,-100.0f,
		 -100.0f,0.0f,0.0f,0.0f,100.0f,0.0f,
		 -200.0f,100.0f, -100.0f,100.0f, 0.0f,100.0f, 100.0f,100.0f, 200.0f,100.0f
	 };
	 for (int i = 0; i < PYRAMID_NUM; i++) {
		 Positions[i].x = pos[i * 2];
		 Positions[i].y = pos[i * 2 + 1];
		 Positions[i].z = 0.0f;
	 }
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
	// ���C�g�I�t
	glDisable(GL_LIGHTING);

	CRenderer::OpenGLSet2D();
	// �v���W�F�N�V�����s��->2D�p�̍s�񂪃Z�b�g���ꂽ���
	// ���f���r���[�s��->�P�ʍs�񂪃Z�b�g���ꂽ���
	
	// �e�N�X�`���̃Z�b�g
	glBindTexture(GL_TEXTURE_2D, m_Texture);
	const int n = PYRAMID_NUM;
	static float rotZ = 0.0f;	// ��]�p�xz
	// �\�����W
	static VECTOR3D Position1(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, -0);
	

	VECTOR3D PositionPyramid;
	
	// ��]�|���S����\��
	for (int i = 0; i < n; i++)
	{
		glMatrixMode(GL_MODELVIEW);	// �|���S���`��s��̑���ɐ؂�ւ���
		glPushMatrix();				// ���݂̃��f���r���[�s���ۑ�
		{
			// �s���~�b�h�ʒu
			glTranslatef(Position1.x, Position1.y, Position1.z);
			
		//	glScalef(1.0f, 1.0f, 1.0f);
			// ���s�ړ��s��
			glTranslatef(Positions[i].x, Positions[i].y, Positions[i].z);	// �X�^�b�N�ɏ�Z
			// ��]�s��
		//	glRotatef(rotZ, 0, 0, 1.0f);	// ���s�ړ��s��ɏ�Z
		//	rotZ += 0.1f;

			// �|���S���Z�b�g
			glBegin(GL_TRIANGLE_STRIP);			// ���_�̃Z�b�g�J�n
			{
				glColor4f(1.0f, 0.0f, 0.0f, 1.0f);	// ���_1�̃J���[�Z�b�g
				glTexCoord2f(0.0f, 0.0f);			// ���_1�̃e�N�X�`�����W
				glVertex3f(-50.0f, -50.0f, 0.0f);	// ���_1�̉�ʍ��W

				glColor4f(0.0f, 1.0f, 0.0f, 1.0f);	// ���_2�̃J���[�Z�b�g
				glTexCoord2f(0.0f, -1.0f);			// ���_2�̃e�N�X�`�����W
				glVertex3f(-50.0f, 50.0f, 0.0f);	// ���_2�̉�ʍ��W

				glColor4f(0.0f, 0.0f, 1.0f, 1.0f);	// ���_3�̃J���[�Z�b�g
				glTexCoord2f(1.0f, 0.0f);			// ���_3�̃e�N�X�`�����W
				glVertex3f(50.0f, -50.0f, 0.0f);	// ���_3�̉�ʍ��W

				glColor4f(1.0f, 1.0f, 1.0f, 1.0f);	// ���_4�̃J���[�Z�b�g
				glTexCoord2f(1.0f, -1.0f);			// ���_4�̃e�N�X�`�����W
				glVertex3f(50.0f, 50.0f, 0.0f);	// ���_4�̉�ʍ��W


			}
			glEnd();
		}
		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();		// �s��X�^�b�N�̕��A
	
	}

	// ���C�g�I��
	glEnable(GL_LIGHTING);


	CRenderer::OpenGLSet3D();
	//// �}�g���N�X���ŏ��̏�Ԃɕ��A
	//glMatrixMode(GL_PROJECTION);
	//glPopMatrix();
	//glMatrixMode(GL_MODELVIEW);
	//glPopMatrix();
}
