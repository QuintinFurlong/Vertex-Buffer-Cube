#include "Vector3.h"

Vector3Class::Vector3Class() :
	x(0.0),
	y(0.0),
	z(0.0)
{
}

Vector3Class::Vector3Class(double t_x, double t_y, double t_z):
	x(t_x),
	y(t_y),
	z(t_z)
{
}

Vector3Class::Vector3Class(Vector3Class* t_vec):
	x(t_vec->x),
	y(t_vec->y),
	z(t_vec->z)
{
}

double Vector3Class::X()
{
	return x;
}

double Vector3Class::Y()
{
	return y;
}

double Vector3Class::Z()
{
	return z;
}

void Vector3Class::setX(double t_x)
{
	x = t_x;
}

void Vector3Class::setY(double t_y)
{
	y = t_y;
}

void Vector3Class::setZ(double t_z)
{
	z = t_z;
}

double Vector3Class::length()
{
	return std::sqrt(x*x + y*y + z* z);
}

double Vector3Class::lengthSquared()
{
	return (x*x + y*y + z* z);
}

void Vector3Class::normalise()
{
	if (length() > 0.0)
	{
		const double orignalLength = length();
		x /= orignalLength;
		y /= orignalLength;
		z /= orignalLength;
	}
}

Vector3Class Vector3Class::operator+(Vector3Class V1)
{
	return new Vector3Class(V1.x + x, V1.y + y, V1.z + z);
}

Vector3Class Vector3Class::operator-(Vector3Class V1)
{
	return new Vector3Class(V1.x - x, V1.y - y, V1.z - z);
}

Vector3Class Vector3Class::operator-()
{
	return new Vector3Class(-x, -y, -z);
}

double Vector3Class::operator*(Vector3Class V1)
{
	return (V1.x * x + V1.y * y + V1.z * z);
}

Vector3Class Vector3Class::operator*(double k)
{
	return new Vector3Class(x * (float)k, y * (float)k, z * (float)k);
}

Vector3Class Vector3Class::operator*(float k)
{
	return new Vector3Class(x * k, y * k, z * k);
}

Vector3Class Vector3Class::operator*(int k)
{
	return new Vector3Class(x * k, y * k, z * k);
}

Vector3Class Vector3Class::operator^(Vector3Class V1)
{
	return new Vector3Class(V1.y * z - V1.z * y, V1.z * x - V1.x * z, V1.x * y - V1.y * x);
}

std::string Vector3Class::ToString()
{
	return "(" + std::to_string(x)  + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
}
