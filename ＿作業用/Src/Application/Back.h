#pragma once
class Scene;	//�O���錾

class C_Back
{
public:
	C_Back() {};
	~C_Back() {};

	void Init();

	void Update();

	void Draw();

	//�Z�b�^�[
	void SetTexture(KdTexture* a_pTex) { m_pTex = a_pTex; };	//�w�i�P�摜
	void SetOwner(Scene* ap_Owner) { m_pOwner = ap_Owner; }			//�A�N�Z�X����
private:
	Scene* m_pOwner;		//�A�N�Z�X����

	//--�e�N�X�`��--
	KdTexture* m_pTex;	//�w�i�P�摜

	//--�ϐ�--

	//�w�i�P
	Math::Vector2 m_scroll;	//�X�N���[������l
	Math::Vector2 m_pos;	//���W
	Math::Vector2 m_move;	//�ړ���
	Math::Vector2 m_rad;	//���a
	Math::Vector2 m_size;	//�T�C�Y
	float m_angle;			//�p�x
	Math::Vector2 m_scale;	//�傫��

	//--�}�g���b�N�X--

	//�w�i�P
	Math::Matrix m_smat;	//�g��
	Math::Matrix m_rmat;	//��]
	Math::Matrix m_tmat;	//�ړ�
	Math::Matrix m_mat;		//����
};
