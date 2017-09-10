#include "Vector4.h"
#include <math.h>

Vector4::Vector4():
	x(0),
	y(0),
	z(0),
	w(0)
{}

Vector4::~Vector4() {}

Vector4::Vector4(float x, float y, float z, float w):
	x(x),
	y(y),
	z(z),
	w(w)
{}

Vector4::Vector4(const Vector4& vector):
	x(vector.x),
	y(vector.y),
	z(vector.z),
	w(vector.w)
{}

float Vector4::magnitude() const
{
	return (sqrt(x*x + y*y + z*z + w*w));
}

void Vector4::normalize()
{
	*this = *this / magnitude();
}

Vector4 Vector4::operator +(const Vector4& vector) const
{
	return Vector4(x + vector.x, y + vector.y, z + vector.z, w + vector.w);
}

Vector4 Vector4::operator -(const Vector4& vector) const
{
	return Vector4(x - vector.x, y - vector.y, z - vector.z, w - vector.w);
}

Vector4 Vector4::operator *(const float scalar) const
{
	return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
}

Vector4 Vector4::operator /(const float scalar) const
{
	return Vector4(x / scalar, y / scalar, z / scalar, w / scalar);
}

Vector4& Vector4::operator =(const Vector4& vector)
{
	if(this != &vector)
	{
		x = vector.x;
		y = vector.y;
		z = vector.z;
		w = vector.w;
	}

	return *this;
}

const float& Vector4::operator [](const unsigned int index) const
{
	return (&x)[index];
}

Vector4 Vector4::zero()
{
	return Vector4();
}

	std::ostream& operator<<(std::ostream& os, const Vector4& vec)
	{
		os << "(" << vec.x<<"," <<vec.y<<","<<vec.z<<","<<vec.w<<")";
		return os;
	}
