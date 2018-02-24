
#pragma once

#include<map>
#include<vector>


#include "GameObject.h"
class GameObject;
#include "AuraEngine.h"

 class GameObjManager
{		
	public:
		void start();	
		void update();	
		void addObj(GameObject* someObj); 	
		std::vector<GameObject*> listOfObjs;
};

