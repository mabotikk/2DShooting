#pragma once


class Scene;	//�O���錾

class C_Player
{
public:
	C_Player() {};
	~C_Player() {};

	void Init();

	void Update();

	void Draw();

	//�Z�b�^�[
	void SetTexture(KdTexture* a_pTex) { m_pTex = a_pTex; }			//�v���C���[�̉摜
	void SetOwner(Scene* ap_Owner) { m_pOwner = ap_Owner; }			//�A�N�Z�X����

	//�Q�b�^�[
	int GetMode() { return m_mode; }	//�v���C���[���[�h
	Math::Vector2 GetScale() { return m_scale; }	//�v���C���[�̌���
	Math::Vector2 GetPos() { return m_pos; }	//�v���C���[���W
private:
	Scene* m_pOwner;		//�A�N�Z�X����
	
	//--�e�N�X�`��--
	KdTexture *m_pTex;		//�v���C���[�摜

	//--�ϐ�--
	
	//�v���C���[
	Math::Vector2 m_scroll;	//�X�N���[������l
	Math::Vector2 m_pos;	//���W
	Math::Vector2 m_move;	//�ړ���
	Math::Vector2 m_rad;	//���a
	Math::Vector2 m_size;	//�T�C�Y
	float m_angle;			//�p�x
	Math::Vector2 m_scale;	//�傫��
	int m_mode;			//�v���C���[���[�h
	int m_life;			//�v���C���[���C�t
	float m_timebullet;	//�e�̔��ˊԊu
	int m_anime;		//�A�j���[�V�����p�֐�
	float m_animeFrame;	//�A�j���[�V�����؂�ւ��Ԋu

	//--�}�g���b�N�X--

	//�v���C���[
	Math::Matrix m_smat;	//�g��
	Math::Matrix m_rmat;	//��]
	Math::Matrix m_tmat;	//�ړ�
	Math::Matrix m_mat;		//����
	//�v���C���[�O�g�A�e
	Math::Matrix m_smatP2;	//�g��
	Math::Matrix m_rmatP2;	//��]
	Math::Matrix m_tmatP2;	//�ړ�
	Math::Matrix m_matP2;	//����
};
