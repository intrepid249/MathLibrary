#include <Matrix2.h>
#include <Vector2.h>
#include <math.h>
#include <memory>

Matrix2::Matrix2() : x1(1), x2(0), y1(0), y2(1) {
}

Matrix2::Matrix2(float *a_ptr) :
	// This will store the axis-major 'colums' in memory as 'rows', so we can access
	// columns using the subscript [] operator
	x1(a_ptr[0]), x2(a_ptr[1]), // x and y elements of x-axis
	y1(a_ptr[2]), y2(a_ptr[3])	// x and y elements of y-axis
{
}

Matrix2::Matrix2(float a_x1, float a_x2, float a_y1, float a_y2) :
	// This will store the axis-major 'colums' in memory as 'rows', so we can access
	// columns using the subscript [] operator
	x1(a_x1), x2(a_x2), // x and y elements of x-axis
	y1(a_y1), y2(a_y2)  // x and y elements of y-axis
{
}

#pragma region Static Methods
Matrix2 Matrix2::createIdentity() {
	return Matrix2(1.0f, 0.0f,
		0.0f, 1.0f);
}

Matrix2 Matrix2::createTranslation(float a_x, float a_y) {
	return Matrix2(1.0f, 0.0f,
		a_x, a_y);
}

Matrix2 Matrix2::createTranslation(const Vector2 &a_vec) {
	return Matrix2(1.0f, 0.0f,
		a_vec.x, a_vec.y);
}

Matrix2 Matrix2::createRotation(float a_rot) {
	return Matrix2(
		cosf(a_rot), sinf(a_rot),
		-sinf(a_rot), cosf(a_rot));
}

Matrix2 Matrix2::createScale(float a_xScale, float a_yScale) {
	return Matrix2(
		a_xScale, 0.0f,
		0.0f, a_yScale);
}
#pragma endregion

#pragma region Operators
Matrix2  Matrix2::operator * (const Matrix2 &a_rhs) const {
	return Matrix2(x1*a_rhs.x1 + y1*a_rhs.x2, x2*a_rhs.x1 + y2*a_rhs.x2,
		x1*a_rhs.y1 + y1*a_rhs.y2, x2*a_rhs.y1 + y2*a_rhs.y2);
}

Matrix2& Matrix2::operator *=(const Matrix2 &a_rhs) {
	*this = *this * a_rhs;
	return *this;
}

Vector2 Matrix2::operator * (const Vector2 &a_vec) const {
	return Vector2(x1*a_vec.x + y1*a_vec.y,
		x2*a_vec.x + y2*a_vec.y);
}
#pragma endregion

#pragma region Class Methods
// rebuild the matrix
void Matrix2::set(float a_m1, float a_m2, float a_m3, float a_m4) {
	x1 = a_m1; x2 = a_m2; y1 = a_m3; y2 = a_m4;
}

// rebuild the matrix - expects pointer to array of 9 floats
void Matrix2::set(float *a_ptr) {
	memcpy(m, &a_ptr, sizeof(float) * 4);
}

// only set the translation component of the matrix
void Matrix2::setTranslation(float a_x, float a_y) {
	y1 = a_x; // x component of y-axis
	y2 = a_y; // y component of y-axis
}
// only set the translation component of the matrix
void Matrix2::setTranslation(const Vector2 &a_vec) {
	y1 = a_vec.x; // x component of y-axis
	y2 = a_vec.y; // y component of y-axis
}

void Matrix2::setRotateZ(float a_rot) {
	set(cosf(a_rot), sinf(a_rot),
		-sinf(a_rot), cosf(a_rot));
}

float Matrix2::getRotationZ() {
	return atan2f(x2, x1);
}

// add x and y onto the translation component of the matrix
void Matrix2::translate(float a_x, float a_y) {
	y1 += a_x; // x component of y-axis
	y2 += a_y; // y component of y-axis
}

// add x and y onto the translation component of the matrix
void Matrix2::translate(const Vector2 &a_vec) {
	y1 += a_vec.x; // x component of y-axis
	y2 += a_vec.y; // y component of y-axis
}

// returns the translation component of the matrix
Vector2 Matrix2::getTranslation() const {
	return Vector2(y1, y2);
}

#pragma endregion