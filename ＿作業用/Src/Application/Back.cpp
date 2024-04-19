#include "Back.h"
#include "Scene.h"

void C_Back::Init()
{
	m_pos = { 0,0 };		//座標
	m_move = { 0,0 };		//移動量
	m_scale = { 2.0,2.0 };	//大きさ
	m_size = { 390 ,390 };	//サイズ
	m_rad = { m_size.x / 2 * m_scale.x,m_size.y / 2 * m_scale.y };	//半径
	m_angle = 0;			//角度
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
