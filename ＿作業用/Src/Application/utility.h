#pragma once

using namespace std;

//�V�[�����
enum SceneType
{
	Title,	//0�^�C�g��
	Game,	//1�Q�[���{��
	Reselt	//2���U���g
};

enum	// �L�[�t���O�p
{
	key_T,
	key_E,
	key_W,
	key_A,
	key_B,
	key_S,
	key_D,
	key_P,
	key_Q,
	key_G,
	key_Z,
	key_F,
	key_UP,
	key_DOWN,
	key_LEFT,
	key_RIGHT,
	key_SPACE,
	key_RETURN,
	key_BackSpace,
	key_Tab,
	key_SHIFT,
	key_0,
	key_1,
	key_2,
	key_3,
	key_4,
	key_5,
	key_6,
	key_7,
	key_8,
	key_9,
	key_LMB,
	key_RMB,

	key_FlgEnd
};


// ==== ����̕`��n�֐� =============================

// �P�s�ŉ摜�`��錾 ( �s��, �e�N�X�`��, �؂���͈�, �A���t�@�l)
void DrawImg(Math::Matrix a_mat, KdTexture* a_tex, Math::Rectangle a_rect, float a_alpha);

// �P�s�ŐF�t���摜�`�� (�s��, �e�N�X�`��, �؂���͈�, �F)
void DrawImgEX(Math::Matrix a_mat, KdTexture* a_tex, Math::Rectangle a_rect, Math::Color a_color);

//�Z�`��
void DrawMaru(float x, float y, float rad, Math::Color* color, bool nuri);

//���`��
void DrawSankaku(float x1, float y1, float x2, float y2, float x3, float y3, Math::Color* color, bool nuri);

//���`��
void DrawHako(float x, float y, float xs, float ys, Math::Color* color, bool nuri);

//���`��
void DrawSen(float x, float y, float xx, float yy, Math::Color* color);

//�_�`��
void DrawTen(float x, float y, Math::Color* color);

//�����`��@����(X, Y, ����, �F(R,G,B,A), �e��t���邩�ǂ���)
void DrawMoji(float x, float y, char* p_str, Math::Color* color, bool Shadow, float SAlpha);

// ���������W�A���ɕϊ��i�錾�j
float DegToRad(float a_deg);

// �����擾
float Rnd();

// �L�[��Ԏ擾
bool GetKey(int key);

// bool�^��int�^�ɂ�����(false��0�Atrue��1)
int BoolToInt(bool a);

// �������v�Z���ĕԂ�
float GetDist(Math::Vector2 Apos, Math::Vector2 Bpos);

// A��B�̊p�x���v�Z���ĕԂ�
float GetRadian(Math::Vector2 Apos, Math::Vector2 Bpos);

Math::Matrix CreateScale(float a, float b, float c);