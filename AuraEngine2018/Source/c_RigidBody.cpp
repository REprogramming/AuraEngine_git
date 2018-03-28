#include "c_RigidBody.h"



c_RigidBody::c_RigidBody(float objX, float objY)
{
	setBoundingBox(objX, objY); 
}


c_RigidBody::~c_RigidBody()
{
}

void c_RigidBody::addForce(sf::Vector2f someForce)
{
	totalForces += someForce; 
}

void c_RigidBody::stop()
{
	currentVelocity = sf::Vector2f(0, 0); 
	totalForces = sf::Vector2f(0, 0); 
}

bool c_RigidBody::setIsGrounded()
{
	this->isGrounded = true;
	return isGrounded;
}

void c_RigidBody::setBoundingBox(float sizeX, float sizeY)
{

	// TODO: Set the bounding box of this object.  How to get the transform/size of this object?	
}

bool c_RigidBody::AABBCheck(AABB b)
{
	// CHECKING FOR Seperating Axis Theorem (SAT)
	if (this->aabbBox.max.x < b.min.x || this->aabbBox.min.x > b.max.x)	{return false;}
	if (this->aabbBox.max.y < b.min.y || this->aabbBox.min.y > b.max.y) {return false;}

	// Collision has occurred
	return true; 
}


void c_RigidBody::onStart()
{
}
