#pragma once
#include "vector3.h"

class mat3
{

public:
		mat3();
		mat3(const Vector3& column1, const Vector3& column2, const Vector3& column3);
		mat3(const float a11, const float a12, const float a13, const float a21, const float a22, const float a23, const float a31, const float a32, const float a33);
		~mat3();
		mat3(const mat3& _mat3);

		const float* data();
		static mat3 identity();
		static mat3 createRotation(const float rotation);
		static mat3 createScale(const Vector3& scale);
		static mat3 createTranslation(const Vector3& scale);
		mat3 Inverse(const mat3& _mat3);
		const Vector3& operator [](unsigned int index) const;
		mat3 operator *(const Vector3& vector);
		mat3 operator *(const mat3& _mat3);
		friend std::ostream& operator<<(std::ostream& os, const mat3& mat);

	private:

		Vector3 columns[3];
};

