#pragma once

using namespace std;

//シーン種類
enum SceneType
{
	Title,	//0タイトル
	Game,	//1ゲーム本編
	Reselt	//2リザルト
};

enum	// キーフラグ用
{
	key_T,
	key_E,
	key_W,
	key_A,
	key_B,
	key_S,
	key_D,
	key_P,
	key_Q,
	key_G,
	key_Z,
	key_F,
	key_UP,
	key_DOWN,
	key_LEFT,
	key_RIGHT,
	key_SPACE,
	key_RETURN,
	key_BackSpace,
	key_Tab,
	key_SHIFT,
	key_0,
	key_1,
	key_2,
	key_3,
	key_4,
	key_5,
	key_6,
	key_7,
	key_8,
	key_9,
	key_LMB,
	key_RMB,

	key_FlgEnd
};


// ==== 自作の描画系関数 =============================

// １行で画像描画宣言 ( 行列, テクスチャ, 切り取り範囲, アルファ値)
void DrawImg(Math::Matrix a_mat, KdTexture* a_tex, Math::Rectangle a_rect, float a_alpha);

// １行で色付き画像描画 (行列, テクスチャ, 切り取り範囲, 色)
void DrawImgEX(Math::Matrix a_mat, KdTexture* a_tex, Math::Rectangle a_rect, Math::Color a_color);

//〇描画
void DrawMaru(float x, float y, float rad, Math::Color* color, bool nuri);

//△描画
void DrawSankaku(float x1, float y1, float x2, float y2, float x3, float y3, Math::Color* color, bool nuri);

//箱描画
void DrawHako(float x, float y, float xs, float ys, Math::Color* color, bool nuri);

//線描画
void DrawSen(float x, float y, float xx, float yy, Math::Color* color);

//点描画
void DrawTen(float x, float y, Math::Color* color);

//文字描画　引数(X, Y, 文字, 色(R,G,B,A), 影を付けるかどうか)
void DrawMoji(float x, float y, char* p_str, Math::Color* color, bool Shadow, float SAlpha);

// 引数をラジアンに変換（宣言）
float DegToRad(float a_deg);

// 乱数取得
float Rnd();

// キー状態取得
bool GetKey(int key);

// bool型をint型にするやつ(falseは0、trueは1)
int BoolToInt(bool a);

// 距離を計算して返す
float GetDist(Math::Vector2 Apos, Math::Vector2 Bpos);

// AとBの角度を計算して返す
float GetRadian(Math::Vector2 Apos, Math::Vector2 Bpos);

Math::Matrix CreateScale(float a, float b, float c);