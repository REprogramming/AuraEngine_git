#include "c_Transform.h"

float x;
float y;
float z;
float alpha;


c_Transform::c_Transform() // CONSTRUCTOR
{
	vec3(0, 0, 0);
	vecUI3(0.0f, 0.0f, 0.0f, 0.0f);
}


c_Transform::~c_Transform() // DESTRUCTOR
{
}

void c_Transform::vec2(float x, float y)
{
	x = x;
	y = y;
}

void c_Transform::vec3(float x, float y, float z)
{
	x = x;
	y = y;
	z = z;
}

void c_Transform::vecUI2(float x, float y, float alpha)
{
	x = x;
	y = y;
	alpha = alpha;
}

void c_Transform::vecUI3(float x, float y, float z, float alpha)
{
	x = x;
	y = y;
	z = z;
	alpha = alpha;
}

void c_Transform::setX(float x)
{
	x = x;
}

void c_Transform::setY(float y)
{
	y = y;
}

void c_Transform::setZ(float z)
{
	z = z;
}

void c_Transform::setAlpha(float alpha)
{
	alpha = alpha;
}

void c_Transform::update()
{
	std::cout << "Updating Transform component" << std::endl; 
}
