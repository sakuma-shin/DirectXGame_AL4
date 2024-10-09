#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize(Model* model, uint32_t textureHandle, const Vector3& position)
{
	//NULLポインタチェック
	assert(model);
	model_ = model;

	textureHandle_ = textureHandle;

	//ワ－ルドトランスフォームの初期化
	worldTransform_.Initialize();
	//引数からpositionを代入して初期座標を設定
	worldTransform_.translation_ = position;
	//敵が正面を向くようにする
	worldTransform_.rotation_.y=3.2f;

	const float kSpeed = -0.2f;
	velocity_ = { 0.0f,0.0f,kSpeed };
}

void Enemy::Update()
{
	//敵の移動
	worldTransform_.translation_ += velocity_;
	worldTransform_.UpdateMatrix();
}

void Enemy::Draw(Camera& camera)
{
	model_->Draw(worldTransform_, camera, textureHandle_);
}
