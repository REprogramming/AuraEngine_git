#include "GameObjManager.h"


GameObjManager::GameObjManager()
{
}

GameObjManager::~GameObjManager()
{
}

GameObject * GameObjManager::CreateObject()
{
	return nullptr;
}


void GameObjManager::start()
{
	for (std::map<int, GameObject*>::iterator i = listOfObjects.begin(); i != listOfObjects.end(); ++i) {
		(i->second)->start();
	}
}


void GameObjManager::update()
{
	for (std::map<int, GameObject*>::iterator i = listOfObjects.begin(); i != listOfObjects.end(); ++i) {
		(i->second)->update();
	}
}
