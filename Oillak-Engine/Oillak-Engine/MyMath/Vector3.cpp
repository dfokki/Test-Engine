#include "Vector3.h"

#include <cmath>

Vector3::Vector3()
	:x(0), y(0), z(0)
{ }

Vector3::Vector3(float X, float Y,float Z)
	: x(X), y(Y),z(Z)
{ }

Vector3::Vector3(const Vector3& other)
	:x(other.x), y(other.y), z(other.z)
{ }

Vector3::~Vector3()
{ }

void Vector3::Normalize()
{
	float magnitude = this->GetMagnitude();

	this->x /= magnitude;
	this->y /= magnitude;
	this->z /= magnitude;
}

float::Vector3::GetMagnitudeSqrd() const
{
	return x*x + y*y+ z*z;
}

	float Vector3::GetMagnitude() const
{
	return sqrt(GetMagnitudeSqrd());
}

float Vector3::DotProduct(const Vector3& other)
{
	return this->x * other.x + this->y * other.y+this->z*other.z;
}

float Vector3::CrossProduct(const Vector3& other)
{
	return (this->x * other.y) - (this->y * other.x) - (this->z * other.z);
}

float Vector3::AngleBetween(const Vector3& other)
{
	float dot = this->DotProduct(other);
	
	dot /= this->GetMagnitude();
	dot /= other.GetMagnitude();

	return acos(dot);
}

Vector3& Vector3::operator+=(const Vector3& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	//paluu arvo vector3 referenssi
	return *this;

}

Vector3 operator+(const Vector3& lhs, const Vector3& rhs)
{
	return Vector3(lhs.x +rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);

}

Vector3& Vector3::operator-=(const Vector3& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;

	//paluu arvo vector3 referenssi
	return *this;

}

Vector3 operator-(const Vector3& lhs, const Vector3& rhs)
{
	return Vector3(lhs.x - rhs.x, lhs.y - rhs.y,lhs.z + rhs.z);


}

Vector3& Vector3::operator*=(const Vector3& rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;

	//paluu arvo vektor3 referenssi
	return *this;

}

Vector3 operator*(const Vector3& lhs,const float rhs)
{
	//HÖPÖHÖPÖ
	return Vector3(lhs.x * rhs, lhs.y * rhs,lhs.z * rhs);
}

bool Vector3::operator==(const Vector3& other) const
{
	return (x == other.x && y == other.y && z == other.z);
}

bool Vector3::operator!=(const Vector3& other) const
{
	return (x != other.x || y != other.y || z != other.z);
	//return !(*this == other);
}



	Vector3& Vector3::operator=(const Vector3& other)

	{
		if (this != &other)
		{
			x=other.x;
			y=other.y;
			z=other.z;
		}
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const Vector3& vec)
	{
		os << "(" << vec.x<<"," <<vec.y<<","<<vec.z<<")";
		return os;
	}

	const float& Vector3::operator[](const unsigned int index) const

	{
		//assert = varmista tämä, jos ei niin kaataa ohjelman ja näyttää mitä sen sisällä on. toimii vain Debug
		assert(index < 2);

		return(&x)[index];
		
	}