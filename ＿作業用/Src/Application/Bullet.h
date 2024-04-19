#pragma once


class Scene;	//�O���錾

class C_Bullet
{
public:
	C_Bullet() {};
	~C_Bullet() {};

	void Init();

	void Update();

	void Draw();

	void Shot(Math::Vector2 a_playerPos,int a_playerMode);	//�e���N������֐�(���@���W�A���[�h�j
	void Laser(Math::Vector2 a_playerPos);
	//�Z�b�^�[
	void SetTexture(KdTexture* a_pTex) { m_pTex = a_pTex; }			//�e�P�̉摜
	void SetOwner(Scene* a_pOwner) { m_pOwner = a_pOwner; }			//�A�N�Z�X����

	//�Q�b�^�[
	bool  GetLife() { return m_life; }
private:
	Scene* m_pOwner;		//�A�N�Z�X����

	//--�e�N�X�`��--
	KdTexture* m_pTex;		//�e�P�摜

	//--�ϐ�--

	//�e
	Math::Vector2 m_scroll;	//�X�N���[������l
	Math::Vector2 m_pos;	//���W
	Math::Vector2 m_move;	//�ړ���
	Math::Vector2 m_rad;	//���a
	Math::Vector2 m_size;	//�T�C�Y
	float m_angle;			//�p�x
	Math::Vector2 m_scale;	//�傫��
	bool m_life;			//���C�t
	int m_shotMode;
	float m_direction;		//����
	float m_speed;
	//--�}�g���b�N�X--

	Math::Matrix m_smat;	//�g��
	Math::Matrix m_rmat;	//��]
	Math::Matrix m_tmat;	//�ړ�
	Math::Matrix m_mat;		//����

	

};