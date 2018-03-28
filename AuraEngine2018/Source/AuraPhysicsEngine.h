#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>
#include <vector>

#include "c_RigidBody.h"

 class AuraPhysicsEngine
{
	public:
		AuraPhysicsEngine();
		~AuraPhysicsEngine();

	
		struct CollisionPair
		{			
			//c_RigidBody rbA; 
			//c_RigidBody rbB;
		};

		struct CollisionInfo
		{
			sf::Vector2f collisionNormal; 
			float penetration; 
		};

		/*void addRigidBody(c_RigidBody* rb);
		void integrateBodies(float dT); 
		bool isGrounded(c_RigidBody* rb);
		void checkCollisions(); 
		void resolveCollisions(); 
		void updatePhysics(); 
		void fixedUpdate();*/
			
		//static std::map<CollisionPair, CollisionInfo> collisions;
		//static std::vector<c_RigidBody*> rigidBodiesList;
};

