#include <Siv3D.hpp>
#include "Ball.h"

void Main()
{
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	Ball ball{ 20.0, Scene::Center(), RandomVec2(500)};

	while (System::Update())
	{
		ball.update();
		Circle{ ball.getPos(), ball.getRadius() }.draw();
	}
}
