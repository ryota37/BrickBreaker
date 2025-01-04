#include <Siv3D.hpp>
#include "Ball.h"

Ball::Ball(double x, double y, double r, Vec2 initialVelocity)
	: Circle(x,y,r), velocity(initialVelocity)
{

}

void Ball::setVelocity(Vec2 velocity)
{
	velocity = velocity;
}
Vec2 Ball::getVelocity()
{
	return velocity;
}

void Ball::update()
{
	x += (velocity.x * Scene::DeltaTime());
	y += (velocity.y * Scene::DeltaTime());
}

void Ball::reflect(bool Xaxis, bool Yaxis)
{
	if (Xaxis)
	{
		velocity.x *= -1.0;
	}
	if (Yaxis)
	{
		velocity.y *= -1.0;
	}
}
