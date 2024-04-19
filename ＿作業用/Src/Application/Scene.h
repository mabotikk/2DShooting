#pragma once

#include "utility.h"	// namespace (名前空間)
#include "Player.h"		//プレイヤー
#include "Enemy.h"		//敵
#include "Back.h"		//背景
#include"Bullet.h"		//弾


class Scene
{
private:
	//テクスチャ ・・・ 画像データ
	KdTexture m_playerTex;	//プレイヤー
	KdTexture m_enemy1Tex;	//敵
	KdTexture m_back1Tex;	//背景
	KdTexture m_bulletTex;	//弾

	//配列用関数
	static const int m_bulletNum = 50;

	//オブジェクト宣言
	C_Player m_player;	//プレイヤー
	C_Enemy m_enemy;	//敵
	C_Back m_back;		//背景
	//C_Bullet m_bullet[m_bulletNum];	//弾
	C_Bullet m_bullet;	//弾

	//--変数--
	 
	//シーン変数
	SceneType nowScene;		//現在のシーン
	
	//フレーム
	float frame;

	
	
	

public:

	//キー制御
	bool keyFlg[key_FlgEnd];

	// 初期設定
	void Init();				// 起動時に一度だけ呼び出す初期化
	void InitScene(int obj);	// シーン別初期化用(何回も呼び出す方）
	

	// 解放
	void Release();

	// 更新処理
	void Update();

	//タイトル更新処理
	void UpdateTitle();

	//ゲーム更新処理
	void UpdateGame();

	//リザルト更新処理
	void UpdateReselt();

	// 描画処理
	void Draw2D();

	//タイトル描画処理
	void DrawTitle();

	//ゲーム描画処理
	void DrawGame();

	//リザルト描画処理
	void DrawReselt();

	// GUI処理
	void ImGuiUpdate();



	//ゲッター
	C_Player* GetPlayer() { return &m_player; }
	//C_Bullet* GetBullet() { return &m_bullet[m_bulletNum]; }
	C_Bullet* GetBullet() { return &m_bullet; }
	C_Enemy* GetEnemy() { return &m_enemy; }
	
private:

	Scene() {}

public:
	static Scene& GetInstance()
	{
		static Scene instance;
		return instance;
	}
};

#define SCENE Scene::GetInstance()
