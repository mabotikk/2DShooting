#pragma once


class Scene;	//前方宣言

class C_Player
{
public:
	C_Player() {};
	~C_Player() {};

	void Init();

	void Update();

	void Draw();

	//セッター
	void SetTexture(KdTexture* a_pTex) { m_pTex = a_pTex; }			//プレイヤーの画像
	void SetOwner(Scene* ap_Owner) { m_pOwner = ap_Owner; }			//アクセス権限

	//ゲッター
	int GetMode() { return m_mode; }	//プレイヤーモード
	Math::Vector2 GetScale() { return m_scale; }	//プレイヤーの向き
	Math::Vector2 GetPos() { return m_pos; }	//プレイヤー座標
private:
	Scene* m_pOwner;		//アクセス権限
	
	//--テクスチャ--
	KdTexture *m_pTex;		//プレイヤー画像

	//--変数--
	
	//プレイヤー
	Math::Vector2 m_scroll;	//スクロールする値
	Math::Vector2 m_pos;	//座標
	Math::Vector2 m_move;	//移動量
	Math::Vector2 m_rad;	//半径
	Math::Vector2 m_size;	//サイズ
	float m_angle;			//角度
	Math::Vector2 m_scale;	//大きさ
	int m_mode;			//プレイヤーモード
	int m_life;			//プレイヤーライフ
	float m_timebullet;	//弾の発射間隔
	int m_anime;		//アニメーション用関数
	float m_animeFrame;	//アニメーション切り替え間隔

	//--マトリックス--

	//プレイヤー
	Math::Matrix m_smat;	//拡大
	Math::Matrix m_rmat;	//回転
	Math::Matrix m_tmat;	//移動
	Math::Matrix m_mat;		//合成
	//プレイヤー外枠、影
	Math::Matrix m_smatP2;	//拡大
	Math::Matrix m_rmatP2;	//回転
	Math::Matrix m_tmatP2;	//移動
	Math::Matrix m_matP2;	//合成
};
