#pragma once
#include "Vector3.h"
#include <math.h>

class Matrix3
{
	double A11, A12, A13,
		A21, A22, A23,
		A31, A32, A33;
public:
	Matrix3();
	Matrix3(Vector3Class t_row1, Vector3Class t_row2, Vector3Class t_row3);
	Matrix3(double t_A11, double t_A12, double t_A13,
		double t_A21, double t_A22, double t_A23,
		double t_A31, double t_A32, double t_A33);

	Vector3Class Row(int i);
	Vector3Class Column(int i);

	Vector3Class operator *(Vector3Class V1);
	Matrix3 Transpose();
	Matrix3 operator +(Matrix3 M1);
	Matrix3 operator -(Matrix3 M1);
	Matrix3 operator *(double x);
	Matrix3 operator *(Matrix3 M1);
	double Determinant();
	Matrix3 Inverse(Matrix3 M1);
	Matrix3 Rotation(int t_angle);
	Matrix3 Translate(double dx, double dy);
	Matrix3 Scale(double dx, double dy);
	Matrix3 Neg(Matrix3 M1);

	Matrix3 RotationX(int _angle);
	Matrix3 RotationY(int _angle);
	Matrix3 RotationZ(int _angle);
	Matrix3 Scale3D(int dx);
};