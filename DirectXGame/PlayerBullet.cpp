#include "playerBullet.h"
using namespace KamataEngine;

void PlayerBullet::Initialize(KamataEngine::Model* model, const KamataEngine::Vector3& position)
{
	//NULLポインタチェック
	assert(model);

	model_ = model;

	objColor.Initialize();

	//テクスチャ読み込み
	textureHandle_ = TextureManager::Load("white1x1.png");

	worldTransform_.Initialize();

	//引数の座標をセット
	worldTransform_.translation_ = position;
}

void PlayerBullet::Update()
{
	worldTransform_.UpdateMatrix();
}

void PlayerBullet::Draw(const KamataEngine::Camera& camera)
{
//モデルの描画
	model_->Draw(worldTransform_, camera, textureHandle_,&objColor);
}
