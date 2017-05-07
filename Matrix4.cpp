#include "Matrix4.h"
#include <Vector3.h>

#include <memory.h>
#include <math.h>

template <class T>
Matrix4<T>::Matrix4() {
	*this = createIdentity();
}

template <class T>
Matrix4<T>::Matrix4(T *a_ptr) :
	x1(a_ptr[0]), x2(a_ptr[1]), x3(a_ptr[2]), x4(a_ptr[3]),
	y1(a_ptr[4]), y2(a_ptr[5]), y3(a_ptr[6]), y4(a_ptr[7]),
	z1(a_ptr[8]), z2(a_ptr[9]), z3(a_ptr[10]), z4(a_ptr[11]),
	w1(a_ptr[12]), w2(a_ptr[13]), w3(a_ptr[14]), w4(a_ptr[15]) {
}

template <class T>
Matrix4<T>::Matrix4(T a_m1, T a_m2, T a_m3, T a_m4, T a_m5, T a_m6, T a_m7, T a_m8, T a_m9, T a_m10, T a_m11, T a_m12,
	T a_m13, T a_m14, T a_m15, T a_m16) :
	x1(a_m1), x2(a_m2), x3(a_m3), x4(a_m4),
	y1(a_m5), y2(a_m6), y3(a_m7), y4(a_m8),
	z1(a_m9), z2(a_m10), z3(a_m11), z4(a_m12),
	w1(a_m13), w2(a_m14), w3(a_m15), w4(a_m16) {
}

template<class T>
Matrix4<T>::Matrix4(const Matrix4 & rhs) {
	v[0] = rhs.v[0];
	v[1] = rhs.v[1];
	v[2] = rhs.v[2];
	v[3] = rhs.v[3];
}

#pragma region Static Methods
template <class T>
Matrix4<T> Matrix4<T>::createIdentity() {
	return Matrix4<T>(1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);
}

template <class T>
Matrix4<T> Matrix4<T>::createTranslation(T a_x, T a_y, T a_z, T a_w) {
	return Matrix4<T>(1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		a_x, a_y, a_z, a_w);
}

template <class T>
Matrix4<T> Matrix4<T>::createTranslation(const Vector3<T> &a_vec, T a_w) {
	return Matrix4<T>(1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		a_vec.x, a_vec.y, a_vec.z, a_w);
}

template <class T>
Matrix4<T> Matrix4<T>::createRotation(T a_rot) {
	return Matrix4<T>((T)cos((double)a_rot), (T)sin((double)a_rot), 0, 0,
		(T)-sin((double)a_rot), (T)cos((double)a_rot), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);
}

template <class T>
Matrix4<T> Matrix4<T>::createScale(T a_x, T a_y, T a_z) {
	return Matrix4(
		a_x, 0, 0, 0,
		0, a_y, 0, 0,
		0, 0, a_z, 0,
		0, 0, 0, 1);
}
#pragma endregion

#pragma region Operators
template<class T>
Vector4<T> & Matrix4<T>::operator[](unsigned int a_index) {
	return v[a_index];
}

template<class T>
Matrix4<T> Matrix4<T>::operator=(const Matrix4 & rhs) {
	memcpy(m, rhs.m, sizeof(T) * 16);
	return *this;
}

template<class T>
Matrix4<T>::operator T*() { return m; }

template <class T>
Vector4<T> Matrix4<T>::operator * (const Vector4<T> &a_vec) const {
	return Vector4<T>(x1 * a_vec.x + y1 * a_vec.y + z1 * a_vec.z + w1 * a_vec.w,
		x2 * a_vec.x + y2 * a_vec.y + z2 * a_vec.z + w2 * a_vec.w,
		x3 * a_vec.x + y3 * a_vec.y + z3 * a_vec.z + w3 * a_vec.w,
		x4 * a_vec.x + y4 * a_vec.y + z4 * a_vec.z + w4 * a_vec.w);
}

template <class T>
Matrix4<T> Matrix4<T>::operator *(const Matrix4 &a_rhs) const {
	Matrix4<T> tmp;
	// We are in column major, so our memory is storing 'rows' of the column-vectors
	for (unsigned int c = 0; c < 4; c++) {
		for (unsigned int r = 0; r < 4; r++) {
			tmp.m_floats[c][r] = (m_floats[0][r] * a_rhs.m_floats[c][0] +
				m_floats[1][r] * a_rhs.m_floats[c][1] +
				m_floats[2][r] * a_rhs.m_floats[c][2] +
				m_floats[3][r] * a_rhs.m_floats[c][3]);
		}
	}

	return tmp;
}
#pragma endregion

#pragma region Class Methods
template <class T>
void  Matrix4<T>::set(T *a_ptr) {
}

template <class T>
void  Matrix4<T>::set(T a_x1, T a_x2, T a_x3, T a_x4,
	T a_y1, T a_y2, T a_y3, T a_y4,
	T a_z1, T a_z2, T a_z3, T a_z4,
	T a_w1, T a_w2, T a_w3, T a_w4) {
	x1 = a_x1; x2 = a_x2; x3 = a_x3; x4 = a_x4;
	y1 = a_y1; y2 = a_y2; y3 = a_y3; y4 = a_y4;
	z1 = a_z1; z2 = a_z2; z3 = a_z3; z4 = a_z4;
	w1 = a_w1; w2 = a_w2; w3 = a_w3; w4 = a_w4;
}

template <class T>
void Matrix4<T>::setRotateX(T a_rot) {
	set(1, 0, 0, 0,
		0, (T)cos((double)a_rot), (T)sin((double)a_rot), 0,
		0, (T)-sin((double)a_rot), (T)cos((double)a_rot), 0,
		0, 0, 0, 1);
}

template <class T>
void Matrix4<T>::setRotateY(T a_rot) {
	set((T)cos((double)a_rot), 0, (T)-sin((double)a_rot), 0,
		0, 1, 0, 0,
		(T)sin((double)a_rot), 0, (T)cos((double)a_rot), 0,
		0, 0, 0, 1);
}

template <class T>
void Matrix4<T>::setRotateZ(T a_rot) {
	set((T)cos((double)a_rot), (T)sin((double)a_rot), 0, 0,
		(T)-sin((double)a_rot), (T)cos((double)a_rot), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);
}

template <class T>
T Matrix4<T>::getRotationZ() {
	return (T)atan2((double)x2, (double)x1);
}
#pragma endregion

/*Instantiate every possible use of the template classes*/
template class Matrix4<float>;
template class Matrix4<int>;
template class Matrix4<double>;
template class Matrix4<long>;
template class Matrix4<short>;