#pragma once
#include <3d\WorldTransform.h>
#include <3d\Model.h>
#include <base\TextureManager.h>
#include <input\Input.h>
#include <math\Vector3.h>
#include<cassert>
#include"ExMath.h"
class PlayerBullet
{
public:
	void Initialize(KamataEngine::Model* model,const KamataEngine::Vector3& position,const Vector3& velocity);

	void Update();

	void Draw(const KamataEngine::Camera& camera);

	bool IsDead() const { return isDead_; }

private:
	KamataEngine::WorldTransform worldTransform_;

	KamataEngine::Model* model_ = nullptr;

	KamataEngine::ObjectColor objColor;

	uint32_t textureHandle_ = 0u;

	Vector3 velocity_;

	//弾の寿命
	static const uint32_t kLifeTime = 60 * 5;

	//デスタイマー
	int32_t deathTimer_ = kLifeTime;

	//デスフラグ
	bool isDead_ = false;
};

