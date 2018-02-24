
#include "GameObject.h"
class AuraEngine; 



GameObject::GameObject()
{	
	AuraEngine::fullScene.addObj(this);

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
