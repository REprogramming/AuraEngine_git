#include "GameObject.h"

#include "GameObjManager.h"



GameObject::GameObject()
{	
	std::cout << "Created object." << std::endl;
	ID = GameObjManager::gameObjectIDs++; 	
	this->addComponent(GameObject::TRANSFORM);	
}

GameObject::~GameObject()
{
}


void GameObject::update()
{		
	std::cout << "Updating object" << std::endl;

	// TODO:: Update the individual components for this obj
	//for (int i = 0; i < myComponents.size(); i++)
	//{
	//	this->componentsBanner[i].update();		
	//}
}

void GameObject::removeComponent(typeOfComponent someComponent)
{
	switch (someComponent)
	{
	case TRANSFORM:
	{
		componentsBanner.pop_back();
		break;
	}
	case INPUT:
	{
		componentsBanner.pop_back();
		break;
	}
	case RIGIDBODY:
	{
		componentsBanner.pop_back();
		break;
	}
	default:
		break;
	}
}

void GameObject::addComponent(typeOfComponent someComponent)
{
	switch (someComponent)
	{
	case TRANSFORM:
	{
		std::cout << "Adding Transform component." << std::endl; 
		componentsBanner.push_back(c_Transform());
		break;
	}
	case INPUT:
	{
		componentsBanner.push_back(c_Input());
		break;
	}
	case RIGIDBODY:
	{
		// RigidBody component creates BoundingBox
		//componentsBanner.push_back(c_RigidBody());
		break;
	}
	default:
		break;
	}
}

