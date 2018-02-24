
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
	public:						
		GameObject();	
		~GameObject();

		static int uniqueId; 
		sf::Transform worldTransform; 

		c_BaseComponent* componentBanner;
		int getUniqueId(); 
		void setParent(GameObject& parent);
		void addChild(GameObject* child);
		void addComponent(c_BaseComponent* component);	
			
		void start();
		void update();	

	private:
		c_Transform * transform;
		GameObject* parent;
		int thisObjUniqueId;
		std::vector<GameObject*> children;
		std::vector<c_BaseComponent*> components;
};

