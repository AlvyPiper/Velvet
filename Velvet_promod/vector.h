#pragma once
#include "velvet.h"


class Vector
{
public:
	Vector();
	Vector(float, float, float);

	float&	operator [] (int);
	Vector&	operator =  (const Vector&);

	Vector&	operator += (const Vector&);
	Vector&	operator -= (const Vector&);
	Vector&	operator *= (const Vector&);
	Vector&	operator *= (const float);
	Vector&	operator /= (const Vector&);
	Vector&	operator /= (const float);

	Vector	operator +  (const Vector&) const;
	Vector	operator -  (const Vector&) const;

	Vector	operator *  (const Vector&) const;
	Vector	operator *  (const float&)  const;

	Vector	operator /  (const Vector&) const;
	Vector	operator /  (const float&)  const;

	float	x, y, z;
};

inline Vector::Vector()
{
	x = y = z = 0.f;
}

inline Vector::Vector(float ix, float iy, float iz)
{
	x = ix;
	y = iy;
	z = iz;
}


inline Vector& Vector::operator = (const Vector &i)
{
	x = i.x;
	y = i.y;
	z = i.z;

	return *this;
}

inline Vector& Vector::operator += (const Vector &i)
{
	x += i.x;
	y += i.y;
	z += i.z;

	return *this;
}

inline Vector& Vector::operator -= (const Vector &i)
{
	x -= i.x;
	y -= i.y;
	z -= i.z;

	return *this;
}

inline Vector& Vector::operator *= (const Vector &i)
{
	x *= i.x;
	y *= i.y;
	z *= i.z;

	return *this;
}

inline Vector& Vector::operator *= (const float i)
{
	x *= i;
	y *= i;
	z *= i;

	return *this;
}

inline Vector& Vector::operator /= (const Vector &i)
{
	x /= i.x;
	y /= i.y;
	z /= i.z;

	return *this;
}

inline Vector& Vector::operator /= (const float i)
{
	x /= i;
	y /= i;
	z /= i;

	return *this;
}

inline Vector Vector::operator + (const Vector &i) const
{
	return Vector(x + i.x, y + i.y, z + i.z);
}

inline Vector Vector::operator - (const Vector &i) const
{
	return Vector(x - i.x, y - i.y, z - i.z);
}

inline Vector Vector::operator * (const Vector &i) const
{
	return Vector(x * i.x, y * i.y, z * i.z);
}

inline Vector Vector::operator * (const float &i) const
{
	return Vector(x * i, y * i, z * i);
}

inline Vector Vector::operator / (const Vector &i) const
{
	return Vector(x / i.x, y / i.y, z / i.z);
}

inline Vector Vector::operator / (const float &i) const
{
	return Vector(x / i, y / i, z / i);
}