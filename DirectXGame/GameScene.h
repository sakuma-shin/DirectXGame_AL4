#pragma once
#include <audio\Audio.h>
#include <base\TextureManager.h>
#include <3d\DebugCamera.h>
#include <3d\AxisIndicator.h>
#include <3d\Camera.h>
#include <2d\Sprite.h>
#include"Player.h"


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

	DirectXCommon*dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	//テクスチャハンドル
	uint32_t playerTextureHandle_ = 0;

	//モデル
	Model* playerModel_ = nullptr;

	//カメラ
	Camera camera_;

	//自キャラ
	Player* player_ = nullptr;


	//デバッグカメラ
	DebugCamera* debugCamera_ = nullptr;

	bool isDebugCameraActive_ = false;


};

