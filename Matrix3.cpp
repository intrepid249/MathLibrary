#include "Matrix3.h"

#include <memory.h>
#include <math.h>

#include <iostream>


Matrix3 & Matrix3::operator=(const Matrix3 & a_rhs) {
	x1 = a_rhs.x1;
	x2 = a_rhs.x2;
	x3 = a_rhs.x3;
	y1 = a_rhs.y1;
	y2 = a_rhs.y2;
	y3 = a_rhs.y3;
	z1 = a_rhs.z1;
	z2 = a_rhs.z2;
	z3 = a_rhs.z3;
	return *this;
}

Matrix3::Matrix3() : x1(1), x2(0), x3(0), y1(0), y2(1), y3(0), z1(0), z2(0), z3(1) {
}

Matrix3::Matrix3(float *a_ptr) :
	// This will store the axis-major 'colums' in memory as 'rows', so we can access
	// columns using the subscript [] operator
	x1(a_ptr[0]), x2(a_ptr[1]), x3(a_ptr[2]),
	y1(a_ptr[3]), y2(a_ptr[4]), y3(a_ptr[5]),
	z1(a_ptr[6]), z2(a_ptr[7]), z3(a_ptr[8]) {
}

Matrix3::Matrix3(float a_x1, float a_x2, float a_x3,
	float a_y1, float a_y2, float a_y3,
	float a_z1, float a_z2, float a_z3) :
	// This will store the axis-major 'colums' in memory as 'rows', so we can access
	// columns using the subscript [] operator
	x1(a_x1), x2(a_x2), x3(a_x3),
	y1(a_y1), y2(a_y2), y3(a_y3),
	z1(a_z1), z2(a_z2), z3(a_z3) {
}

#pragma region Static Methods
Matrix3 Matrix3::createIdentity() {
	return Matrix3(1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f);
}

Matrix3 Matrix3::createTranslation(float a_x, float a_y, float a_z) {
	return Matrix3(1.0f, 0.0f, 0.0f,
					0.0f, 1.0f, 0.0f,
					a_x, a_y, a_z);
}

Matrix3 Matrix3::createTranslation(const Vector3 &a_vec) {
	return Matrix3(1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		a_vec.x, a_vec.y, a_vec.z);
}

Matrix3 Matrix3::createTranslation(const Vector2 &a_vec, float a_z) {
	return Matrix3(1.0f, 0.0f, 0.0f,
					0.0f, 1.0f, 0.0f,
					a_vec.x, a_vec.y, a_z);
}

Matrix3 Matrix3::createRotation(float a_rot) {
	return Matrix3(cosf(a_rot), sinf(a_rot), 0.0f,
		-sinf(a_rot), cosf(a_rot), 0.0f,
		0.0f, 0.0f, 1.0f);
}

Matrix3 Matrix3::createScale(float a_xScale, float a_yScale) {
	return Matrix3(
		a_xScale, 0.0f, 0.0f,
		0.0f, a_yScale, 0.0f,
		0.0f, 0.0f, 1.0f);
}
#pragma endregion

#pragma region Operators
Vector3 Matrix3::operator * (const Vector3 &a_vec) const {
	return Vector3(
		v[0].x*a_vec.x + v[1].x*a_vec.y + v[2].x*a_vec.z,
		v[0].y*a_vec.x + v[1].y*a_vec.y + v[2].y*a_vec.z,
		v[0].z*a_vec.x + v[1].z*a_vec.y + v[2].z*a_vec.z);
}


Vector2 Matrix3::operator * (const Vector2 &a_vec) const {
	return Vector2(	(v[0].x * a_vec.x) + (v[1].x * a_vec.y) + v[2].x,
					(v[0].y * a_vec.x) + (v[1].y * a_vec.y) + v[2].y);
}

Vector3 & Matrix3::operator[](int a_index) {
	return v[a_index];
}

Matrix3 Matrix3::operator *(const Matrix3 &a_rhs) const {
	Matrix3 tmp;
	// We are in column major, so our memory is storing 'rows' of the column-vectors
	for (auto c = 0; c < 3; c++) {
		for (auto r = 0; r < 3; r++) {
			tmp.m_floats[c][r] = (	m_floats[0][r] * a_rhs.m_floats[c][0] +
									m_floats[1][r] * a_rhs.m_floats[c][1] +
									m_floats[2][r] * a_rhs.m_floats[c][2]);
		}
	}

	return tmp;
}

Matrix3 &Matrix3::operator *=(const Matrix3 &a_rhs) {
	*this = *this * a_rhs;
	return *this;
}
#pragma endregion

#pragma region Class Methods
void  Matrix3::set(float a_x1, float a_x2, float a_x3,
	float a_y1, float a_y2, float a_y3,
	float a_z1, float a_z2, float a_z3) {
	x1 = a_x1, x2 = a_x2, x3 = a_x3;
	y1 = a_y1, y2 = a_y2, y3 = a_y3;
	z1 = a_z1, z2 = a_z2, z3 = a_z3;
}

void  Matrix3::set(float *a_ptr) {
	memcpy(m, &a_ptr, sizeof(float) * 9);
}

// only set the translation component of the matrix
void Matrix3::setTranslation(float a_x, float a_y) {
	z1 = a_x; // x-component of the translation axis
	z2 = a_y; // y-component of the translation axis

}

// only set the translation component of the matrix
void Matrix3::setTranslation(const Vector2 &a_vec) {
	z1 = a_vec.x; // x-component of the translation axis
	z2 = a_vec.y; // y-component of the translation axis
}

void Matrix3::setRotateX(float a_rot) {
	// Alter the z and y coordinates to rotate around the x-axis
	y2 = cosf(a_rot);
	y3 = sinf(a_rot);
	z2 = -sinf(a_rot);
	z3 = cosf(a_rot);
}

void Matrix3::setRotateY(float a_rot) {
	// alter the x and z coordinates to rotate around the y-axis
	x1 = cosf(a_rot);
	x3 = -sinf(a_rot);
	z1 = sinf(a_rot);
	z3 = cosf(a_rot);
}

void Matrix3::setRotateZ(float a_rot) {
	// alter the x and y coordinates to rotate around the z-axis
	x1 = cosf(a_rot);
	x2 = sinf(a_rot);
	y1 = -sinf(a_rot);
	y2 = cosf(a_rot);
}

float Matrix3::getRotationZ() {
	return atan2f(x2, x1);
}

// add x and y onto the translation component of the matrix
void Matrix3::translate(float a_x, float a_y) {
	z1 += a_x; // x-component of the translation axis
	z2 += a_y; // y-component of the translation axis
}

// add x and y onto the translation component of the matrix
void Matrix3::translate(const Vector2 &a_vec) {
	z1 += a_vec.x; // x-component of the translation axis
	z2 += a_vec.y; // y-component of the translation axis
}

// returns the translation component of the matrix
Vector2 Matrix3::getTranslation() const {
	return Vector2(z1, z2);
}
#pragma endregion