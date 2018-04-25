#pragma once

#include <string>
#include <vector>
#include<iostream>


#include "GameObjManager.h"
#include "GameObject.h"



class Scene
{
public:
	Scene();	
	~Scene();

	std::string sceneName; 
	int ID;	
	
	void onStart(int someScene); 
	void run(int someScene);
	void end(int nextScreen);	
	bool physicsEnabled = false; 	
};

