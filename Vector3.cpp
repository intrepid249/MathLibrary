#include "Vector3.h"
#include <math.h>

Vector3::Vector3() : x(0), y(0), z(0) {
}

Vector3::Vector3(float a_x, float a_y, float a_z) : x(a_x), y(a_y), z(a_z) {
}

void Vector3::get(float& a_x, float& a_y, float& a_z) const {
	a_x = x;
	a_y = y;
	a_z = z;
	return;
}

void Vector3::set(const float& a_x, const float& a_y, const float& a_z) {
	x = a_x;
	y = a_y;
	z = a_z;
	return;
}

Vector3 Vector3::operator + (const Vector3 &a_rhs) const {
	return Vector3(x + a_rhs.x, y + a_rhs.y, z + a_rhs.z);
}

Vector3 Vector3::operator - (const Vector3 &a_rhs) const {
	return Vector3(x - a_rhs.x, y - a_rhs.y, z - a_rhs.z);
}

Vector3 Vector3::operator * (const Vector3 &a_rhs) const {
	return Vector3(x * a_rhs.x, y * a_rhs.y, z * a_rhs.z);
}

Vector3 Vector3::operator / (const Vector3 &a_rhs) const {
	return Vector3(x / a_rhs.x, y / a_rhs.y, z / a_rhs.z);
}

Vector3 Vector3::operator * (const float a_rhs) const {
	return Vector3(x * a_rhs, y * a_rhs, z * a_rhs);
}

Vector3 Vector3::operator / (const float a_rhs) const {
	return Vector3(x / a_rhs, y / a_rhs, z / a_rhs);
}

Vector3& Vector3::operator += (const Vector3 &a_rhs) {
	x += a_rhs.x;
	y += a_rhs.y;
	z += a_rhs.z;
	return *this;
}

Vector3& Vector3::operator -= (const Vector3 &a_rhs) {
	x -= a_rhs.x;
	y -= a_rhs.y;
	z -= a_rhs.z;
	return *this;
}

Vector3& Vector3::operator *= (const Vector3 &a_rhs) {
	x *= a_rhs.x;
	y *= a_rhs.y;
	z *= a_rhs.z;
	return *this;
}

Vector3& Vector3::operator /= (const Vector3 &a_rhs) {
	x /= a_rhs.x;
	y /= a_rhs.y;
	z /= a_rhs.z;
	*this = *this / a_rhs;
	return *this;

}

Vector3& Vector3::operator *= (const float a_rhs) {
	x *= a_rhs;
	y *= a_rhs;
	z *= a_rhs;
	return *this;
}

Vector3& Vector3::operator /= (const float a_rhs) {
	x /= a_rhs;
	y /= a_rhs;
	z /= a_rhs;
	return *this;
}

bool Vector3::operator == (const Vector3 &a_rhs) const {
	return (x == a_rhs.x && y == a_rhs.y && z == a_rhs.z);
}

bool Vector3::operator != (const Vector3 &a_rhs) const {
	return (x != a_rhs.x || y != a_rhs.y || z != a_rhs.z);
}

Vector3 Vector3::operator -() const {
	return Vector3(-x, -y, -z);
}

float Vector3::magnitude() const {
	return sqrtf(x*x + y*y + z*z);
}

float Vector3::dot(const Vector3 &a_rhs) const {
	return x * a_rhs.x + y * a_rhs.y + z * a_rhs.z;
}

Vector3 Vector3::cross(const Vector3 & a_rhs) const {
	return Vector3(y * a_rhs.z - z * a_rhs.y,
		z * a_rhs.x - x * a_rhs.z,
		x * a_rhs.y - y * a_rhs.x);

}

Vector3& Vector3::normalise() {
	float mag = magnitude();
	if (mag == 0) return(*this);
	x /= mag;
	y /= mag;
	z /= mag;

	return (*this);
}

Vector3 Vector3::getNormalised() {
	float mag = magnitude();
	if (mag == 0) return Vector3(x, y, z);
	return Vector3(x / mag, y / mag, z / mag);

}

Vector3 operator*(float a_scalar, const Vector3 & a_rhs) {
	return Vector3(a_rhs.x * a_scalar, a_rhs.y * a_scalar, a_rhs.z * a_scalar);
}

Vector3  Vector3::operator = (const Vector3 &a_rhs) {
	x = a_rhs.x;
	y = a_rhs.y;
	z = a_rhs.z;
	return *this;
}