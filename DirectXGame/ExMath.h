#pragma once
#include"math/Vector3.h"
#include"math/Matrix4x4.h"
#include<cmath>

using namespace KamataEngine;
struct AABB {
	Vector3 min; // 最小点
	Vector3 max; // 最小点
};

// 加算
Vector3 Add(const Vector3& v1, const Vector3& v2);

Vector3 Add2(const Vector3 v1, const Vector3 v2);

// 積
Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);

// 座標変換
Vector3 TransForm(const Vector3& vector3, const Matrix4x4& matrix);

// 1.X軸回転行列
Matrix4x4 MakeRotateXMatrix(float radian);

// 2.Y軸回転行列
Matrix4x4 MakeRotateYMatrix(float radian);

// 3.Z軸回転行列
Matrix4x4 MakeRotateZMatrix(float radian);

// 回転行列の合成
Matrix4x4 RotateXYZMatrix(const Vector3& radian);

// 3次元アフィン変換行列
Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);

Vector3 Lerp(const Vector3& a, const Vector3& b, float t);

Vector3 Multiply(float scalar, const Vector3& v);

Vector3 TransForm(const Vector3& vector3, const Matrix4x4& matrix);

bool IsCollision(const AABB& a, const AABB& b);

//代入演算子オーバーロード
//Vector3の掛け算
Vector3& operator*=(Vector3& v, float s);

//2項演算子オーバーロード
//Vector3の掛け算
Vector3 operator*(const Vector3& v, float s);

// 代入演算子オーバーロード
// Vector3の足し算
Vector3& operator+=(Vector3& v1, const Vector3& v2);

// 2項演算子オーバーロード
// Vector3の足し算
const Vector3 operator+(Vector3& v1, Vector3& v2);

Vector3& operator-=(Vector3& lhv, const Vector3& rhv);

const Vector3 operator-(Vector3& v1, Vector3& v2);

