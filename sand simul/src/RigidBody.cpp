#include "headers/RigidBody.h"

void RigidBody::gravity(float  dt) {
	 _Y_vel += 0.1 * dt;
}

void RigidBody::Moveobject(float dt) {
	_X += _X_vel*dt;
	_Y += _Y_vel*dt;
}

Sqaure::Sqaure(float Xpos, float Ypos, float width, float height)
{
	_X = Xpos; _Y = Ypos, _width = width, _height = height;
}

Circle::Circle(float Xpos, float Ypos, float radios) {
	_radios = radios, _X = Xpos, _Y = Ypos;
}