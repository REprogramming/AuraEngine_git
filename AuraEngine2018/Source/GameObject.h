
#pragma once
#include <stdio.h>
#include <iostream>
#include <list>
#include <vector>
#include <iterator>


//#include "AuraEngine.h"
#include "GameObjManager.h"
#include "c_BaseComponent.h"
#include "c_Transform.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class GameObject
{
	private:

	int uniqueId;
	c_Transform* transform;   	
	GameObject* parent;
	std::vector<GameObject*> children;
	std::vector<c_BaseComponent*> components;
	
	
	public:
				
		// Constructor	
		GameObject();

		// Destructor
		~GameObject();

		c_BaseComponent* componentBanner;
		void setParent(GameObject& parent);
		void addChild(GameObject* child);
		void addComponent(c_BaseComponent* component);	
			
		void start();
		void update();	
};

