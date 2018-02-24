
#include "c_Transform.h"


c_Transform::c_Transform()
{
}

c_Transform::~c_Transform() 
{
}

void c_Transform::translate(float x, float y)
{	
	this->myPosition.x += x;
	this->myPosition.y += y; 
	
	sf::Transform t; 
	t.translate(myPosition.x, myPosition.y); 
}

void c_Transform::rotate(float degrees)
{	
	sf::Transform obj;
	obj.rotate(degrees);
}

void c_Transform::scale(float x, float y)
{	
	myScale.x *= x;
	myScale.y *= y; 	

	sf::Transform t;
	t.scale(myScale.x, myScale.y);
}

