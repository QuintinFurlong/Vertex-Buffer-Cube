#include "Matrix3.h"

Matrix3::Matrix3():
	A11{ 0.0 },
	A12{ 0.0 },
	A13{ 0.0 },
	A21{ 0.0 },
	A22{ 0.0 },
	A23{ 0.0 },
	A31{ 0.0 },
	A32{ 0.0 },
	A33{ 0.0 }
{
}

Matrix3::Matrix3(Vector3Class t_row1, Vector3Class t_row2, Vector3Class t_row3) :
	A11{ t_row1.X() },
	A12{ t_row1.Y() },
	A13{ t_row1.Z() },
	A21{ t_row2.X() },
	A22{ t_row2.Y() },
	A23{ t_row2.Z() },
	A31{ t_row3.X() },
	A32{ t_row3.Y() },
	A33{ t_row3.Z() }
{
}

Matrix3::Matrix3(double t_A11, double t_A12, double t_A13,
	double t_A21, double t_A22, double t_A23, 
	double t_A31, double t_A32, double t_A33) :
	A11{ t_A11 },
	A12{ t_A12 },
	A13{ t_A13 },
	A21{ t_A21 },
	A22{ t_A22 },
	A23{ t_A23 },
	A31{ t_A31 },
	A32{ t_A32 },
	A33{ t_A33 }
{
}

Vector3Class Matrix3::Row(int i)
{
	switch (i)
	{
	case 0:
		return new Vector3Class(A11, A12, A13);
	case 1:
		return new Vector3Class(A21, A22, A23);
	case 2:
	default:
		return new Vector3Class(A31, A32, A33);
	}
}

Vector3Class Matrix3::Column(int i)
{
	switch (i)
	{
	case 0:
		return new Vector3Class(A11, A21, A31);
	case 1:
		return new Vector3Class(A12, A22, A32);
	case 2:
	default:
		return new Vector3Class(A13, A23, A33);
	}
}

Vector3Class Matrix3::operator*(Vector3Class V1)
{
	return new Vector3Class(A11 * V1.X() + A12 * V1.Y() + A13 * V1.Z(),
		A21 * V1.X() + A22 * V1.Y() + A23 * V1.Z(),
		A31 * V1.X() + A32 * V1.Y() + A33 * V1.Z());
}

Matrix3 Matrix3::Transpose()
{
	return Matrix3(A11, A21, A31,
		A12, A22, A32,
		A13, A23, A33);
}

Matrix3 Matrix3::operator+(Matrix3 M1)
{
	return Matrix3(M1.A11 + A11, M1.A12 + A12, M1.A13 + A13,
		M1.A21 + A21, M1.A22 + A22, M1.A23 + A23,
		M1.A31 + A31, M1.A32 + A32, M1.A33 + A33);
}

Matrix3 Matrix3::operator-(Matrix3 M1)
{
	return Matrix3(M1.A11 - A11, M1.A12 - A12, M1.A13 -A13,
		M1.A21 - A21, M1.A22 - A22, M1.A23 - A23,
		M1.A31 - A31, M1.A32 - A32, M1.A33 - A33);
}

Matrix3 Matrix3::operator*(double x)
{
	return Matrix3(A11 * x, A12 * x, A13 * x,
		A21 * x, A22 * x, A23 * x,
		A31 * x, A32 * x, A33 * x);
}

Matrix3 Matrix3::operator*(Matrix3 M1)
{
	return Matrix3(M1.Row(0) * Column(0), M1.Row(0) * Column(1), M1.Row(0) * Column(2),
		M1.Row(1) * Column(0), M1.Row(1) * Column(1), M1.Row(1) * Column(2),
		M1.Row(2) * Column(0), M1.Row(2) * Column(1), M1.Row(2) * Column(2));
}

double Matrix3::Determinant()
{
	return A11 * A22 * A33 - A11 * A32 * A23 + A21 * A32 * A13 - A31 * A22 * A13 + A31 * A12 * A23 - A21 * A12 * A33;
}

Matrix3 Matrix3::Inverse(Matrix3 M1)
{
	double det = M1.Determinant();
	if (det == 0)
		return Matrix3();
	else
	{
		double scale = 1 / det;
		Matrix3 answer = Matrix3();
		answer.A11 = scale * (M1.A22 * M1.A33 - M1.A23 * M1.A32); // ei-fh
		answer.A12 = scale * (M1.A13 * M1.A32 - M1.A12 * M1.A33); // ch-bi
		answer.A13 = scale * (M1.A12 * M1.A23 - M1.A13 * M1.A22); // ch-bi

		answer.A21 = scale * (M1.A23 * M1.A31 - M1.A21 * M1.A33); // fg-di
		answer.A22 = scale * (M1.A11 * M1.A33 - M1.A13 * M1.A31); // ai-cg
		answer.A23 = scale * (M1.A13 * M1.A21 - M1.A11 * M1.A23); // cd-af


		answer.A31 = scale * (M1.A21 * M1.A32 - M1.A22 * M1.A31); // dh-eg
		answer.A32 = scale * (M1.A12 * M1.A31 - M1.A11 * M1.A32); // bg-ah
		answer.A33 = scale * (M1.A11 * M1.A22 - M1.A12 * M1.A21); // ae-bd

		return answer;
	}
}

Matrix3 Matrix3::Rotation(int t_angle)
{
	double radians = acos(-1.0) / 180 * t_angle;
	return Matrix3(cos(radians), sin(radians), 0,
		-sin(radians), cos(radians), 0,
		0, 0, 1);
}

Matrix3 Matrix3::Translate(double dx, double dy)
{
	return Matrix3(1, 0, dx,
		0, 1, dy,
		0, 0, 1);
}

Matrix3 Matrix3::Scale(double dx, double dy)
{
	return Matrix3((double)dx / 100, 0, 0,
		0, (double)dy / 100, 0,
		0, 0, 1);
}

Matrix3 Matrix3::Neg(Matrix3 M1)
{
	return M1 * -1;
}

Matrix3 Matrix3::RotationX(int t_angle)
{
	double radians = acos(-1.0) / 180 * t_angle;
	return Matrix3(1, 0, 0,
		0, cos(radians), -sin(radians),
		0, sin(radians), cos(radians));
}

Matrix3 Matrix3::RotationY(int t_angle)
{
	double radians = acos(-1.0) / 180 * t_angle;
	return Matrix3(cos(radians), 0, sin(radians),
		0, 1, 0,
		-sin(radians), 0, cos(radians));
}

Matrix3 Matrix3::RotationZ(int t_angle)
{
	double radians = acos(-1.0) / 180 * t_angle;
	return Matrix3(cos(radians), -sin(radians), 0,
		sin(radians), cos(radians), 0,
		0, 0, 1);
}

Matrix3 Matrix3::Scale3D(int dx)
{
	return Matrix3((double)dx / 100, 0, 0,
		0, (double)dx / 100, 0,
		0, 0, (double)dx / 100);
}
