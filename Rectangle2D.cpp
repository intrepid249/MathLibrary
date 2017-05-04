#include <Rectangle2D.h>



Rectangle2D::Rectangle2D(float x, float y, float width, float height) {
}


Rectangle2D::~Rectangle2D() {
}

void Rectangle2D::setPos(const Vector2 & pos) {
	m_position = pos;
}

Vector2 & Rectangle2D::getPos() {
	return m_position;
}

void Rectangle2D::setSize(const Vector2 & size) {
	m_size = size;
}

Vector2 & Rectangle2D::getSize() {
	return m_size;
}

Vector3& Rectangle2D::getXNormal() {
	return xn;
}

Vector3& Rectangle2D::getYNormal() {
	return yn;
}
