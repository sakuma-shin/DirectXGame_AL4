#pragma once
#include <3d\WorldTransform.h>
#include <3d\Model.h>
#include <base\TextureManager.h>
#include <math\Vector3.h>
#include"ExMath.h"
#include <2d\ImGuiManager.h>
#include<cassert>

class Enemy
{
public:
	Enemy();
	~Enemy();

	void Initialize(Model* model,uint32_t textureHandle,const Vector3& position);

	void Update();

	void Draw(Camera& camera);

private:
	KamataEngine::WorldTransform worldTransform_;

	KamataEngine::Model* model_ = nullptr;

	uint32_t textureHandle_ = 0u;

	Vector3 position_ = {};

	Vector3 velocity_ = {};
};

