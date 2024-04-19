#include "Bullet.h"
#include "Scene.h"
#include "Player.h"

void C_Bullet::Init()
{
	m_pos = { 0,0 };			//���W
	m_move = { 0,0 };			//�ړ���
	m_scale = { 1.0f,1.0f };	//�傫��
	m_size = { 32.32 };			//�T�C�Y
	m_rad = { m_size.x / 2 * m_scale.x,m_size.y / 2 * m_scale.y };	//���a
	m_angle = 0;			//�p�x
	m_life = false;
	m_shotMode = 0;
	m_direction = 0;
	m_speed = 15;
}

void C_Bullet::Update()
{
	

	if (m_life)
	{
		m_move = { 0.0 };	//�e�̈ړ��ʃ��Z�b�g

		
			
		m_move.x += m_direction;
		
		m_pos += m_move;

		if (m_pos.x >= 640|| m_pos.x <= -640)
		{
			m_life = false;
		}

		m_smat = Math::Matrix::CreateScale(1.0f * m_scale.x, 1.0f * m_scale.y, 1.0f);
		m_rmat = Math::Matrix::CreateRotationZ(DegToRad(m_angle));
		m_tmat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0.0f);
		m_mat = m_smat * m_rmat * m_tmat;
	}
	

	
}

void C_Bullet::Draw()
{
	if(m_life)		//���@�������Ă��鎞
	{
		
		switch (m_shotMode)
		{
		case 0:
			DrawImg(m_mat, m_pTex, { (int)m_size.x * m_shotMode,0,(int)m_size.x,(int)m_size.y }, 1.0f);
			break;
		case 1:
			DrawImg(m_mat, m_pTex, { (int)m_size.x * m_shotMode,0,(int)m_size.x,(int)m_size.y }, 1.0f);
			break;
		case 2:
			DrawImg(m_mat, m_pTex, { (int)m_size.x * m_shotMode,0,(int)m_size.x,(int)m_size.y }, 1.0f);
			break;
		}
		
	}
	
}

void C_Bullet::Shot(Math::Vector2 a_playerPos,int a_playerMode)
{
	//�v���C���[�̍��W�擾
	m_pos = a_playerPos;
	m_shotMode = a_playerMode;
	m_life = true;
	C_Player* m_player = m_pOwner->GetPlayer();
	if (m_player->GetScale().x < 0)
	{
		m_direction = m_speed;
	}
	if (m_player->GetScale().x > 0)
	{
		m_direction = -m_speed;
	}
}

void C_Bullet::Laser(Math::Vector2 a_playerPos)
{
	//�v���C���[�̍��W�擾
	m_pos = a_playerPos;
	m_life = true;
}
