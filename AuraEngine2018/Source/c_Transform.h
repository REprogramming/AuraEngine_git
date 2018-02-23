#pragma once

#include "c_BaseComponent.h"
#include "SFML\Graphics\Transform.hpp"


struct Vector2
{
public:
	Vector2() : x(0.0f), y(0.0f) {}
	Vector2(float _x, float _y) : x(_x), y(_y) {}
	float x, y;
};



class c_Transform : public c_BaseComponent 
{
	void calculateTransform(){

	}

	public:
		c_Transform();
		~c_Transform();

		Vector2 myPosition;
		Vector2 myScale;
		Vector2 myRotation;		
		
		void translate(float x, float y);		
		void rotate(float x, float y); 
		void scale(float x, float y);			

	private:
		sf::Transform transformMatrix;
		sf::Transform translation; 
		
};

