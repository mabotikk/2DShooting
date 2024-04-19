#include "main.h"
#include "Scene.h"

void Scene::Draw2D()
{
	// ������\��
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
	//�t���[��
	frame = 0;
	// �L�[�t���O������
	for (int i = 0; i < key_FlgEnd; i++)
	{
		keyFlg[i] = false;
	}

	// �摜�̓ǂݍ��ݏ���
	m_playerTex.Load("Data/Texture/Player/playerTensi.png");	//�v���C���[
	m_enemy1Tex.Load("Data/Texture/Enemy/kokyu.png");	//�G
	m_back1Tex.Load("Data/Texture/Back/show.png");		//�w�i
	m_bulletTex.Load("Data/Texture/Bullet/bulletAll_siro.png");//�e
	//�摜�̃Z�b�^�[
	m_player.SetTexture(&m_playerTex);	//�v���C���[
	m_player.SetOwner(this);	//�v���C���[
	m_enemy.SetTexture(&m_enemy1Tex);	//�G
	m_enemy.SetOwner(this);		//�G
	m_back.SetTexture(&m_back1Tex);		//�w�i
	m_back.SetOwner(this);		//�w�i
	//for (int i=0; m_bulletNum > i; i++)
	//{
	//	m_bullet[i].SetTexture(&m_bulletTex);	//�e
	//	m_bullet[i].SetOwner(this);	//�e
	//}
	
	m_bullet.SetTexture(&m_bulletTex);	//�e
	m_bullet.SetOwner(this);	//�e
	
	

	
	InitScene(Title);		//�J�n�̃^�C�g���̏������Ăяo��
}

void Scene::InitScene(int obj)
{
	frame = 0;
	switch (obj)
	{
	case Title:
		m_player.Init();	//�v���C���[
		m_enemy.Init();		//�G
		m_back.Init();		//�w�i
		//for (int i = 0; m_bulletNum > i; i++)
		//{
		//	//m_bullet[i].Init();	//�e
		//}
		m_bullet.Init();	//�e
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
	m_player.Update();	//�v���C���[
	m_enemy.Update();	//�G
	m_back.Update();	//�w�i
	//for (int i=0; m_bulletNum > i; i++)
	//{
	//	m_bullet[i].Update();	//�e
	//}
	m_bullet.Update();	//�e
	//�G���^�[�L�[�ŃQ�[���V�[�����Ăяo��
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		if (!keyFlg[key_RETURN])
		{
			keyFlg[key_RETURN] = true;
			nowScene = SceneType::Game;//�Q�[���V�[����
		}
	}
	else	keyFlg[key_RETURN] = false;
}

void Scene::DrawTitle()
{
	//m_back.Draw();		//�w�i
	//m_enemy.Draw();		//�G
	//for (int i = 0; m_bulletNum > i; i++)
	//{
	//	//m_bullet[i].Draw();	//�e
	//}
	m_bullet.Draw();	//�e

	m_player.Draw();	//�v���C���[
	
	//�^�C�g���`��
	SHADER.m_spriteShader.DrawString(0,0, "�^�C�g�����", Math::Vector4(1, 1, 0, 1));
}

void Scene::UpdateGame()
{
	m_player.Update();	//�v���C���[
	m_enemy.Update();	//�G
	m_back.Update();	//�w�i
	//for (int i=0; m_bulletNum > i; i++)
	//{
	//	//m_bullet[i].Update();	//�e
	//}
	m_bullet.Update();	//�e
	//�G���^�[�L�[�Ń��U���g�V�[�����Ăяo��
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		if (!keyFlg[key_RETURN])
		{
			//�Q�[���V�[�����m�F
			if (nowScene == Game)
			{
				keyFlg[key_RETURN] = true;
				nowScene = Reselt;//���U���g�V�[����
			}
		}
	}
	else	keyFlg[key_RETURN] = false;

}

void Scene::DrawGame()
{
	m_back.Draw();		//�w�i
	m_enemy.Draw();		//�G
	//for (int i=0; m_bulletNum > i; i++)
	//{
	//	m_bullet[i].Draw();	//�e
	//	
	//}
	m_bullet.Draw();	//�e
	m_player.Draw();	//�v���C���[
	//�`��
	SHADER.m_spriteShader.DrawString(0,0, "�Q�[�����", Math::Vector4(1, 0, 0, 1));
}

void Scene::UpdateReselt()
{
	//�G���^�[�L�[�Ń^�C�g���V�[�����Ăяo��
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		if (!keyFlg[key_RETURN])
		{
			//���U���g�V�[�����m�F
			if (nowScene == Reselt)
			{
				keyFlg[key_RETURN] = true;
				nowScene = Title;//�^�C�g���V�[����
				InitScene(Title);		//�J�n�̃^�C�g���̏������Ăяo��
			}
		}
	}
	else	keyFlg[key_RETURN] = false;
}
void Scene::DrawReselt()
{
	//�`��
	SHADER.m_spriteShader.DrawString(0,0, "���U���g���", Math::Vector4(1, 1, 1, 1));
}
void Scene::Release()
{
	// �摜�̉������
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

	// �f�o�b�O�E�B���h�E
	if (ImGui::Begin("Debug Window"))
	{
		ImGui::Text("FPS : %d", APP.m_fps);
		ImGui::Text("%d", m_player.GetMode());
		

	}
	ImGui::End();
}
