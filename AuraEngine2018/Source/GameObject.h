#pragma once

#include <stdio.h>
#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include "c_BaseComponent.h"
#include "c_Transform.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class GameObject
{
	public:
		
		int getID() const { return uniqueId; }
		int GetObjectID() const { return uniqueId; }

		void addComponent(c_BaseComponent* component);

		void setParent();
		void addChild();

		void awake();
		void start();
		void update();
	
		// Constructor
		GameObject(int Unum) {
			uniqueId = Unum; 		
		}; 
	
		~GameObject();

	
	private: // Members
		int uniqueId;
		GameObject* parent;
		std::vector<GameObject*> children;	
		std::vector<c_BaseComponent*> m_Components;
		c_Transform transform;    //local transform	
		// TODO: WORLD TRANSFORM setup 
};

