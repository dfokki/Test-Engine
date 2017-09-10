#include "mat3.h"

//TODO: recheck 
mat3::mat3()
{
	*this = identity();
}

mat3::mat3(const Vector3& column1, const Vector3& column2, const Vector3& column3)
{
	columns[0] = column1;
	columns[1] = column2;
	columns[2] = column3;
}

mat3::mat3(const float a11, const float a12, const float a13, const float a21, const float a22, const float a23, const float a31, const float a32, const float a33)
{
	columns[0] = Vector3(a11, a12, a13);
	columns[1] = Vector3(a21, a22, a23);
	columns[2] = Vector3(a31, a32, a33);
}

mat3::mat3(const mat3& Mat3)
{
	columns[0] = Mat3[0];
	columns[1] = Mat3[1];
	columns[2] = Mat3[2];
}

mat3::~mat3() {}

mat3 mat3::identity()
{
	return mat3(1, 0, 0,
				0, 1, 0,
				0, 0, 1);
}

mat3 mat3::createRotation(const float rotation)
{
	return mat3(	cos(rotation),	sin(rotation),	0,
					-sin(rotation),	cos(rotation),	0,
					0,				0,				1.0f	);
}

mat3 mat3::createScale(const Vector3& scale)
{
	
	return mat3(	scale.x,	0,			0,
					0,			scale.y,	0,
					0,			0,			scale.z	);
}

mat3 mat3::createTranslation(const Vector3& translation)
{
	return mat3(	1.0f,			0,				0,
					0,				1.0f,			0,
					translation.x,	translation.y,	translation.z	);
}

const float* mat3::data()
{
	return &columns[0].x;
}

const Vector3& mat3::operator [](const unsigned int index) const
{
	return columns[index];
}

mat3 mat3::operator *(const mat3& _mat3)
{
	return mat3(	_mat3[0][0] * columns[0][0] + _mat3[0][1] * columns[1][0] + _mat3[0][2] * columns[2][0],
					_mat3[0][0] * columns[0][1] + _mat3[0][1] * columns[1][1] + _mat3[0][2] * columns[2][1],
					_mat3[0][0] * columns[0][2] + _mat3[0][1] * columns[1][2] + _mat3[0][2] * columns[2][2],
												  						
					_mat3[1][0] * columns[0][0] + _mat3[1][1] * columns[1][0] + _mat3[1][2] * columns[2][0],
					_mat3[1][0] * columns[0][1] + _mat3[1][1] * columns[1][1] + _mat3[1][2] * columns[2][1],
					_mat3[1][0] * columns[0][2] + _mat3[1][1] * columns[1][2] + _mat3[1][2] * columns[2][2],
												  							
					_mat3[2][0] * columns[0][0] + _mat3[2][1] * columns[1][0] + _mat3[2][2] * columns[2][0],
					_mat3[2][0] * columns[0][1] + _mat3[2][1] * columns[1][1] + _mat3[2][2] * columns[2][1],
					_mat3[2][0] * columns[0][2] + _mat3[2][1] * columns[1][2] + _mat3[2][2] * columns[2][2]
				);
}

mat3 mat3::Inverse(const mat3& _mat3)
{
	 float OneDividedByDet (
							1 /(
								 _mat3[0][0] * _mat3[1][1] * _mat3[2][2] +
								 _mat3[1][0] * _mat3[2][1] * _mat3[0][2] +
								 _mat3[2][0] * _mat3[0][1] * _mat3[1][2] -
								 _mat3[0][0] * _mat3[2][1] * _mat3[1][2] -
								 _mat3[2][0] * _mat3[1][1] * _mat3[0][2] -
								 _mat3[1][0] * _mat3[0][1] * _mat3[2][2]
								) 
							);


	return	mat3(	OneDividedByDet * (columns[1][2] * columns[2][2] - columns[1][2] * columns[2][1]) , 
					OneDividedByDet * (columns[0][2] * columns[2][1] - columns[0][1] * columns[2][2]) , 
					OneDividedByDet * (columns[0][1] * columns[1][2] - columns[0][2] * columns[1][1]) , 
								 
					OneDividedByDet * (columns[1][2] * columns[2][0] - columns[0][1] * columns[2][2]) , 
					OneDividedByDet * (columns[0][0] * columns[2][2] - columns[0][2] * columns[2][0]) , 
					OneDividedByDet * (columns[0][2] * columns[1][1] - columns[0][0] * columns[1][2]) , 
								 
					OneDividedByDet * (columns[1][0] * columns[2][1] - columns[1][1] * columns[2][0]) , 
					OneDividedByDet * (columns[0][1] * columns[2][0] - columns[0][0] * columns[2][1]) , 
					OneDividedByDet * (columns[0][0] * columns[1][1] - columns[0][1] * columns[1][1])  
				);
}

std::ostream& operator<<(std::ostream& os, const mat3& mat)
	{
		//os << " (" << mat[0][0]<<"," <<mat[0][1]<<","<<mat[0][2]<<"\n"<< mat[1][0]<<"," <<mat[1][1]<<","<<mat[1][2] << mat[2][0]<<"\n" <<mat[2][1]<<","<<mat[2][2]<<"\n )";
		os << mat.columns[0]<<"\n" <<mat.columns[1]<<"\n"<<mat.columns[2]<<"\n \n";
		return os;
	}