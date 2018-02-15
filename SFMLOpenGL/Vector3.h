#pragma once
#include <iostream>
#include <string>

class Vector3Class
{
	double x, y, z;
public:
	Vector3Class();
	Vector3Class(double t_x, double t_y, double t_z);
	Vector3Class(Vector3Class* t_vector);
	double X();
	double Y();
	double Z();
	void setX(double t_x);
	void setY(double t_y);
	void setZ(double t_z);
	double length();
	double lengthSquared();
	void normalise();

	Vector3Class operator +(Vector3Class V1);
	Vector3Class operator -(Vector3Class V1);
	Vector3Class operator -();
	double operator *(Vector3Class V1);
	Vector3Class operator *(double k);
	Vector3Class operator *(float k);
	Vector3Class operator *(int k);
	Vector3Class operator ^(Vector3Class V1);
	std::string ToString();
};