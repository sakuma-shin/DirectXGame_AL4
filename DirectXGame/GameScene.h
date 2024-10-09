#pragma once
#include <audio\Audio.h>
#include <base\TextureManager.h>
#include <3d\DebugCamera.h>
#include <3d\AxisIndicator.h>
#include <3d\Camera.h>
#include <2d\Sprite.h>
#include"Player.h"
#include"Enemy.h"


class GameScene
{
public:
	//コンストラクタ
	GameScene();

	//デストラクタ
	~GameScene();

	void Initialize();

	void Update();

	void Draw();

private:

	KamataEngine::DirectXCommon*dxCommon_ = nullptr;
	KamataEngine::Input* input_ = nullptr;
	KamataEngine::Audio* audio_ = nullptr;

	//テクスチャハンドル
	uint32_t playerTextureHandle_ = 0;

	//モデル
	KamataEngine::Model* playerModel_ = nullptr;

	//カメラ
	KamataEngine::Camera camera_;

	//自キャラ
	Player* player_ = nullptr;

	//敵
	Enemy* enemy_ = nullptr;
	uint32_t enemyTextureHandle_ = 0u;
	KamataEngine::Model* enemyModel_ = nullptr;

	//デバッグカメラ
	DebugCamera* debugCamera_ = nullptr;

	bool isDebugCameraActive_ = false;


};

