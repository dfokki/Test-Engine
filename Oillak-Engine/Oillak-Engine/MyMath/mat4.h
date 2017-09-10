#pragma once
#include "Vector3.h"
#include "Vector4.h"
#include <ostream>

class mat4

	{
	public:

		mat4();
		mat4(const Vector4& column1, const Vector4& column2, const Vector4& column3, const Vector4& column4);
		mat4(const float a11, const float a12, const float a13, const float a14,
			const float a21, const float a22, const float a23, const float a24,
			const float a31, const float a32, const float a33, const float a34,
			const float a41, const float a42, const float a43, const float a44);
		~mat4();
		mat4(const mat4& mat4);

		const float* data();
		static mat4 identity();
		static mat4 createRotationX(const float rotation);
		static mat4 createRotationY(const float rotation);
		static mat4 createRotationZ(const float rotation);
		static mat4 createScale(const Vector3& scale);
		static mat4 createScale(const float scale);
		static mat4 createTranslation(const Vector3& translation);

		const Vector4& operator [](unsigned int index) const;
		mat4 operator *(const Vector4& vector);
		mat4 operator *(const mat4& mat4);
		float getdet();
		mat4 inverse();
		friend std::ostream& operator<<(std::ostream& os, const mat4& mat);
	private:

		Vector4 columns[4];

	};

