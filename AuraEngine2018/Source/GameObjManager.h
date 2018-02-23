#pragma once
#include <iostream>
#include <stdio.h>
#include<vector>
#include <map>
#include <list>
#include <iterator>
#include "GameObject.h"

class GameObjManager
{
	public:
		GameObjManager();
		~GameObjManager();

		//bool SendMessage(BaseMessage* msg);
		GameObject* CreateObject();				
	
		void start();	
		void update();

	private:
		std::map<int, GameObject*> listOfObjects;
		static int nextObjectID;
		
};

