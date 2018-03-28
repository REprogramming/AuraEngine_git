#include "c_BaseComponent.h"
#include "c_Transform.h"
#include "c_Input.h"
#include "c_RigidBody.h"


c_BaseComponent::c_BaseComponent()
{

}

c_BaseComponent::~c_BaseComponent()
{
}

void c_BaseComponent::update()
{
	std::cout << "Components updating..." << std::endl; 	
}


