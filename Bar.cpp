#include <Siv3D.hpp>
#include "Bar.h"

Bar::Bar(double barHeight, double barWidth, Vec2 initialPos, Vec2 initialVelocity)
	: barHeight(barHeight), barWidth(barWidth), pos(initialPos), velocity(initialVelocity)
{

}

void Bar::setHeight(double barHeight)
{
	barHeight = barHeight;
}
double Bar::getHeight()
{
	return barHeight;
}

void Bar::setWidth(double barWidth)
{
	barWidth = barWidth;
}
double Bar::getWidth()
{
	return barWidth;
}

void Bar::setPos(Vec2 pos)
{
	pos = pos;
}
Vec2 Bar::getPos()
{
	return pos;
}

void Bar::setVelocity(Vec2 velocity)
{
	velocity = velocity;
}
Vec2 Bar::getVelocity()
{
	return velocity;
}

void Bar::update()
{
	if (KeyLeft.pressed())
	{
		pos.x = Max((pos.x - velocity.x * Scene::DeltaTime()), 60.0);
	}
	if (KeyRight.pressed())
	{
		pos.x = Min((pos.x + velocity.x * Scene::DeltaTime()), 740.0);
	}
}
