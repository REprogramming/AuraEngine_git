#pragma once

#include<iostream>
#include<vector>
#include<cstdlib>


#include "c_BaseComponent.h"
#include "c_Transform.h"
#include "c_Input.h"
#include "c_RigidBody.h"


class Asteroid: public c_BaseComponent
{
public:
	Asteroid();
	~Asteroid();
	sf::CircleShape mAsteroid; 	
	sf::CircleShape draw(); 
	void c_update(); 
	
private:
	float radius; 
	float speed; 
	float positionX; 
	float positionY; 	
};

