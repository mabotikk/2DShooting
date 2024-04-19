#include "main.h"
#include "Scene.h"

void Scene::Draw2D()
{
	// 文字列表示
	//SHADER.m_spriteShader.DrawString(0, 0, "Hello World", Math::Vector4(1, 1, 0, 1));
	switch (nowScene)
	{
	case Title:
		
		DrawTitle();
		break;
	case Game:
		DrawGame();
		break;
	case Reselt:
		DrawReselt();
		break;
	default:
		break;
	}

}

void Scene::Update()
{
	switch (nowScene)
	{
	case Title:
		
		UpdateTitle();
		break;

	case Game:
		UpdateGame();
		break;

	case Reselt:
		UpdateReselt();
		break;

	default:
		break;
	}
	

}


void Scene::Init()
{
	//フレーム
	frame = 0;
	// キーフラグ初期化
	for (int i = 0; i < key_FlgEnd; i++)
	{
		keyFlg[i] = false;
	}

	// 画像の読み込み処理
	m_playerTex.Load("Data/Texture/Player/playerTensi.png");	//プレイヤー
	m_enemy1Tex.Load("Data/Texture/Enemy/kokyu.png");	//敵
	m_back1Tex.Load("Data/Texture/Back/show.png");		//背景
	m_bulletTex.Load("Data/Texture/Bullet/bulletAll_siro.png");//弾
	//画像のセッター
	m_player.SetTexture(&m_playerTex);	//プレイヤー
	m_player.SetOwner(this);	//プレイヤー
	m_enemy.SetTexture(&m_enemy1Tex);	//敵
	m_enemy.SetOwner(this);		//敵
	m_back.SetTexture(&m_back1Tex);		//背景
	m_back.SetOwner(this);		//背景
	//for (int i=0; m_bulletNum > i; i++)
	//{
	//	m_bullet[i].SetTexture(&m_bulletTex);	//弾
	//	m_bullet[i].SetOwner(this);	//弾
	//}
	
	m_bullet.SetTexture(&m_bulletTex);	//弾
	m_bullet.SetOwner(this);	//弾
	
	

	
	InitScene(Title);		//開始のタイトルの初期化呼び出し
}

void Scene::InitScene(int obj)
{
	frame = 0;
	switch (obj)
	{
	case Title:
		m_player.Init();	//プレイヤー
		m_enemy.Init();		//敵
		m_back.Init();		//背景
		//for (int i = 0; m_bulletNum > i; i++)
		//{
		//	//m_bullet[i].Init();	//弾
		//}
		m_bullet.Init();	//弾
		break;
	case Game:
		break;
	case Reselt:
		break;
	default:
		break;
	}
}

void Scene::UpdateTitle()
{
	m_player.Update();	//プレイヤー
	m_enemy.Update();	//敵
	m_back.Update();	//背景
	//for (int i=0; m_bulletNum > i; i++)
	//{
	//	m_bullet[i].Update();	//弾
	//}
	m_bullet.Update();	//弾
	//エンターキーでゲームシーンを呼び出す
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		if (!keyFlg[key_RETURN])
		{
			keyFlg[key_RETURN] = true;
			nowScene = SceneType::Game;//ゲームシーンへ
		}
	}
	else	keyFlg[key_RETURN] = false;
}

void Scene::DrawTitle()
{
	//m_back.Draw();		//背景
	//m_enemy.Draw();		//敵
	//for (int i = 0; m_bulletNum > i; i++)
	//{
	//	//m_bullet[i].Draw();	//弾
	//}
	m_bullet.Draw();	//弾

	m_player.Draw();	//プレイヤー
	
	//タイトル描画
	SHADER.m_spriteShader.DrawString(0,0, "タイトル画面", Math::Vector4(1, 1, 0, 1));
}

void Scene::UpdateGame()
{
	m_player.Update();	//プレイヤー
	m_enemy.Update();	//敵
	m_back.Update();	//背景
	//for (int i=0; m_bulletNum > i; i++)
	//{
	//	//m_bullet[i].Update();	//弾
	//}
	m_bullet.Update();	//弾
	//エンターキーでリザルトシーンを呼び出す
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		if (!keyFlg[key_RETURN])
		{
			//ゲームシーンか確認
			if (nowScene == Game)
			{
				keyFlg[key_RETURN] = true;
				nowScene = Reselt;//リザルトシーンへ
			}
		}
	}
	else	keyFlg[key_RETURN] = false;

}

void Scene::DrawGame()
{
	m_back.Draw();		//背景
	m_enemy.Draw();		//敵
	//for (int i=0; m_bulletNum > i; i++)
	//{
	//	m_bullet[i].Draw();	//弾
	//	
	//}
	m_bullet.Draw();	//弾
	m_player.Draw();	//プレイヤー
	//描画
	SHADER.m_spriteShader.DrawString(0,0, "ゲーム画面", Math::Vector4(1, 0, 0, 1));
}

void Scene::UpdateReselt()
{
	//エンターキーでタイトルシーンを呼び出す
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		if (!keyFlg[key_RETURN])
		{
			//リザルトシーンか確認
			if (nowScene == Reselt)
			{
				keyFlg[key_RETURN] = true;
				nowScene = Title;//タイトルシーンへ
				InitScene(Title);		//開始のタイトルの初期化呼び出し
			}
		}
	}
	else	keyFlg[key_RETURN] = false;
}
void Scene::DrawReselt()
{
	//描画
	SHADER.m_spriteShader.DrawString(0,0, "リザルト画面", Math::Vector4(1, 1, 1, 1));
}
void Scene::Release()
{
	// 画像の解放処理
	m_playerTex.Release();
	m_enemy1Tex.Release();
	m_back1Tex.Release();
	m_bulletTex.Release();
}

void Scene::ImGuiUpdate()
{
	//return;

	ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	// デバッグウィンドウ
	if (ImGui::Begin("Debug Window"))
	{
		ImGui::Text("FPS : %d", APP.m_fps);
		ImGui::Text("%d", m_player.GetMode());
		

	}
	ImGui::End();
}
