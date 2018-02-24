#include "GameObjManager.h"


GameObjManager::GameObjManager()
{	
}

GameObjManager::~GameObjManager()
{
}


void GameObjManager::start()
{
	/*
	for (std::map<int, GameObject*>::iterator i = listOfObjects.begin(); i != listOfObjects.end(); ++i) {
		(i->second)->start();
	}*/
}


void GameObjManager::update()
{
	/*
	for (std::map<int, GameObject*>::iterator i = listOfObjects.begin(); i != listOfObjects.end(); ++i) {
		(i->second)->update();
	}*/
}


void GameObjManager::addObj(GameObject* someObj)
{
	this->listOfObjs.push_back(someObj); 
}


