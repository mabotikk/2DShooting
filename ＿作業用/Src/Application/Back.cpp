#include "Back.h"
#include "Scene.h"

void C_Back::Init()
{
	m_pos = { 0,0 };		//���W
	m_move = { 0,0 };		//�ړ���
	m_scale = { 2.0,2.0 };	//�傫��
	m_size = { 390 ,390 };	//�T�C�Y
	m_rad = { m_size.x / 2 * m_scale.x,m_size.y / 2 * m_scale.y };	//���a
	m_angle = 0;			//�p�x
}

void C_Back::Update()
{
	m_smat = Math::Matrix::CreateScale(1.0f * m_scale.x, 1.0f * m_scale.y, 0);
	m_rmat = Math::Matrix::CreateRotationZ(DegToRad(m_angle));
	m_tmat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0.0f);
	m_mat = m_smat * m_rmat * m_tmat;
}

void C_Back::Draw()
{
	DrawImg(m_mat, m_pTex, { 0,0,(int)m_size.x,(int)m_size.y }, 1.0f);
}
