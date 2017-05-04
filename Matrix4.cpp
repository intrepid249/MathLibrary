#include "Matrix4.h"
#include <Vector3.h>

#include <memory.h>
#include <math.h>

Matrix4::~Matrix4() {
	*this = createIdentity();
}

Matrix4::Matrix4() {
}

#pragma region Static Methods
Matrix4 Matrix4::createIdentity() {
	return Matrix4(1.0f, 0.0f, 0.0f, 0.f,
		0.0f, 1.0f, 0.0f, 0.f,
		0.0f, 0.0f, 1.0f, 0.f,
		0.f, 0.f, 0.f, 1.f);
}

Matrix4 Matrix4::createTranslation(float a_x, float a_y, float a_z, float a_w) {
	return Matrix4(1.0f, 0.0f, 0.0f, 0.f,
		0.0f, 1.0f, 0.0f, 0.f,
		0.f, 0.f, 1.f, 0.f,
		a_x, a_y, a_z, a_w);
}

Matrix4 Matrix4::createTranslation(const Vector3 &a_vec, float a_w) {
	return Matrix4(1.0f, 0.0f, 0.0f, 0.f,
		0.0f, 1.0f, 0.0f, 0.f,
		0.f, 0.f, 1.f, 0.f,
		a_vec.x, a_vec.y, a_vec.z, a_w);
}

Matrix4 Matrix4::createRotation(float a_rot) {
	return Matrix4(cosf(a_rot), sinf(a_rot), 0.0f, 0.f,
		-sinf(a_rot), cosf(a_rot), 0.0f, 0.f,
		0.f, 0.f, 1.f, 0.f,
		0.0f, 0.0f, 0.f, 1.0f);
}

Matrix4 Matrix4::createScale(float a_x, float a_y, float a_z) {
	return Matrix4(
		a_x, 0.f, 0.f, 0.f,
		0.f, a_y, 0.f, 0.f,
		0.f, 0.f, a_z, 0.f,
		0.f, 0.f, 0.f, 1.f);
}
#pragma endregion


void  Matrix4::set(float *a_ptr) {
}

void  Matrix4::set(float a_x1, float a_x2, float a_x3, float a_x4,
	float a_y1, float a_y2, float a_y3, float a_y4,
	float a_z1, float a_z2, float a_z3, float a_z4,
	float a_w1, float a_w2, float a_w3, float a_w4) {
	x1 = a_x1; x2 = a_x2; x3 = a_x3; x4 = a_x4;
	y1 = a_y1; y2 = a_y2; y3 = a_y3; y4 = a_y4;
	z1 = a_z1; z2 = a_z2; z3 = a_z3; z4 = a_z4;
	w1 = a_w1; w2 = a_w2; w3 = a_w3; w4 = a_w4;
}


Matrix4::Matrix4(float *a_ptr) :
	x1(a_ptr[0]), x2(a_ptr[1]), x3(a_ptr[2]), x4(a_ptr[3]),
	y1(a_ptr[4]), y2(a_ptr[5]), y3(a_ptr[6]), y4(a_ptr[7]),
	z1(a_ptr[8]), z2(a_ptr[9]), z3(a_ptr[10]), z4(a_ptr[11]),
	w1(a_ptr[12]), w2(a_ptr[13]), w3(a_ptr[14]), w4(a_ptr[15]) {
}

Matrix4::Matrix4(float a_m1, float a_m2, float a_m3, float a_m4, float a_m5, float a_m6, float a_m7, float a_m8, float a_m9, float a_m10, float a_m11, float a_m12,
	float a_m13, float a_m14, float a_m15, float a_m16) :
	x1(a_m1), x2(a_m2), x3(a_m3), x4(a_m4),
	y1(a_m5), y2(a_m6), y3(a_m7), y4(a_m8),
	z1(a_m9), z2(a_m10), z3(a_m11), z4(a_m12),
	w1(a_m13), w2(a_m14), w3(a_m15), w4(a_m16) {
}

Vector4 Matrix4::operator * (const Vector4 &a_vec) const {
	return Vector4(x1 * a_vec.x + y1 * a_vec.y + z1 * a_vec.z + w1 * a_vec.w,
		x2 * a_vec.x + y2 * a_vec.y + z2 * a_vec.z + w2 * a_vec.w,
		x3 * a_vec.x + y3 * a_vec.y + z3 * a_vec.z + w3 * a_vec.w,
		x4 * a_vec.x + y4 * a_vec.y + z4 * a_vec.z + w4 * a_vec.w);
}

Matrix4 Matrix4::operator *(const Matrix4 &a_rhs) const {
	Matrix4 tmp;
	// We are in column major, so our memory is storing 'rows' of the column-vectors
	for (auto c = 0; c < 4; c++) {
		for (auto r = 0; r < 4; r++) {
			tmp.m_floats[c][r] = (m_floats[0][r] * a_rhs.m_floats[c][0] +
				m_floats[1][r] * a_rhs.m_floats[c][1] +
				m_floats[2][r] * a_rhs.m_floats[c][2] +
				m_floats[3][r] * a_rhs.m_floats[c][3]);
		}
	}

	return tmp;
}


void Matrix4::setRotateX(float a_rot) {
	set(1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, cosf(a_rot), sinf(a_rot), 0.0f,
		0.0f, -sinf(a_rot), cosf(a_rot), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
}

void Matrix4::setRotateY(float a_rot) {
	set(cosf(a_rot), 0.0f, -sinf(a_rot), 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		sinf(a_rot), 0.0f, cosf(a_rot), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
}

void Matrix4::setRotateZ(float a_rot) {
	set(cosf(a_rot), sinf(a_rot), 0.0f, 0.0f,
		-sinf(a_rot), cosf(a_rot), 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
}

float Matrix4::getRotationZ() {
	return atan2f(x2, x1);
}