#include "Player.h"
#include<cassert>


void Player::Initialize(Model* model, uint32_t textureHandle)
{
	//NULLポインタチェック
	assert(model);

	model_ = model;
	textureHandle_ = textureHandle;
	objColor.Initialize();

	worldTransform_.Initialize();
}

void Player::Update()
{
	worldTransform_.TransferMatrix();
}

void Player::Draw(Camera& camera)
{
	model_->Draw(worldTransform_, camera, textureHandle_,&objColor);
}

