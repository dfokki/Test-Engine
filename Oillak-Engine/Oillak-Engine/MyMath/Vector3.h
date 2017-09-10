#ifndef Vector3_H
#define Vector3_H

#include <iostream>
#include <cassert>

class Vector3
{
public:
	Vector3();
	Vector3(float, float,float);
	Vector3(const Vector3& other);

	~Vector3();

	void Normalize();

	float GetMagnitude() const;
	float GetMagnitudeSqrd() const;

	float DotProduct(const Vector3& other);
	float CrossProduct(const Vector3& other);
	float AngleBetween(const Vector3& other);

	float x, y,z;

public: //operators

	Vector3& operator+=(const Vector3& rhs);
	
	friend Vector3 operator+(const Vector3& lhs, const Vector3& rhs);


	Vector3& operator-=(const Vector3& rhs);

	friend Vector3 operator-(const Vector3& lhs, const Vector3& rhs);


	Vector3& operator*=(const Vector3& rhs);


	friend Vector3 operator*(const Vector3& lhs, const float rhs);

	bool operator==(const Vector3& other) const;

	bool operator!=(const Vector3& other) const;

	Vector3& operator=(const Vector3& other);

	friend std::ostream& operator<<(std::ostream& os, const Vector3& vec);

	const float& operator[](const unsigned int index) const;
};
#endif