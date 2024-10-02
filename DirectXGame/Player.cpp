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

	input_ = Input::GetInstance();
}

void Player::Update()
{
	//キャラクターの移動ベクトル
	Vector3 move = { 0,0,0 };

	//キャラクターの移動の速さ
	const float kCharacterSpeed = 0.2f;

	//押した方向で移動ベクトルを変更(左右)
	if (input_->PushKey(DIK_LEFT)||input_->PushKey(DIK_A)) {
		move.x -= kCharacterSpeed;
	} else if (input_->PushKey(DIK_RIGHT) || input_->PushKey(DIK_D)) {
		move.x += kCharacterSpeed;
	}

	//押した方向で移動ベクトルを変更(上下)
	if (input_->PushKey(DIK_UP) || input_->PushKey(DIK_W)) {
		move.y += kCharacterSpeed;
	} else if (input_->PushKey(DIK_DOWN) || input_->PushKey(DIK_S)) {
		move.y -= kCharacterSpeed;
	}

	const float kMoveLimitX = 33.0f;
	const float kMoveLimitY = 18.0f;

	//範囲を超えない処理
	worldTransform_.translation_.x = max(worldTransform_.translation_.x, -kMoveLimitX);
	worldTransform_.translation_.x = min(worldTransform_.translation_.x, kMoveLimitX);
	worldTransform_.translation_.y = max(worldTransform_.translation_.y, -kMoveLimitY);
	worldTransform_.translation_.y = min(worldTransform_.translation_.y, kMoveLimitY);

	ImGui::Begin("window");
	ImGui::DragFloat3("player.pos", &worldTransform_.translation_.x, 0.01f);
	ImGui::DragFloat3("player.rotate", &worldTransform_.rotation_.x, 0.01f);
	ImGui::DragFloat3("player.scale", &worldTransform_.scale_.x, 0.01f);
	ImGui::End();

	//座標移動(ベクトルの加算)
	worldTransform_.translation_ += move;

	worldTransform_.UpdateMatrix();

}

void Player::Draw(Camera& camera)
{
	model_->Draw(worldTransform_, camera, textureHandle_,&objColor);
}

