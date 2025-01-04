#include <Siv3D.hpp>
#include "Ball.h"
#include "Bar.h"

void Main()
{
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	Ball ball{ Scene::CenterF().x, Scene::CenterF().y, 20.0,  RandomVec2(500)};
	Bar bar{ Scene::CenterF().x, Scene::Height() * 0.9, 200.0, 20.0, {300.0,0}};

	while (System::Update())
	{
		ball.update();
		ball.draw();
		bar.update();
		bar.draw();

		if ((ball.x <= ball.r) || (Scene::Width() <= (ball.x + ball.r)))
		{
			ball.reflect(true, false);
		}
		if ((ball.y <= ball.r) || (Scene::Height() <= (ball.y + ball.r)))
		{
			ball.reflect(false, true);
		}
		if (ball.intersects(bar))
		{
			ball.reflect(false, true);
		}
	}
}
