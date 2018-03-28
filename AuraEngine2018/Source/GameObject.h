#pragma once

#include<iostream>
#include<vector>

#include "c_BaseComponent.h"
#include "c_Transform.h"
#include "c_Input.h"
#include "c_RigidBody.h"

class GameObject
{
public:
	GameObject();
	~GameObject();		
			
	enum typeOfComponent { TRANSFORM, INPUT, RIGIDBODY };
	std::vector<c_BaseComponent> componentsBanner;
	int ID; 

	void update();
	void addComponent(typeOfComponent someComponent);
	void removeComponent(typeOfComponent someComponent); 

};

