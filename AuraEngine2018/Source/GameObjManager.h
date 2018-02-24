
#pragma once

#include<map>
#include<vector>


#include "GameObject.h"
class GameObject;
#include "AuraEngine.h"


 class GameObjManager
{		
	public:
		
		GameObjManager();
		~GameObjManager();				
		
		void start();	
		void update();	
		void addObj(GameObject* someObj); 	

	private: 
	std::vector<GameObject*> listOfObjs;

};

