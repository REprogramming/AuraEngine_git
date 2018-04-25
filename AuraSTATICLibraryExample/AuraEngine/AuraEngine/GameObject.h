#pragma once

#include<iostream>
#include<vector>

#include "c_BaseComponent.h"
#include "c_Transform.h"
#include "c_Input.h"
#include "c_RigidBody.h"
#include "c_Asteroid.h"
#include "c_SpriteRenderer.h"


namespace Aura{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		enum typeOfComponent { TRANSFORM, INPUT, RIGIDBODY, ASTEROID, SPRITE_RENDERER };

		std::vector<c_BaseComponent*> componentsBanner;

		void addComponent(typeOfComponent someComponent);
		void removeComponent(typeOfComponent someComponent);
		void update(sf::RenderWindow* ptr_gameWindow);

		int ID;
		c_Input _cInput;
		c_Transform _cTransform;
		c_RigidBody _cRb;
		c_Asteroid _cAsteroid;
		c_SpriteRenderer _cSpriteRend;


	};


}

