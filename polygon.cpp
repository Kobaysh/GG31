#include "main.h"
#include "renderer.h"
#include "polygon.h"
#include "textureGL.h"
#include "vector.h"
#include "renderer.h"
#include <math.h>

// �e�N�X�`���摜�̃t�@�C����
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
	// ���C�g�I�t
	glDisable(GL_LIGHTING);

	CRenderer::OpenGLSet2D();
	// �v���W�F�N�V�����s��->2D�p�̍s�񂪃Z�b�g���ꂽ���
	// ���f���r���[�s��->�P�ʍs�񂪃Z�b�g���ꂽ���
	
	// �e�N�X�`���̃Z�b�g
	glBindTexture(GL_TEXTURE_2D, m_Texture);
	static float rotZ = 0.0f;	// ��]�p�xz
// �\�����W
	static VECTOR3D Position1(SCREEN_WIDTH * 0.25f, SCREEN_HEIGHT * 0.25f, -0);
	// ��]�|���S����\��
	{
		glMatrixMode(GL_MODELVIEW);	// �|���S���`��s��̑���ɐ؂�ւ���
		glPushMatrix();				// ���݂̃��f���r���[�s���ۑ�
		{
			// ���s�ړ��s��
			glTranslatef(Position1.x, Position1.y, Position1.z);	// �X�^�b�N�ɏ�Z
			// ��]�s��
			glRotatef(rotZ, 0, 0, 1.0f);	// ���s�ړ��s��ɏ�Z
			rotZ += 1.1f;

			// �|���S���Z�b�g
			glBegin(GL_TRIANGLE_STRIP);			// ���_�̃Z�b�g�J�n
			{
				glColor4f(1.0f, 0.0f, 0.0f, 1.0f);	// ���_1�̃J���[�Z�b�g
				glTexCoord2f(0.0f, 0.0f);			// ���_1�̃e�N�X�`�����W
				glVertex3f(-100.0f, -100.0f, 0.0f);	// ���_1�̉�ʍ��W

				glColor4f(0.0f, 1.0f, 0.0f, 1.0f);	// ���_2�̃J���[�Z�b�g
				glTexCoord2f(0.0f, -1.0f);			// ���_2�̃e�N�X�`�����W
				glVertex3f(-100.0f, 100.0f, 0.0f);	// ���_2�̉�ʍ��W

				glColor4f(0.0f, 0.0f, 1.0f, 1.0f);	// ���_3�̃J���[�Z�b�g
				glTexCoord2f(1.0f, 0.0f);			// ���_3�̃e�N�X�`�����W
				glVertex3f(100.0f, -100.0f, 0.0f);	// ���_3�̉�ʍ��W

				glColor4f(1.0f, 1.0f, 1.0f, 1.0f);	// ���_4�̃J���[�Z�b�g
				glTexCoord2f(1.0f, -1.0f);			// ���_4�̃e�N�X�`�����W
				glVertex3f(100.0f, 100.0f, 0.0f);	// ���_4�̉�ʍ��W


			}
			glEnd();
		}
		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();		// �s��X�^�b�N�̕��A
	
	}

	{
		glPushMatrix();				// ���݂̃��f���r���[�s���ۑ�
		{
			// ���s�ړ��s��
			glTranslatef(Position1.x * 2, Position1.y * 2, Position1.z * 2);	// �X�^�b�N�ɏ�Z
			// ��]�s��
			glRotatef(rotZ, 0, 0, 1.0f);	// ���s�ړ��s��ɏ�Z
			rotZ += 1.1f;

			// �|���S���Z�b�g
			glBegin(GL_TRIANGLE_STRIP);			// ���_�̃Z�b�g�J�n
			{
				glColor4f(1.0f, 0.0f, 0.0f, 1.0f);	// ���_1�̃J���[�Z�b�g
				glTexCoord2f(0.0f, 0.0f);			// ���_1�̃e�N�X�`�����W
				glVertex3f(-100.0f, -100.0f, 0.0f);	// ���_1�̉�ʍ��W

				glColor4f(0.0f, 1.0f, 0.0f, 1.0f);	// ���_2�̃J���[�Z�b�g
				glTexCoord2f(0.0f, -1.0f);			// ���_2�̃e�N�X�`�����W
				glVertex3f(-100.0f, 100.0f, 0.0f);	// ���_2�̉�ʍ��W

				glColor4f(0.0f, 0.0f, 1.0f, 1.0f);	// ���_3�̃J���[�Z�b�g
				glTexCoord2f(1.0f, 0.0f);			// ���_3�̃e�N�X�`�����W
				glVertex3f(100.0f, -100.0f, 0.0f);	// ���_3�̉�ʍ��W

				glColor4f(1.0f, 1.0f, 1.0f, 1.0f);	// ���_4�̃J���[�Z�b�g
				glTexCoord2f(1.0f, -1.0f);			// ���_4�̃e�N�X�`�����W
				glVertex3f(100.0f, 100.0f, 0.0f);	// ���_4�̉�ʍ��W


			}
			glEnd();
		}
		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();		// �s��X�^�b�N�̕��A
	}

	/*
	// �|���S���̕`��
	glBegin(GL_TRIANGLE_STRIP);			// ���_�̃Z�b�g�J�n
	{
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);	// ���_1�̃J���[�Z�b�g
		glTexCoord2f(0.0f, 0.0f);			// ���_1�̃e�N�X�`�����W
		glVertex3f(100.0f, 100.0f, 0.0f);	// ���_1�̉�ʍ��W

		glColor4f(0.0f, 1.0f, 0.0f, 1.0f);	// ���_2�̃J���[�Z�b�g
		glTexCoord2f(0.0f, -1.0f);			// ���_2�̃e�N�X�`�����W
		glVertex3f(100.0f, 300.0f, 0.0f);	// ���_2�̉�ʍ��W

		glColor4f(0.0f, 0.0f, 1.0f, 1.0f);	// ���_3�̃J���[�Z�b�g
		glTexCoord2f(1.0f, 0.0f);			// ���_3�̃e�N�X�`�����W
		glVertex3f(300.0f, 100.0f, 0.0f);	// ���_3�̉�ʍ��W

		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);	// ���_4�̃J���[�Z�b�g
		glTexCoord2f(1.0f, -1.0f);			// ���_4�̃e�N�X�`�����W
		glVertex3f(300.0f, 300.0f, 0.0f);	// ���_4�̉�ʍ��W


	}
	glEnd();

	glBegin(GL_TRIANGLES);			// ���_�̃Z�b�g�J�n
	{
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);	// ���_1�̃J���[�Z�b�g
		glTexCoord2f(0.0f, 0.0f);			// ���_1�̃e�N�X�`�����W
		glVertex3f(400.0f, 200.0f, 0.0f);	// ���_1�̉�ʍ��W

		glColor4f(0.0f, 1.0f, 0.0f, 1.0f);	// ���_2�̃J���[�Z�b�g
		glTexCoord2f(0.0f, -1.0f);			// ���_2�̃e�N�X�`�����W
		glVertex3f(400.0f, 400.0f, 0.0f);	// ���_2�̉�ʍ��W

		glColor4f(0.0f, 0.0f, 1.0f, 1.0f);	// ���_3�̃J���[�Z�b�g
		glTexCoord2f(1.0f, 0.0f);			// ���_3�̃e�N�X�`�����W
		glVertex3f(600.0f, 200.0f, 0.0f);	// ���_3�̉�ʍ��W

	}
	glEnd();

	glBegin(GL_LINES);
	{
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);	// ���_1�̃J���[�Z�b�g
		glTexCoord2f(0.0f, 0.0f);			// ���_1�̃e�N�X�`�����W
		glVertex3f(050.0f, 050.0f, 0.0f);	// ���_1�̉�ʍ��W

		glColor4f(0.0f, 0.0f, 0.0f, 1.0f);	// ���_2�̃J���[�Z�b�g
		glTexCoord2f(0.0f, -1.0f);			// ���_2�̃e�N�X�`�����W
		glVertex3f(500.0f, 020.0f, 0.0f);	// ���_2�̉�ʍ��W

	}
	glEnd();

	glLineWidth(5);

	glBegin(GL_LINE_STRIP);
	{
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);	// ���_1�̃J���[�Z�b�g
		glTexCoord2f(0.0f, 0.0f);			// ���_1�̃e�N�X�`�����W
		glVertex3f(600.0f, 010.0f, 0.0f);	// ���_1�̉�ʍ��W

		glColor4f(0.0f, 0.0f, 0.0f, 1.0f);	// ���_2�̃J���[�Z�b�g
		glTexCoord2f(0.0f, -1.0f);			// ���_2�̃e�N�X�`�����W
		glVertex3f(700.0f, 300.0f, 0.0f);	// ���_2�̉�ʍ��W

		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);	// ���_1�̃J���[�Z�b�g
		glTexCoord2f(0.0f, 0.0f);			// ���_1�̃e�N�X�`�����W
		glVertex3f(850.0f, 250.0f, 0.0f);	// ���_1�̉�ʍ��W

		glColor4f(0.0f, 0.0f, 1.0f, 1.0f);	// ���_2�̃J���[�Z�b�g
		glTexCoord2f(0.0f, -1.0f);			// ���_2�̃e�N�X�`�����W
		glVertex3f(450.0f, 520.0f, 0.0f);	// ���_2�̉�ʍ��W

	}
	glEnd();

	glPointSize(20);
	glBegin(GL_POINTS);
	{
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);	// ���_1�̃J���[�Z�b�g
		glTexCoord2f(0.0f, 0.0f);			// ���_1�̃e�N�X�`�����W
		glVertex3f(500.0f, 100.0f, 0.0f);	// ���_1�̉�ʍ��W

		glColor4f(0.0f, 1.0f, 0.0f, 1.0f);	// ���_2�̃J���[�Z�b�g
		glTexCoord2f(0.0f, -1.0f);			// ���_2�̃e�N�X�`�����W
		glVertex3f(100.0f, 500.0f, 0.0f);	// ���_2�̉�ʍ��W

		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);	// ���_1�̃J���[�Z�b�g
		glTexCoord2f(0.0f, 0.0f);			// ���_1�̃e�N�X�`�����W
		glVertex3f(350.0f, 250.0f, 0.0f);	// ���_1�̉�ʍ��W
	}
	glEnd();
	*/




	// ���C�g�I��
	glEnable(GL_LIGHTING);


	CRenderer::OpenGLSet3D();
	//// �}�g���N�X���ŏ��̏�Ԃɕ��A
	//glMatrixMode(GL_PROJECTION);
	//glPopMatrix();
	//glMatrixMode(GL_MODELVIEW);
	//glPopMatrix();
}
