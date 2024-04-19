#pragma once

class Scene;	//前方宣言

class C_Enemy
{
public:
	C_Enemy() {};
	~C_Enemy() {};

	void Init();

	void Update();

	void Draw();

	//セッター
	void SetTexture(KdTexture * a_pTex) { m_pTex = a_pTex; };	//敵１画像
	void SetOwner(Scene* ap_Owner) { m_pOwner = ap_Owner; }			//アクセス権限
private:
	Scene* m_pOwner;		//アクセス権限

	//--テクスチャ--
	KdTexture* m_pTex;		//敵１画像

	//--変数--

	//敵１
	Math::Vector2 m_scroll;	//スクロールする値
	Math::Vector2 m_pos;	//座標
	Math::Vector2 m_move;	//移動量
	Math::Vector2 m_rad;	//半径
	Math::Vector2 m_size;	//サイズ
	float m_angle;			//角度
	Math::Vector2 m_scale;	//大きさ

	//--マトリックス--

	//敵１
	Math::Matrix m_smat;	//拡大
	Math::Matrix m_rmat;	//回転
	Math::Matrix m_tmat;	//移動
	Math::Matrix m_mat;		//合成
};