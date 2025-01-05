#include <Siv3D.hpp>
#include "Bar.h"

Bar::Bar(double x, double y, double w, double h, Vec2 initialVelocity)
	:RectF(x,y,w,h), velocity(initialVelocity)
{

}
void Bar::setVelocity(Vec2 newVelocity)
{
	velocity = newVelocity;
}
Vec2 Bar::getVelocity()
{
	return velocity;
}

void Bar::update()
{
	if (KeyLeft.pressed())
	{
		x = Max((x - velocity.x * Scene::DeltaTime()), 60.0);
	}
	if (KeyRight.pressed())
	{
		x = Min((x + velocity.x * Scene::DeltaTime()), 740.0);
	}
}
