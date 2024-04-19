#pragma once

class Scene;	//�O���錾

class C_Enemy
{
public:
	C_Enemy() {};
	~C_Enemy() {};

	void Init();

	void Update();

	void Draw();

	//�Z�b�^�[
	void SetTexture(KdTexture * a_pTex) { m_pTex = a_pTex; };	//�G�P�摜
	void SetOwner(Scene* ap_Owner) { m_pOwner = ap_Owner; }			//�A�N�Z�X����
private:
	Scene* m_pOwner;		//�A�N�Z�X����

	//--�e�N�X�`��--
	KdTexture* m_pTex;		//�G�P�摜

	//--�ϐ�--

	//�G�P
	Math::Vector2 m_scroll;	//�X�N���[������l
	Math::Vector2 m_pos;	//���W
	Math::Vector2 m_move;	//�ړ���
	Math::Vector2 m_rad;	//���a
	Math::Vector2 m_size;	//�T�C�Y
	float m_angle;			//�p�x
	Math::Vector2 m_scale;	//�傫��

	//--�}�g���b�N�X--

	//�G�P
	Math::Matrix m_smat;	//�g��
	Math::Matrix m_rmat;	//��]
	Math::Matrix m_tmat;	//�ړ�
	Math::Matrix m_mat;		//����
};