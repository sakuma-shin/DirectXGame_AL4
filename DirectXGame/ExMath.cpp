#include"ExMath.h"

// 加算
Vector3 Add(const Vector3& v1, const Vector3& v2) {
	Vector3 result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;

	return result;
}

Vector3 Add2(const Vector3 v1, const Vector3 v2) {
	Vector3 result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;

	return result;
}

// 積
Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 result;

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			result.m[i][j] = 0;
			for (int k = 0; k < 4; ++k) {
				result.m[i][j] += m1.m[i][k] * m2.m[k][j];
			}
		}
	}

	return result;
}

// 1.X軸回転行列
Matrix4x4 MakeRotateXMatrix(float radian) {
	Matrix4x4 result;
	float cos = cosf(radian);
	float sin = sinf(radian);

	result.m[0][0] = 1.0f;
	result.m[0][1] = 0.0f;
	result.m[0][2] = 0.0f;
	result.m[0][3] = 0.0f;
	result.m[1][0] = 0.0f;
	result.m[1][1] = cos;
	result.m[1][2] = sin;
	result.m[1][3] = 0.0f;
	result.m[2][0] = 0.0f;
	result.m[2][1] = -sin;
	result.m[2][2] = cos;
	result.m[2][3] = 0.0f;
	result.m[3][0] = 0.0f;
	result.m[3][1] = 0.0f;
	result.m[3][2] = 0.0f;
	result.m[3][3] = 1.0f;
	return result;
}

// 2.Y軸回転行列
Matrix4x4 MakeRotateYMatrix(float radian) {
	Matrix4x4 result;
	float cos = cosf(radian);
	float sin = sinf(radian);

	result.m[0][0] = cos;
	result.m[0][1] = 0.0f;
	result.m[0][2] = -sin;
	result.m[0][3] = 0.0f;
	result.m[1][0] = 0.0f;
	result.m[1][1] = 1.0f;
	result.m[1][2] = 0.0f;
	result.m[1][3] = 0.0f;
	result.m[2][0] = sin;
	result.m[2][1] = 0.0f;
	result.m[2][2] = cos;
	result.m[2][3] = 0.0f;
	result.m[3][0] = 0.0f;
	result.m[3][1] = 0.0f;
	result.m[3][2] = 0.0f;
	result.m[3][3] = 1.0f;
	return result;
}

// 3.Z軸回転行列
Matrix4x4 MakeRotateZMatrix(float radian) {
	Matrix4x4 result;
	float cos = cosf(radian);
	float sin = sinf(radian);

	result.m[0][0] = cos;
	result.m[0][1] = sin;
	result.m[0][2] = 0.0f;
	result.m[0][3] = 0.0f;
	result.m[1][0] = -sin;
	result.m[1][1] = cos;
	result.m[1][2] = 0.0f;
	result.m[1][3] = 0.0f;
	result.m[2][0] = 0.0f;
	result.m[2][1] = 0.0f;
	result.m[2][2] = 1.0f;
	result.m[2][3] = 0.0f;
	result.m[3][0] = 0.0f;
	result.m[3][1] = 0.0f;
	result.m[3][2] = 0.0f;
	result.m[3][3] = 1.0f;
	return result;
}

// 回転行列の合成
Matrix4x4 RotateXYZMatrix(const Vector3& radian) {
	Matrix4x4 result =
		Multiply(MakeRotateXMatrix(radian.x), Multiply(MakeRotateYMatrix(radian.y), MakeRotateZMatrix(radian.z)));

	return result;
}

// 3次元アフィン変換行列
Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate) {
	Matrix4x4 result;
	result.m[0][3] = 0.0f;
	result.m[1][3] = 0.0f;
	result.m[2][3] = 0.0f;
	result.m[3][3] = 1.0f;

	Matrix4x4 rotateM = RotateXYZMatrix(rotate);

	result.m[0][0] = scale.x * rotateM.m[0][0];
	result.m[0][1] = scale.x * rotateM.m[0][1];
	result.m[0][2] = scale.x * rotateM.m[0][2];

	result.m[1][0] = scale.y * rotateM.m[1][0];
	result.m[1][1] = scale.y * rotateM.m[1][1];
	result.m[1][2] = scale.y * rotateM.m[1][2];

	result.m[2][0] = scale.z * rotateM.m[2][0];
	result.m[2][1] = scale.z * rotateM.m[2][1];
	result.m[2][2] = scale.z * rotateM.m[2][2];

	result.m[3][0] = translate.x;
	result.m[3][1] = translate.y;
	result.m[3][2] = translate.z;

	return result;
}

Vector3 Lerp(const Vector3& a, const Vector3& b, float t) {
	Vector3 result;
	result.x = a.x + (b.x - a.x) * t;
	result.y = a.y + (b.y - a.y) * t;
	result.z = a.z + (b.z - a.z) * t;
	return result;
}

// スカラー倍
Vector3 Multiply(float scalar, const Vector3& v) {
	Vector3 result;

	result.x = v.x * scalar;
	result.y = v.y * scalar;
	result.z = v.z * scalar;

	return result;
}


Vector3 TransForm(const Vector3& vector3, const Matrix4x4& matrix) {
	Vector3 result;

	result.x = vector3.x * matrix.m[0][0] + vector3.y * matrix.m[1][0] + vector3.z * matrix.m[2][0] + matrix.m[3][0]; // x成分の変換

	result.y = vector3.x * matrix.m[0][1] + vector3.y * matrix.m[1][1] + vector3.z * matrix.m[2][1] + matrix.m[3][1]; // y成分の変換

	result.z = vector3.x * matrix.m[0][2] + vector3.y * matrix.m[1][2] + vector3.z * matrix.m[2][2] + matrix.m[3][2]; // z成分の変換

	float length = vector3.x * matrix.m[0][3] + vector3.y * matrix.m[1][3] + vector3.z * matrix.m[2][3] + matrix.m[3][3];
	if (length != 0.0f) {
		result.x /= length;
		result.y /= length;
		result.z /= length;
	}
	return result;
}


Vector3& operator*=(Vector3& v, float s) {
	v.x *= s;
	v.y *= s;
	v.z *= s;

	return v;
}

Vector3 operator*(const Vector3& v, float s) {
	Vector3 temp(v);
	return temp *= s;
}

Vector3& operator+=(Vector3& lhv, const Vector3& rhv) {
	lhv.x += rhv.x;
	lhv.y += rhv.y;
	lhv.z += rhv.z;

	return lhv;
}




Vector3& operator-=(Vector3& lhv, const Vector3& rhv) {
	lhv.x -= rhv.x;
	lhv.y -= rhv.y;
	lhv.z -= rhv.z;

	return lhv;
}


const Vector3 operator-(Vector3& v1, Vector3& v2) { return { v1.x - v2.x, v1.y - v2.y, v1.z - v2.z }; }
const Vector3 operator+(Vector3& v1, Vector3& v2) { return { v1.x + v2.x, v1.y + v2.y, v1.z + v2.z }; }

bool IsCollision(const AABB& a, const AABB& b) {
	if (a.min.x <= b.max.x && a.max.x >= b.min.x && a.min.y <= b.max.y && a.max.y >= b.min.y && a.min.z <= b.max.z && a.max.z >= b.min.z) {
		return true;
	} else {
		return false;
	}
}

Vector3 TransformNormal(const Vector3& v, const Matrix4x4& m)
{
	Vector3 result;
	result.x = v.x * m.m[0][0] + v.y * m.m[1][0] + v.z * m.m[2][0];
	result.y = v.x * m.m[0][1] + v.y * m.m[1][1] + v.z * m.m[2][1];
	result.z = v.x * m.m[0][2] + v.y * m.m[1][2] + v.z * m.m[2][2];

	return result;
}
