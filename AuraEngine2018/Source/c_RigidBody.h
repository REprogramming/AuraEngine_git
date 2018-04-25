#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#include "c_BaseComponent.h"
#include "AuraPhysicsEngine.h"

class c_RigidBody: public c_BaseComponent
{
public:
	c_RigidBody();
	virtual ~c_RigidBody();
	
	float mass = 0; 
	float bouciness = 1; 
	bool hasGravity = true; 
	bool isGrounded = false; 
	sf::Vector2f gravity = sf::Vector2f(0.0f, -9.8f); 

	sf::Vector2f currentVelocity;
	sf::Vector2f maxVelocity = sf::Vector2f(10.0f, 10.0f); 
	sf::Vector2f totalForces; 
	
	struct AABB
	{
		sf::Vector2f min; 
		sf::Vector2f max; 
	};

	AABB aabbBox; 

	void addForce(sf::Vector2f someForce);
	void stop(); 
	bool setIsGrounded();
	//void setBoundingBox(float sizeX, float sizeY);
	bool AABBCheck(AABB b);

	void onStart(); 
	void update(sf::RenderWindow* ptr_gameWindow);


};

