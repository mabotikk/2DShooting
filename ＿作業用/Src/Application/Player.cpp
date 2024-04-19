#include "Player.h"
#include "Scene.h"
//#include"Bullet.h"

void C_Player::Init()
{
	m_pos = { 0,0 };		//座標
	m_move = { 0,0 };		//移動量
	m_scale = { -1,1 };	//拡大
	m_size = { 64,64 };		//サイズ
	m_rad = { m_size.x / 2 * m_scale.x,m_size.y / 2 * m_scale.y };	//半径
	m_angle = 0;			//角度
	m_mode = 0;			//プレイヤーのモード
	m_life = true;			//プレイヤーのライフ
	m_timebullet = 0;		//発射間隔
	m_anime = 0;
	m_animeFrame=0;
}

void C_Player::Update()
{
	if (m_life)		//プレイヤーが生きているなら
	{
		m_timebullet++;	//マイフレ、インクリメント
		m_animeFrame++;	//アニメーション
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
		//WASDで上下左右移動
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


		//Eで自機のモードを変えれる。
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
		//スペースで弾発射
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			C_Bullet* m_bullet = m_pOwner->GetBullet();
			if (m_timebullet >= 50)
			{
				if (m_bullet->GetLife() == false)		//弾がfalseなら発射
				{
					m_timebullet = 0;
					m_bullet->Shot(m_pos, m_mode);		//プレイヤーの座標とモードをわたす
				}
			}
		}

		m_pos += m_move;			//プレイヤーの移動量の合成

		//移動制限
		if (m_pos.x >= 640 - m_rad.x)m_pos.x = 640 - m_rad.x;
		if (m_pos.x <= -640 + m_rad.x)m_pos.x = -640 + m_rad.x;
		if (m_pos.y >= 360 - m_rad.y)m_pos.y = 360 - m_rad.y;
		if (m_pos.y <= -360 + m_rad.y)m_pos.y = -360 + m_rad.y;


		//マトリックス合成
		//プレイヤー
		m_smat = Math::Matrix::CreateScale(1.0f * m_scale.x, 1.0f * m_scale.y, 1.0f);
		m_rmat = Math::Matrix::CreateRotationZ(DegToRad(m_angle));
		m_tmat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0.0f);
		m_mat = m_smat * m_rmat * m_tmat;	
		//プレイヤーの外枠
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
		//モードで色変え（0：赤、1：青、2：緑）
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
