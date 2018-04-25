#include "GameObject.h"
#include "GameObjManager.h"

GameObject::GameObject()
{	
	std::cout << "Created object." << std::endl;	
}

GameObject::~GameObject()
{
}


void GameObject::addComponent(typeOfComponent someComponent)
{
	switch (someComponent)
	{
	case TRANSFORM:
	{
		std::cout << "Adding Transform component." << std::endl;		
		componentsBanner.push_back(new c_Transform());
		break;
	}
	case INPUT:
	{
		_cInput = c_Input(); 
		componentsBanner.push_back(&_cInput);
		break;
	}
	case RIGIDBODY:
	{
		std::cout << "Adding RigidBody component" << std::endl;	
		componentsBanner.push_back(new c_RigidBody()); 
		break;
	}
	case ASTEROID:
		std::cout << "Adding Asteroid component" << std::endl;		
		componentsBanner.push_back(new c_Asteroid());
		break;

	case SPRITE_RENDERER:
		std::cout << "Adding SpriteRenderer component" << std::endl;
		componentsBanner.push_back(new c_SpriteRenderer());
		break;

	default:
		break;
	}

	std::cout << "Component Banner size: " << componentsBanner.size() << std::endl;
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
	case ASTEROID:
	{
		componentsBanner.pop_back(); 
	}

	
	default:
		break;
	}
}


void GameObject::update(sf::RenderWindow* ptr_gameWindow)
{
	std::cout << std::endl; 	
	std::cout << "Calling this Objs update()" << std::endl;
	std::cout << "Num of components " << componentsBanner.size() << std::endl;
	for (int i = 0; i < componentsBanner.size(); i++)
	{			
		componentsBanner[i]->update(ptr_gameWindow);
	}
}



