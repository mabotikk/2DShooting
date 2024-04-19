#include "Player.h"
#include "Scene.h"
//#include"Bullet.h"

void C_Player::Init()
{
	m_pos = { 0,0 };		//���W
	m_move = { 0,0 };		//�ړ���
	m_scale = { -1,1 };	//�g��
	m_size = { 64,64 };		//�T�C�Y
	m_rad = { m_size.x / 2 * m_scale.x,m_size.y / 2 * m_scale.y };	//���a
	m_angle = 0;			//�p�x
	m_mode = 0;			//�v���C���[�̃��[�h
	m_life = true;			//�v���C���[�̃��C�t
	m_timebullet = 0;		//���ˊԊu
	m_anime = 0;
	m_animeFrame=0;
}

void C_Player::Update()
{
	if (m_life)		//�v���C���[�������Ă���Ȃ�
	{
		m_timebullet++;	//�}�C�t���A�C���N�������g
		m_animeFrame++;	//�A�j���[�V����
		if (m_animeFrame > 15)
		{
			m_animeFrame = 0;
			//m_anime++;
			if (m_anime > 1)
			{
				m_anime = 0;
			}
			else
			{
				m_anime++;
			}
		}

		m_move = { 0,0 };
		//WASD�ŏ㉺���E�ړ�
		if (GetAsyncKeyState('D') & 0x8000)
		{
			m_scale.x = -1;
			m_move.x += 10;
		}
		if (GetAsyncKeyState('A') & 0x8000)
		{
			m_scale.x = 1;
			m_move.x -= 10;
		}
		if (GetAsyncKeyState('W') & 0x8000)m_move.y += 10;
		if (GetAsyncKeyState('S') & 0x8000)m_move.y -= 10;


		//E�Ŏ��@�̃��[�h��ς����B
		if (GetAsyncKeyState('E') & 0x8000)
		{
			if (!m_pOwner->keyFlg[key_RMB])
			{
				m_pOwner->keyFlg[key_RMB] = true;
				switch (m_mode)
				{
				case 0:
					m_mode = 1;
					break;
				case 1:
					m_mode = 2;
					break;
				case 2:
					m_mode = 0;
					break;
				default:
					break;
				}
				
			}
		}
		else
		{
			m_pOwner->keyFlg[key_RMB] = false;
		}
		//�X�y�[�X�Œe����
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			C_Bullet* m_bullet = m_pOwner->GetBullet();
			if (m_timebullet >= 50)
			{
				if (m_bullet->GetLife() == false)		//�e��false�Ȃ甭��
				{
					m_timebullet = 0;
					m_bullet->Shot(m_pos, m_mode);		//�v���C���[�̍��W�ƃ��[�h���킽��
				}
			}
		}

		m_pos += m_move;			//�v���C���[�̈ړ��ʂ̍���

		//�ړ�����
		if (m_pos.x >= 640 - m_rad.x)m_pos.x = 640 - m_rad.x;
		if (m_pos.x <= -640 + m_rad.x)m_pos.x = -640 + m_rad.x;
		if (m_pos.y >= 360 - m_rad.y)m_pos.y = 360 - m_rad.y;
		if (m_pos.y <= -360 + m_rad.y)m_pos.y = -360 + m_rad.y;


		//�}�g���b�N�X����
		//�v���C���[
		m_smat = Math::Matrix::CreateScale(1.0f * m_scale.x, 1.0f * m_scale.y, 1.0f);
		m_rmat = Math::Matrix::CreateRotationZ(DegToRad(m_angle));
		m_tmat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0.0f);
		m_mat = m_smat * m_rmat * m_tmat;	
		//�v���C���[�̊O�g
		m_smatP2 = Math::Matrix::CreateScale(1.2f * m_scale.x, 1.2f * m_scale.y, 1.0f);
		m_rmatP2 = Math::Matrix::CreateRotationZ(DegToRad(m_angle));
		m_tmatP2 = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0.0f);
		m_matP2 = m_smatP2 * m_rmatP2 * m_tmatP2;
	}
}

void C_Player::Draw()
{
	if (m_life)
	{
		//���[�h�ŐF�ς��i0�F�ԁA1�F�A2�F�΁j
		switch (m_mode)
		{
		case 0:
			DrawImg(m_mat, m_pTex, { (int)m_size.x * m_anime ,0,(int)m_size.x ,(int)m_size.y }, 1.0f);

			break;
		case 1:
			DrawImg(m_mat, m_pTex, { (int)m_size.x * m_mode,0,(int)m_size.x,(int)m_size.y }, 1.0f);
			break;
		case 2:
			DrawImg(m_mat, m_pTex, { (int)m_size.x * m_mode,0,(int)m_size.x,(int)m_size.y }, 1.0f);
			break;
		default:
			break;
		}
	}
	
}
