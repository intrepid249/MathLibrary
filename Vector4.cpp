#include "Vector4.h"
#include <math.h>

template <class T>
Vector4<T>::Vector4() : x(0), y(0), z(0), w(0) {}

template <class T>
Vector4<T>::Vector4(T a_x, T a_y, T a_z, T a_w) : x(a_x), y(a_y), z(a_z), w(a_w) {}

template <class T>
void Vector4<T>::get(T& a_x, T& a_y, T& a_z, T& a_w) const {
	a_x = x;
	a_y = y;
	a_z = z;
	a_w = w;
}

template <class T>
void Vector4<T>::set(const T& a_x, const T& a_y, const T& a_z, const T& a_w) {
	x = a_x;
	y = a_y;
	z = a_z;
	w = a_w;
}

#pragma region Arithmetic Operators
template <class T>
Vector4<T> Vector4<T>::operator + (const Vector4 &a_rhs) const {
	return Vector4<T>(x + a_rhs.x, y + a_rhs.y, z + a_rhs.z, w + a_rhs.w);
}

template <class T>
Vector4<T> Vector4<T>::operator - (const Vector4 &a_rhs) const {
	return Vector4<T>(x - a_rhs.x, y - a_rhs.y, z - a_rhs.z, w - a_rhs.w);
}

template <class T>
Vector4<T> Vector4<T>::operator * (const Vector4 &a_rhs) const {
	return Vector4<T>(x * a_rhs.x, y * a_rhs.y, z * a_rhs.z, w * a_rhs.w);
}

template <class T>
Vector4<T> Vector4<T>::operator / (const Vector4 &a_rhs) const {
	return Vector4<T>(x / a_rhs.x, y / a_rhs.y, z / a_rhs.z, w / a_rhs.w);
}

template <class T>
Vector4<T> Vector4<T>::operator * (const T a_rhs) const {
	return Vector4<T>(x * a_rhs, y * a_rhs, z * a_rhs, w * a_rhs);
}

template <class T>
Vector4<T> Vector4<T>::operator / (const T a_rhs) const {
	return Vector4<T>(x / a_rhs, y / a_rhs, z / a_rhs, w / a_rhs);
}

template <class T>
Vector4<T>& Vector4<T>::operator += (const Vector4 &a_rhs) {
	x += a_rhs.x;
	y += a_rhs.y;
	z += a_rhs.z;
	w += a_rhs.w;
	return *this;
}

template <class T>
Vector4<T>& Vector4<T>::operator -= (const Vector4 &a_rhs) {
	x -= a_rhs.x;
	y -= a_rhs.y;
	z -= a_rhs.z;
	w -= a_rhs.w;
	return *this;
}

template <class T>
Vector4<T>& Vector4<T>::operator *= (const Vector4 &a_rhs) {
	x *= a_rhs.x;
	y *= a_rhs.y;
	z *= a_rhs.z;
	w *= a_rhs.w;
	return *this;
}

template <class T>
Vector4<T>& Vector4<T>::operator /= (const Vector4 &a_rhs) {
	x /= a_rhs.x;
	y /= a_rhs.y;
	z /= a_rhs.z;
	w /= a_rhs.w;
	return *this;
}

template <class T>
Vector4<T>& Vector4<T>::operator *= (const T a_rhs) {
	x += a_rhs;
	y += a_rhs;
	z += a_rhs;
	w += a_rhs;
	return *this;
}

template <class T>
Vector4<T>& Vector4<T>::operator /= (const T a_rhs) {
	x /= a_rhs;
	y /= a_rhs;
	z /= a_rhs;
	w /= a_rhs;
	return *this;
}
#pragma endregion

#pragma region Comparitive Operators
template <class T>
bool Vector4<T>::operator == (const Vector4 &a_rhs) const {
	return (x == a_rhs.x && y == a_rhs.y && z == a_rhs.z && w == a_rhs.w);
}

template <class T>
bool Vector4<T>::operator != (const Vector4 &a_rhs) const {
	return (x != a_rhs.x || y != a_rhs.y || z != a_rhs.z || w != a_rhs.w);
}
#pragma endregion

#pragma region Base Operators
template <class T>
Vector4<T> Vector4<T>::operator -() const {
	return Vector4<T>(-x, -y, -z, -w);
}

template<class T>
Vector4<T>::operator T*() { return &x; }

template<class T>
T Vector4<T>::operator[](unsigned int index) {
	return v[index];
}

template<class T>
Vector4<T> Vector4<T>::operator=(const Vector4 & rhs) {
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	w = rhs.w;
	return *this;
}
#pragma endregion

#pragma region Class Methods
template <class T>
T Vector4<T>::magnitude() const {
	return (T)sqrt(double(x*x + y*y + z*z + w*w));
}

template <class T>
T Vector4<T>::dot(const Vector4 &a_rhs) const {
	return x * a_rhs.x + y * a_rhs.y + z * a_rhs.z + w * a_rhs.w;
}

template <class T>
Vector4<T> Vector4<T>::cross(const Vector4 &a_rhs) const {
	return Vector4<T>(y * a_rhs.z - z * a_rhs.y,
		z * a_rhs.x - x * a_rhs.z,
		x * a_rhs.y - y * a_rhs.x, w);
}

template <class T>
Vector4<T>& Vector4<T>::normalise() {
	T mag = magnitude();
	if (mag == 0) return(*this);
	x /= mag;
	y /= mag;
	z /= mag;
	w /= mag;

	return (*this);
}

template <class T>
Vector4<T> Vector4<T>::getNormalised() {
	T mag = magnitude();
	if (mag == 0) return Vector4<T>(x, y, z, w);
	return Vector4<T>(x / mag, y / mag, z / mag, w / mag);
}
#pragma endregion


/*Instantiate every possible use of the template classes*/
template class Vector4<float>;
template class Vector4<int>;
template class Vector4<double>;
template class Vector4<long>;
template class Vector4<short>;