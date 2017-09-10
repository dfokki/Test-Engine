#include "mat4.h"

mat4::mat4()
{
	*this = identity();
}

mat4::mat4(const Vector4& column1, const Vector4& column2, const Vector4& column3, const Vector4& column4)
{
	columns[0] = column1;
	columns[1] = column2;
	columns[2] = column3;
	columns[3] = column4;
}

mat4::mat4(const float a11, const float a12, const float a13, const float a14,
			const float a21, const float a22, const float a23, const float a24,
			const float a31, const float a32, const float a33, const float a34,
			const float a41, const float a42, const float a43, const float a44)
{
	columns[0] = Vector4(a11, a12, a13, a14);
	columns[1] = Vector4(a21, a22, a23, a24);
	columns[2] = Vector4(a31, a32, a33, a34);
	columns[3] = Vector4(a41, a42, a43, a44);
}

mat4::mat4(const mat4& mat4)
{
	columns[0] = mat4[0];
	columns[1] = mat4[1];
	columns[2] = mat4[2];
	columns[3] = mat4[3];
}

mat4::~mat4() {}

mat4 mat4::identity()
{
	return mat4(1, 0, 0, 0,
				0, 1, 0, 0,
				0, 0, 1, 0,
				0, 0, 0, 1);
}

mat4 mat4::createRotationX(const float rotation)
{
	return mat4(    1.0f,		0,					0,				0,
					0,		cos(rotation),		sin(rotation),	0,
					0,		-sin(rotation),		cos(rotation),	0,
					0,		0,					0,				1.0f);
}

mat4 mat4::createRotationY(const float rotation)
{
	return mat4(    cos(rotation),		0,				sin(rotation),		0,
					0,					1.0f,				0,					0,
					-sin(rotation),		0,				cos(rotation),		0,
					0,					0,				0,					1.0f);
}

mat4 mat4::createRotationZ(const float rotation)
{
	return mat4(	cos(rotation),		-sin(rotation),		0,		0,
					sin(rotation),		cos(rotation),		0,		0,
					0,					0,					1.0f,	0,
					0,					0,					0,		1.0f);
}

mat4 mat4::createScale(const Vector3& scale)
{
	return mat4(	scale.x,	0,			0,			0,
					0,			scale.y,	0,			0,
					0,			0,			scale.z,	0,
					0,			0,			0,			1.0f);
}

mat4 mat4::createScale(const float scale)
{
	return mat4(	1,	0,	0,	0,
					0,	1,	0,	0,
					0,	0,	1,	0,
					0,	0,	0,	1.0f/scale);
}

mat4 mat4::createTranslation(const Vector3& translation)
{
	return mat4(	1.0f,			0,				0,				0,
					0,				1.0f,			0,				0,
					0,				0,				1.0f,			0,
					translation.x,	translation.y,	translation.z,	1.0f);
}

const float* mat4::data()
{
	return &columns[0].x;
}

const Vector4& mat4::operator [](const unsigned int index) const
{
	return columns[index];
}

mat4 mat4::operator *(const mat4& _mat4)
{
	return mat4(    _mat4[0][0] * columns[0][0] + _mat4[0][1] * columns[1][0] + _mat4[0][2] * columns[2][0] + _mat4[0][3] * columns[3][0],
					_mat4[0][0] * columns[0][1] + _mat4[0][1] * columns[1][1] + _mat4[0][2] * columns[2][1] + _mat4[0][3] * columns[3][1],
					_mat4[0][0] * columns[0][2] + _mat4[0][1] * columns[1][2] + _mat4[0][2] * columns[2][2] + _mat4[0][3] * columns[3][2],
					_mat4[0][0] * columns[0][3] + _mat4[0][1] * columns[1][3] + _mat4[0][2] * columns[2][3] + _mat4[0][3] * columns[3][3],
												  															  
					_mat4[1][0] * columns[0][0] + _mat4[1][1] * columns[1][0] + _mat4[1][2] * columns[2][0] + _mat4[1][3] * columns[3][0],
					_mat4[1][0] * columns[0][1] + _mat4[1][1] * columns[1][1] + _mat4[1][2] * columns[2][1] + _mat4[1][3] * columns[3][1],
					_mat4[1][0] * columns[0][2] + _mat4[1][1] * columns[1][2] + _mat4[1][2] * columns[2][2] + _mat4[1][3] * columns[3][2],
					_mat4[1][0] * columns[0][3] + _mat4[1][1] * columns[1][3] + _mat4[1][2] * columns[2][3] + _mat4[1][3] * columns[3][3],
												  															  
					_mat4[2][0] * columns[0][0] + _mat4[2][1] * columns[1][0] + _mat4[2][2] * columns[2][0] + _mat4[2][3] * columns[3][0],
					_mat4[2][0] * columns[0][1] + _mat4[2][1] * columns[1][1] + _mat4[2][2] * columns[2][1] + _mat4[2][3] * columns[3][1],
					_mat4[2][0] * columns[0][2] + _mat4[2][1] * columns[1][2] + _mat4[2][2] * columns[2][2] + _mat4[2][3] * columns[3][2],
					_mat4[2][0] * columns[0][3] + _mat4[2][1] * columns[1][3] + _mat4[2][2] * columns[2][3] + _mat4[2][3] * columns[3][3],
												  															  
					_mat4[3][0] * columns[0][0] + _mat4[3][1] * columns[1][0] + _mat4[3][2] * columns[2][0] + _mat4[3][3] * columns[3][0],
					_mat4[3][0] * columns[0][1] + _mat4[3][1] * columns[1][1] + _mat4[3][2] * columns[2][1] + _mat4[3][3] * columns[3][1],
					_mat4[3][0] * columns[0][2] + _mat4[3][1] * columns[1][2] + _mat4[3][2] * columns[2][2] + _mat4[3][3] * columns[3][2],
					_mat4[3][0] * columns[0][3] + _mat4[3][1] * columns[1][3] + _mat4[3][2] * columns[2][3] + _mat4[3][3] * columns[3][3]
				);

}
float mat4::getdet()
{
	return 0;
}

mat4 mat4::inverse()
{
	return mat4{};
}
std::ostream& operator<<(std::ostream& os, const mat4& mat)
	{

		os << mat.columns[0]<<"\n" <<mat.columns[1]<<"\n"<<mat.columns[2]<<"\n"<<mat.columns[3]<<"\n \n";
		return os;
	}