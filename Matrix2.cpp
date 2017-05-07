#include <Matrix2.h>
#include <Vector2.h>
#include <math.h>
#include <memory>

template <class T>
Matrix2<T>::Matrix2() {
	*this = createIdentity();
}

template <class T>
Matrix2<T>::Matrix2(T *a_ptr) :
	// This will store the axis-major 'colums' in memory as 'rows', so we can access
	// columns using the subscript [] operator
	x1(a_ptr[0]), x2(a_ptr[1]), // x and y elements of x-axis
	y1(a_ptr[2]), y2(a_ptr[3])	// x and y elements of y-axis
{
}

template <class T>
Matrix2<T>::Matrix2(T a_x1, T a_x2, T a_y1, T a_y2) :
	// This will store the axis-major 'colums' in memory as 'rows', so we can access
	// columns using the subscript [] operator
	x1(a_x1), x2(a_x2), // x and y elements of x-axis
	y1(a_y1), y2(a_y2)  // x and y elements of y-axis
{
}

template<class T>
Matrix2<T>::Matrix2(const Matrix2 & rhs) {
	v[0] = rhs.v[0];
	v[1] = rhs.v[1];
}

#pragma region Static Methods
template <class T>
Matrix2<T> Matrix2<T>::createIdentity() {
	return Matrix2<T>((T)1, (T)0, (T)0, (T)1);
}

template <class T>
Matrix2<T> Matrix2<T>::createTranslation(T a_x, T a_y) {
	return Matrix2<T>(1, 0, a_x, a_y);
}

template <class T>
Matrix2<T> Matrix2<T>::createTranslation(const Vector2<T> &a_vec) {
	return Matrix2<T>(1, 0, a_vec.x, a_vec.y);
}

template <class T>
Matrix2<T> Matrix2<T>::createRotation(T a_rot) {
	return Matrix2<T>(
		(T)cos((double)a_rot), (T)sin((double)a_rot),
		(T)-sin((double)a_rot), (T)cos((double)a_rot));
}

template <class T>
Matrix2<T> Matrix2<T>::createScale(T a_xScale, T a_yScale) {
	return Matrix2<T>(
		a_xScale, 0,
		0, a_yScale);
}
#pragma endregion

#pragma region Operators
template <class T>
Matrix2<T> Matrix2<T>::operator * (const Matrix2 &a_rhs) const {
	return Matrix2(x1*a_rhs.x1 + y1*a_rhs.x2, x2*a_rhs.x1 + y2*a_rhs.x2,
					x1*a_rhs.y1 + y1*a_rhs.y2, x2*a_rhs.y1 + y2*a_rhs.y2);
}

template <class T>
Matrix2<T>& Matrix2<T>::operator *=(const Matrix2 &a_rhs) {
	*this = *this * a_rhs;
	return *this;
}

template <class T>
Vector2<T> Matrix2<T>::operator * (const Vector2<T> &a_vec) const {
	return Vector2<T>(x1*a_vec.x + y1*a_vec.y,
		x2*a_vec.x + y2*a_vec.y);
}

template<class T>
Vector2<T> Matrix2<T>::operator[](unsigned int index) {
	return v[index];
}

template<class T>
Matrix2<T>& Matrix2<T>::operator=(const Matrix2 & rhs) {
	for (int i = 0; i < 4; ++i)
		m[i] = rhs.m[i];
	return *this;
}
#pragma endregion

#pragma region Class Methods
// rebuild the matrix
template <class T>
void Matrix2<T>::set(T a_x1, T a_x2, T a_y1, T a_y2) {
	x1 = a_x1; x2 = a_x2; y1 = a_y1; y2 = a_y2;
}

// rebuild the matrix - expects pointer to array of 9 Ts
template <class T>
void Matrix2<T>::set(T *a_ptr) {
	memcpy(m, &a_ptr, sizeof(T) * 4);
}

// only set the translation component of the matrix
template <class T>
void Matrix2<T>::setTranslation(T a_x, T a_y) {
	y1 = a_x; // x component of y-axis
	y2 = a_y; // y component of y-axis
}

// only set the translation component of the matrix
template <class T>
void Matrix2<T>::setTranslation(const Vector2<T> &a_vec) {
	y1 = a_vec.x; // x component of y-axis
	y2 = a_vec.y; // y component of y-axis
}

template <class T>
void Matrix2<T>::setRotateZ(T a_rot) {
	x1 = (T)cos((double)a_rot);
	x2 = (T)sin((double)a_rot);
	y1 = (T)-sin((double)a_rot);
	y2 = (T)cos((double)a_rot);
}

template <class T>
T Matrix2<T>::getRotationZ() {
	return (T)atan2((double)x2, (double)x1);
}

// add x and y onto the translation component of the matrix
template <class T>
void Matrix2<T>::translate(T a_x, T a_y) {
	y1 += a_x; // x component of y-axis
	y2 += a_y; // y component of y-axis
}

// add x and y onto the translation component of the matrix
template <class T>
void Matrix2<T>::translate(const Vector2<T> &a_vec) {
	y1 += a_vec.x; // x component of y-axis
	y2 += a_vec.y; // y component of y-axis
}

// returns the translation component of the matrix
template <class T>
Vector2<T> Matrix2<T>::getTranslation() const {
	return Vector2<T>(y1, y2);
}
#pragma endregion

/*Instantiate every possible use of the template classes*/
template class Matrix2<float>;
template class Matrix2<int>;
template class Matrix2<double>;
template class Matrix2<long>;
template class Matrix2<short>;