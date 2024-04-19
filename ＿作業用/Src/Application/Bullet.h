#pragma once


class Scene;	//前方宣言

class C_Bullet
{
public:
	C_Bullet() {};
	~C_Bullet() {};

	void Init();

	void Update();

	void Draw();

	void Shot(Math::Vector2 a_playerPos,int a_playerMode);	//弾を起動する関数(自機座標、モード）
	void Laser(Math::Vector2 a_playerPos);
	//セッター
	void SetTexture(KdTexture* a_pTex) { m_pTex = a_pTex; }			//弾１の画像
	void SetOwner(Scene* a_pOwner) { m_pOwner = a_pOwner; }			//アクセス権限

	//ゲッター
	bool  GetLife() { return m_life; }
private:
	Scene* m_pOwner;		//アクセス権限

	//--テクスチャ--
	KdTexture* m_pTex;		//弾１画像

	//--変数--

	//弾
	Math::Vector2 m_scroll;	//スクロールする値
	Math::Vector2 m_pos;	//座標
	Math::Vector2 m_move;	//移動量
	Math::Vector2 m_rad;	//半径
	Math::Vector2 m_size;	//サイズ
	float m_angle;			//角度
	Math::Vector2 m_scale;	//大きさ
	bool m_life;			//ライフ
	int m_shotMode;
	float m_direction;		//向き
	float m_speed;
	//--マトリックス--

	Math::Matrix m_smat;	//拡大
	Math::Matrix m_rmat;	//回転
	Math::Matrix m_tmat;	//移動
	Math::Matrix m_mat;		//合成

	

};