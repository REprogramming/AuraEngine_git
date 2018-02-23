#include "c_Transform.h"


float x;
float y;
float z;
float rotateX;
float rotateY; 
float rotateZ; 
float scaleX;
float scaleY; 
float scaleZ; 
float alpha;


c_Transform::c_Transform()
{
}

c_Transform::~c_Transform() // DESTRUCTOR
{
}


void c_Transform::translate(float x, float y)
{

}

void c_Transform::rotate(float x, float y)
{
	sf::Transform rotation;
	rotation.rotate(x); 
	rotation.rotate(y); 	

	// now put it in a transformation matrix
}

void c_Transform::scale(float x, float y)
{	
	myScale.x *= x;
	myScale.y *= y; 	
}

