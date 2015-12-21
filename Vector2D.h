#ifndef __Vector2D__
#define __Vector2D__

#include <math.h>
class Vector2D
{
public:
	
	Vector2D();
	Vector2D(float x, float y) : m_x(x), m_y(y) {}
	~Vector2D();

	float getX() { return m_x; }
	float getY() { return m_y; }

	void setX(float x) { m_x = x; }
	void setY(float y) { m_y = y; }

	float length() { return sqrt(m_x * m_x + m_y * m_y); }
	void normalize();	// Rend l'amplitude du vecteur égale à 1.

	// Addition
	Vector2D operator+(const Vector2D& v2) const { return Vector2D(m_x + v2.m_x, m_y + v2.m_y); }
	friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2)
	{
		v1.m_x += v2.m_x;
		v1.m_y += v2.m_y;

		return v1;
	}

	// Multiplication
	Vector2D operator*(float scalar) { return Vector2D(m_x * scalar, m_y * scalar); }
	Vector2D& operator *=(float scalar);

	// Soustraction
	Vector2D operator-(const Vector2D& v2) const { return Vector2D(m_x - v2.m_x, m_y - v2.m_y); }
	friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2)
	{
		v1.m_x -= v2.m_x;
		v1.m_y -= v2.m_y;

		return v1;
	}

	// Division
	Vector2D operator/(float scalar) { return Vector2D(m_x / scalar, m_y / scalar); }
	Vector2D& operator/=(float scalar);

private:
	float m_x;
	float m_y;
};

#endif; /* defined(_Vector2D_) */