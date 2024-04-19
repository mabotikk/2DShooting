#pragma once

#include "utility.h"	// namespace (���O���)
#include "Player.h"		//�v���C���[
#include "Enemy.h"		//�G
#include "Back.h"		//�w�i
#include"Bullet.h"		//�e


class Scene
{
private:
	//�e�N�X�`�� �E�E�E �摜�f�[�^
	KdTexture m_playerTex;	//�v���C���[
	KdTexture m_enemy1Tex;	//�G
	KdTexture m_back1Tex;	//�w�i
	KdTexture m_bulletTex;	//�e

	//�z��p�֐�
	static const int m_bulletNum = 50;

	//�I�u�W�F�N�g�錾
	C_Player m_player;	//�v���C���[
	C_Enemy m_enemy;	//�G
	C_Back m_back;		//�w�i
	//C_Bullet m_bullet[m_bulletNum];	//�e
	C_Bullet m_bullet;	//�e

	//--�ϐ�--
	 
	//�V�[���ϐ�
	SceneType nowScene;		//���݂̃V�[��
	
	//�t���[��
	float frame;

	
	
	

public:

	//�L�[����
	bool keyFlg[key_FlgEnd];

	// �����ݒ�
	void Init();				// �N�����Ɉ�x�����Ăяo��������
	void InitScene(int obj);	// �V�[���ʏ������p(������Ăяo�����j
	

	// ���
	void Release();

	// �X�V����
	void Update();

	//�^�C�g���X�V����
	void UpdateTitle();

	//�Q�[���X�V����
	void UpdateGame();

	//���U���g�X�V����
	void UpdateReselt();

	// �`�揈��
	void Draw2D();

	//�^�C�g���`�揈��
	void DrawTitle();

	//�Q�[���`�揈��
	void DrawGame();

	//���U���g�`�揈��
	void DrawReselt();

	// GUI����
	void ImGuiUpdate();



	//�Q�b�^�[
	C_Player* GetPlayer() { return &m_player; }
	//C_Bullet* GetBullet() { return &m_bullet[m_bulletNum]; }
	C_Bullet* GetBullet() { return &m_bullet; }
	C_Enemy* GetEnemy() { return &m_enemy; }
	
private:

	Scene() {}

public:
	static Scene& GetInstance()
	{
		static Scene instance;
		return instance;
	}
};

#define SCENE Scene::GetInstance()
