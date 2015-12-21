#include "Vector2D.h"


Vector2D::Vector2D(){}

Vector2D::~Vector2D(){}

void Vector2D::normalize()
{
	float l = length();
	if (l > 0)
	{
		(*this) *= 1 / l;
	}
}

Vector2D& Vector2D::operator*=(float scalar)
{
	m_x *= scalar;
	m_y *= scalar;

	return *this;
}

Vector2D& Vector2D::operator/=(float scalar)
{
	m_x /= scalar;
	m_y /= scalar;

	return *this;
}