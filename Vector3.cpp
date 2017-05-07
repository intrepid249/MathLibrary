#include "Vector3.h"
#include <math.h>

template <class T>
Vector3<T>::Vector3() : x(0), y(0), z(0) {
}

template <class T>
Vector3<T>::Vector3(T a_x, T a_y, T a_z) : x(a_x), y(a_y), z(a_z) {
}

template <class T>
void Vector3<T>::get(T& a_x, T& a_y, T& a_z) const {
	a_x = x;
	a_y = y;
	a_z = z;
	return;
}

template <class T>
void Vector3<T>::set(const T& a_x, const T& a_y, const T& a_z) {
	x = a_x;
	y = a_y;
	z = a_z;
	return;
}

#pragma region Arithmetic Operators
template <class T>
Vector3<T> Vector3<T>::operator + (const Vector3 &a_rhs) const {
	return Vector3<T>(x + a_rhs.x, y + a_rhs.y, z + a_rhs.z);
}

template <class T>
Vector3<T> Vector3<T>::operator - (const Vector3 &a_rhs) const {
	return Vector3<T>(x - a_rhs.x, y - a_rhs.y, z - a_rhs.z);
}

template <class T>
Vector3<T> Vector3<T>::operator * (const Vector3 &a_rhs) const {
	return Vector3<T>(x * a_rhs.x, y * a_rhs.y, z * a_rhs.z);
}

template <class T>
Vector3<T> Vector3<T>::operator / (const Vector3 &a_rhs) const {
	return Vector3<T>(x / a_rhs.x, y / a_rhs.y, z / a_rhs.z);
}

template <class T>
Vector3<T> Vector3<T>::operator * (const T a_rhs) const {
	return Vector3<T>(x * a_rhs, y * a_rhs, z * a_rhs);
}

template <class T>
Vector3<T> Vector3<T>::operator / (const T a_rhs) const {
	return Vector3<T>(x / a_rhs, y / a_rhs, z / a_rhs);
}

template <class T>
Vector3<T>& Vector3<T>::operator += (const Vector3 &a_rhs) {
	*this = *this + a_rhs;
	return *this;
}

template <class T>
Vector3<T>& Vector3<T>::operator -= (const Vector3 &a_rhs) {
	*this = *this - a_rhs;
	return *this;
}

template <class T>
Vector3<T>& Vector3<T>::operator *= (const Vector3 &a_rhs) {
	*this = *this * a_rhs;
	return *this;
}

template <class T>
Vector3<T>& Vector3<T>::operator /= (const Vector3 &a_rhs) {
	*this = *this / a_rhs;
	return *this;

}

template <class T>
Vector3<T>& Vector3<T>::operator *= (const T a_rhs) {
	*this = *this * a_rhs;
	return *this;
}

template <class T>
Vector3<T>& Vector3<T>::operator /= (const T a_rhs) {
	*this = *this / a_rhs;
	return *this;
}
#pragma endregion

#pragma region Comparative Operators
template <class T>
bool Vector3<T>::operator == (const Vector3 &a_rhs) const {
	return (x == a_rhs.x && y == a_rhs.y && z == a_rhs.z);
}

template <class T>
bool Vector3<T>::operator != (const Vector3 &a_rhs) const {
	return (x != a_rhs.x || y != a_rhs.y || z != a_rhs.z);
}
#pragma endregion

#pragma region Base Operators
template <class T>
Vector3<T> Vector3<T>::operator -() const {
	return Vector3(-x, -y, -z);
}

template<class T>
Vector3<T>::operator T*() { return &x; }

template<class T>
T & Vector3<T>::operator[](unsigned int index) { return v[index]; }

template <class T>
Vector3<T> Vector3<T>::operator = (const Vector3 &a_rhs) {
	x = a_rhs.x;
	y = a_rhs.y;
	z = a_rhs.z;
	return *this;
}
#pragma endregion

#pragma region Class Methods
template <class T>
T Vector3<T>::magnitude() const {
	return (T)sqrt(double(x*x + y*y + z*z));
}

template <class T>
T Vector3<T>::dot(const Vector3 &a_rhs) const {
	return x * a_rhs.x + y * a_rhs.y + z * a_rhs.z;
}

template <class T>
Vector3<T> Vector3<T>::cross(const Vector3 & a_rhs) const {
	return Vector3<T>(y * a_rhs.z - z * a_rhs.y,
		z * a_rhs.x - x * a_rhs.z,
		x * a_rhs.y - y * a_rhs.x);

}

template <class T>
Vector3<T>& Vector3<T>::normalise() {
	T mag = magnitude();
	if (mag == 0) return(*this);
	x /= mag;
	y /= mag;
	z /= mag;

	return (*this);
}

template <class T>
Vector3<T> Vector3<T>::getNormalised() {
	T mag = magnitude();
	if (mag == 0) return Vector3<T>(x, y, z);
	return Vector3<T>(x / mag, y / mag, z / mag);

}
#pragma endregion

/*Instantiate every possible use of the template classes*/
template class Vector3<float>;
template class Vector3<int>;
template class Vector3<double>;
template class Vector3<long>;
template class Vector3<short>;