#pragma once
#include <3d\WorldTransform.h>
#include <3d\Model.h>
#include <input\Input.h>
#include <math\Vector3.h>
#include"ExMath.h"
#include <2d\ImGuiManager.h>

using namespace KamataEngine;
class Player
{
public:

	//初期化
	void Initialize(Model* model,uint32_t textureHandle);

	//更新
	void Update();

	//描画
	void Draw(Camera& camera);

private:
	WorldTransform worldTransform_; 

	//モデル
	Model* model_ = nullptr;

	//テクスチャハンドル
	uint32_t textureHandle_ = 0u;

	ObjectColor objColor;

	//キーボード入力
	Input* input_ = nullptr;
};

