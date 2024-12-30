#include <Siv3D.hpp>
#include "Ball.h"


double ballRadius;
Vec2 pos;
Vec2 velocity;


Ball::Ball(double ballRadius, Vec2 initialPos, Vec2 initialVelocity)
	: ballRadius(ballRadius), pos(initialPos), velocity(initialVelocity)
{

}

void Ball::setRadius(double ballRadius)
{
	ballRadius = ballRadius;
}
double Ball::getRadius()
{
	return ballRadius;
}

void Ball::setPos(Vec2 pos)
{
	pos = pos;
}
Vec2 Ball::getPos()
{
	return pos;
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
	pos += (velocity * Scene::DeltaTime());
	if ((pos.x <= ballRadius) || (Scene::Width() <= (pos.x + ballRadius)))
	{
		velocity.x *= -1.0;
	}
	if ((pos.y <= ballRadius) || (Scene::Height() <= (pos.y + ballRadius)))
	{
		velocity.y *= -1.0;
	}
}
