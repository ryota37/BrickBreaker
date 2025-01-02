#include <Siv3D.hpp>
#include "Ball.h"
#include "Bar.h"

void Main()
{
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	Ball ball{ 20.0, Scene::CenterF(), RandomVec2(500)};
	Bar bar{ 20.0, 200.0, {Scene::Center().x, Scene::Height() *  0.9} , {300.0,0} };

	Print << (Scene::Center().y + Scene::Height()) / 2;
	Print << Scene::Height() * 5 / 6;



	while (System::Update())
	{
		ball.update();
		Circle{ ball.getPos(), ball.getRadius() }.draw();
		bar.update();
		RectF{ Arg::center(bar.getPos().x, bar.getPos().y), bar.getWidth(), bar.getHeight() }.draw();
	}
}
