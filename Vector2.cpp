#include "Vector2.h"
#include <math.h> 

template <class T>
Vector2<T>::Vector2() : x(0), y(0) {}

template <class T>
Vector2<T>::Vector2(T a_x, T a_y) : x(a_x), y(a_y) {}

template <class T>
Vector2<T>::Vector2(const Vector2 & a_rhs) : x(a_rhs.x), y(a_rhs.y) {}

#pragma region Base Operators
template <class T>
Vector2<T>& Vector2<T>::operator = (const Vector2& a_rhs) {
	x = a_rhs.x;
	y = a_rhs.y;
	return *this;
}

template<class T>
Vector2<T>::operator T*() { return &x; }

template<class T>
Vector2<T> Vector2<T>::operator-() const {
	return Vector2<T>(-x, -y);
}
template<class T>
T Vector2<T>::operator[](unsigned int index) {
	return v[index];
}
#pragma endregion

#pragma region Comparative Operators
template<class T>
bool Vector2<T>::operator==(const Vector2 & rhs) {
	return false;
}

template<class T>
bool Vector2<T>::operator!=(const Vector2 & rhs) {
	return false;
}
#pragma endregion

#pragma region Arithmetic Operators
template <class T>
Vector2<T> Vector2<T>::operator + (const Vector2& a_rhs) const {
	return Vector2(x + a_rhs.x, y + a_rhs.y);
}

template <class T>
Vector2<T> Vector2<T>::operator - (const Vector2& a_rhs) const {
	return Vector2<T>(x - a_rhs.x, y - a_rhs.y);
}

template <class T>
Vector2<T>& Vector2<T>::operator += (const Vector2& a_rhs) {
	x += a_rhs.x;
	y += a_rhs.y;
	return *this;
}

template <class T>
Vector2<T>& Vector2<T>::operator -= (const Vector2& a_rhs) {
	x -= a_rhs.x;
	y -= a_rhs.y;
	return *this;
}

template <class T>
Vector2<T> Vector2<T>::operator * (T a_scalar) const {
	return Vector2<T>(x * a_scalar, y * a_scalar);
}

template <class T>
Vector2<T>& Vector2<T>::operator *= (T a_scalar) {
	x *= a_scalar;
	y *= a_scalar;
	return *this;
}
#pragma endregion

#pragma region Class Methods
template <class T>
T Vector2<T>::magnitude() {
	return (T)sqrt(double(x*x + y*y));
}

template <class T>
Vector2<T> Vector2<T>::normalise() {
	T mag = magnitude();
	if (mag == 0) return *this;
	x /= mag;
	y /= mag;
	return *this;
}

template <class T>
Vector2<T> Vector2<T>::getNormal() {
	T mag = magnitude();
	if (mag == 0) return Vector2(x, y);
	return Vector2(x / mag, y / mag);
}

template <class T>
T Vector2<T>::dot(const Vector2& a_rhs) {
	return x * a_rhs.x + y * a_rhs.y;
}
#pragma endregion

/*Instantiate every possible use of the template classes*/
template class Vector2<float>;
template class Vector2<int>;
template class Vector2<double>;
template class Vector2<long>;
template class Vector2<short>;