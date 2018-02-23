#pragma once

#include <stdio.h>
#include <iostream>
#include <list>
#include <vector>
#include <iterator>


#include "AuraEngine.h"
#include "GameObjManager.h"
#include "c_BaseComponent.h"
#include "c_Transform.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class GameObject
{
	private:

	int uniqueId;
	c_Transform transform;    //local transform	
	GameObject* parent;
	std::vector<GameObject*> children;
	std::vector<c_BaseComponent*> m_Components;
	
	
	public:
		
		int setID();
		int getID() const { return uniqueId; }
	
		void addToObjMgr(GameObject* newObj); 
		void setParent();
		void addChild();
		void addComponent(c_BaseComponent* component);	

		void awake();
		void start();
		void update();
	
		// Constructor
		GameObject(int Unum); 
	
		// Destructor
		~GameObject();

	
	
};

