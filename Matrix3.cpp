#include "Matrix3.h"

#include <memory.h>
#include <math.h>

#include <iostream>

template <class T>
Matrix3<T> & Matrix3<T>::operator=(const Matrix3 & a_rhs) {
	memcpy(m, a_rhs.m, sizeof(T) * 9);
	return *this;
}

template <class T>
Matrix3<T>::Matrix3() : x1(1), x2(0), x3(0), y1(0), y2(1), y3(0), z1(0), z2(0), z3(1) {
}

template <class T>
Matrix3<T>::Matrix3(T *a_ptr) :
	// This will store the axis-major 'colums' in memory as 'rows', so we can access
	// columns using the subscript [] operator
	x1(a_ptr[0]), x2(a_ptr[1]), x3(a_ptr[2]),
	y1(a_ptr[3]), y2(a_ptr[4]), y3(a_ptr[5]),
	z1(a_ptr[6]), z2(a_ptr[7]), z3(a_ptr[8]) {
}

template <class T>
Matrix3<T>::Matrix3(T a_x1, T a_x2, T a_x3,
	T a_y1, T a_y2, T a_y3,
	T a_z1, T a_z2, T a_z3) :
	// This will store the axis-major 'colums' in memory as 'rows', so we can access
	// columns using the subscript [] operator
	x1(a_x1), x2(a_x2), x3(a_x3),
	y1(a_y1), y2(a_y2), y3(a_y3),
	z1(a_z1), z2(a_z2), z3(a_z3) {
}

template<class T>
Matrix3<T>::Matrix3(const Matrix3 & rhs) {
	v[0] = rhs.v[0];
	v[1] = rhs.v[1];
	v[2] = rhs.v[2];
}

#pragma region Static Methods
template <class T>
Matrix3<T> Matrix3<T>::createIdentity() {
	return Matrix3<T>(1, 0, 0,
		0, 1, 0,
		0, 0, 1);
}

template <class T>
Matrix3<T> Matrix3<T>::createTranslation(T a_x, T a_y, T a_z) {
	return Matrix3<T>(1, 0, 0,
					0, 1, 0,
					a_x, a_y, a_z);
}

template <class T>
Matrix3<T> Matrix3<T>::createTranslation(const Vector3<T> &a_vec) {
	return Matrix3<T>(1, 0, 0,
		0, 1, 0,
		a_vec.x, a_vec.y, a_vec.z);
}

template <class T>
Matrix3<T> Matrix3<T>::createTranslation(const Vector2<T> &a_vec, T a_z) {
	return Matrix3<T>(1, 0, 0,
					0, 1, 0,
					a_vec.x, a_vec.y, a_z);
}

template <class T>
Matrix3<T> Matrix3<T>::createRotation(T a_rot) {
	return Matrix3<T>((T)cos((double)a_rot), (T)sin((double)a_rot), 0,
					  (T)-sin((double)a_rot), (T)cos((double)a_rot), 0,
						0, 0, 1);
}


template <class T>
Matrix3<T> Matrix3<T>::createScale(T a_xScale, T a_yScale) {
	return Matrix3<T>(
		a_xScale, 0, 0,
		0, a_yScale, 0,
		0, 0, 1);
}
#pragma endregion

#pragma region Operators
template <class T>
Vector3<T> Matrix3<T>::operator * (const Vector3<T> &a_vec) const {
	return Vector3<T>(
		v[0].x*a_vec.x + v[1].x*a_vec.y + v[2].x*a_vec.z,
		v[0].y*a_vec.x + v[1].y*a_vec.y + v[2].y*a_vec.z,
		v[0].z*a_vec.x + v[1].z*a_vec.y + v[2].z*a_vec.z);
}

template <class T>
Vector2<T> Matrix3<T>::operator * (const Vector2<T> &a_vec) const {
	return Vector2<T>(	(v[0].x * a_vec.x) + (v[1].x * a_vec.y) + v[2].x,
					(v[0].y * a_vec.x) + (v[1].y * a_vec.y) + v[2].y);
}

template<class T>
Vector3<T>& Matrix3<T>::operator[](unsigned int a_index) {
	return v[a_index];
}

template <class T>
Matrix3<T> Matrix3<T>::operator *(const Matrix3 &a_rhs) const {
	Matrix3<T> tmp;
	// We are in column major, so our memory is storing 'rows' of the column-vectors
	for (unsigned int c = 0; c < 3; c++) {
		for (unsigned int r = 0; r < 3; r++) {
			tmp.m_floats[c][r] = (	m_floats[0][r] * a_rhs.m_floats[c][0] +
									m_floats[1][r] * a_rhs.m_floats[c][1] +
									m_floats[2][r] * a_rhs.m_floats[c][2]);
		}
	}

	return tmp;
}

template <class T>
Matrix3<T> &Matrix3<T>::operator *=(const Matrix3 &a_rhs) {
	*this = *this * a_rhs;
	return *this;
}
#pragma endregion

#pragma region Class Methods
template <class T>
void  Matrix3<T>::set(T a_x1, T a_x2, T a_x3,
	T a_y1, T a_y2, T a_y3,
	T a_z1, T a_z2, T a_z3) {
	x1 = a_x1, x2 = a_x2, x3 = a_x3;
	y1 = a_y1, y2 = a_y2, y3 = a_y3;
	z1 = a_z1, z2 = a_z2, z3 = a_z3;
}

template <class T>
void  Matrix3<T>::set(T *a_ptr) {
	memcpy(m, &a_ptr, sizeof(T) * 9);
}

// only set the translation component of the matrix
template <class T>
void Matrix3<T>::setTranslation(T a_x, T a_y) {
	z1 = a_x; // x-component of the translation axis
	z2 = a_y; // y-component of the translation axis
}

// only set the translation component of the matrix
template <class T>
void Matrix3<T>::setTranslation(const Vector2<T> &a_vec) {
	z1 = a_vec.x; // x-component of the translation axis
	z2 = a_vec.y; // y-component of the translation axis
}

template <class T>
void Matrix3<T>::setRotateX(T a_rot) {
	// Alter the z and y coordinates to rotate around the x-axis
	y2 = (T)cos((double)a_rot);
	y3 = (T)sin((double)a_rot);
	z2 = (T)-sin((double)a_rot);
	z3 = (T)cos((double)a_rot);
}

template <class T>
void Matrix3<T>::setRotateY(T a_rot) {
	// alter the x and z coordinates to rotate around the y-axis
	x1 = (T)cos((double)a_rot);
	x3 = (T)-sin((double)a_rot);
	z1 = (T)sin((double)a_rot);
	z3 = (T)cos((double)a_rot);
}

template <class T>
void Matrix3<T>::setRotateZ(T a_rot) {
	// alter the x and y coordinates to rotate around the z-axis
	x1 = (T)cos((double)a_rot);
	x2 = (T)sin((double)a_rot);
	y1 = (T)-sin((double)a_rot);
	y2 = (T)cos((double)a_rot);
}

template<class T>
T Matrix3<T>::getRotationX() const {
	return T(atan2((double)y3, (double)y2));
}

template<class T>
T Matrix3<T>::getRotationY() const {
	return T(atan2((double)x3, (double)x1));
}

template <class T>
T Matrix3<T>::getRotationZ() const {
	return (T)atan2((double)x2, (double)x1);
}

template<class T>
void Matrix3<T>::setScale(const Vector2<T>& a_vec) {
	x1 = a_vec.x;
	y2 = a_vec.x;
}

template<class T>
void Matrix3<T>::setScale(T a_x, T a_y) {
	x1 = a_x;
	y2 = a_y;
}

template<class T>
Vector2<T> Matrix3<T>::getScale() const {
	return Vector2<T>(x1, y2);
}

// add x and y onto the translation component of the matrix
template <class T>
void Matrix3<T>::translate(T a_x, T a_y) {
	z1 += a_x; // x-component of the translation axis
	z2 += a_y; // y-component of the translation axis
}

// add x and y onto the translation component of the matrix
template <class T>
void Matrix3<T>::translate(const Vector2<T> &a_vec) {
	z1 += a_vec.x; // x-component of the translation axis
	z2 += a_vec.y; // y-component of the translation axis
}

// returns the translation component of the matrix
template <class T>
Vector2<T> Matrix3<T>::getTranslation() const {
	return Vector2<T>(z1, z2);
}
#pragma endregion

/*Instantiate every possible use of the template classes*/
template class Matrix3<float>;
template class Matrix3<int>;
template class Matrix3<double>;
template class Matrix3<long>;
template class Matrix3<short>;