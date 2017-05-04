#pragma once
#include <vector>
#include <Vector2.h>
#include <Vector3.h>

class Rectangle2D {
public:
	Rectangle2D(float x, float y, float width, float height);
	~Rectangle2D();

	void setPos(const Vector2 &pos);
	Vector2& getPos();

	void setSize(const Vector2 &size);
	Vector2& getSize();

	Vector3& getXNormal();
	Vector3& getYNormal();

protected:
	Vector2 m_position, m_size;
	std::vector<Vector2> m_points;
	Vector3 east, south, west, north;
	Vector3 xn, yn; // x and y normals
};

