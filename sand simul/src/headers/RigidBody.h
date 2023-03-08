#pragma once
class RigidBody
{
public:
	float _X, _Y, _X_vel = 0, _Y_vel = 0;
	void Moveobject(float dt);
	void gravity(float dt);
};

class Circle : public RigidBody
{
public:
	float _radios;
	Circle(float Xpos, float Ypos,float radios);
};

class Sqaure : public RigidBody
{
public:
	bool moovble=true;
	float _width, _height;
	Sqaure(float Xpos, float Ypos, float _width, float _height);
};

