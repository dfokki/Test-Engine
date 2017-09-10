#pragma once

#include <iostream>
#include <cassert>
class Vector4
{
	public:

		Vector4();
		Vector4(float x, float y, float z, float w);
		~Vector4();
		Vector4(const Vector4& vector);

		float x;
		float y;
		float z;
		float w;

		float magnitude() const;
		void normalize();

		Vector4 operator +(const Vector4& vector) const;
		Vector4 operator -(const Vector4& vector) const;
		Vector4 operator *(const float scalar) const;
		Vector4 operator /(const float scalar) const;
		Vector4& operator =(const Vector4& vector);
		const float& operator [](const unsigned int index) const;
		friend std::ostream& operator<<(std::ostream& os, const Vector4& vec);
		static Vector4 zero();
};

