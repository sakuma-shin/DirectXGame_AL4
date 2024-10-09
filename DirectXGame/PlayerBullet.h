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
	void Initialize(KamataEngine::Model* model,const KamataEngine::Vector3& position);

	void Update();

	void Draw(const KamataEngine::Camera& camera);

private:
	KamataEngine::WorldTransform worldTransform_;

	KamataEngine::Model* model_ = nullptr;

	KamataEngine::ObjectColor objColor;

	uint32_t textureHandle_ = 0u;
};

