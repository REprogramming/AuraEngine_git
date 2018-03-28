#pragma once
#include <iostream>
#include "c_BaseComponent.h"

 class c_Transform : public c_BaseComponent
{
public:
	c_Transform();
	~c_Transform();

	void vec2(float x, float y);
	void vec3(float x, float y, float z);
	void vecUI2(float x, float y, float alpha);
	void vecUI3(float x, float y, float z, float alpha);

	void setX(float x);
	void setY(float y);
	void setZ(float z);
	void setAlpha(float alpha);

	void update(); 
};

