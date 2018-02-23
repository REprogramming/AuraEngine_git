#include "GameObject.h"


GameObject::GameObject(int Unum)
{
	uniqueId = Unum;
	transform;	
}

GameObject::~GameObject()
{
}

int GameObject::setID()
{ 	
	AuraEngine::_gameObjectManager.objNumber = rand() % 1000; 	

	return 0;
}

void GameObject::addToObjMgr(GameObject* newObj)
{
	int newObjId = setID();
	//AuraEngine::_gameObjectManager.listOfObjects.insert(std::<int, GameObject*>); 		
}

void GameObject::addComponent(c_BaseComponent* component)
{
}


void GameObject::setParent()
{
}

void GameObject::addChild()
{
}

void GameObject::awake()
{
}

void GameObject::start()
{
}

void GameObject::update()
{
	
}
