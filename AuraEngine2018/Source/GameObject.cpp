
#include "GameObject.h"
class AuraEngine; 

int GameObject::uniqueId = 0; 
GameObject::GameObject()
{		
	thisObjUniqueId = GameObject::uniqueId++;
	AuraEngine::sceneGraph.addObj(this);
	transform = new c_Transform(); 
	this->addComponent(this->transform); // transform inherits from c_BaseComponent
}

GameObject::~GameObject()
{
}

void GameObject::addComponent(c_BaseComponent* component)
{
	this->components.push_back(component);
}

int GameObject::getUniqueId()
{
	return thisObjUniqueId; 
}

void GameObject::setParent(GameObject& parent)
{
	this->parent = &parent;
}

void GameObject::addChild(GameObject* child)
{
	this->children.push_back(child);
}

void GameObject::start()
{
}

void GameObject::update()
{
	
}
