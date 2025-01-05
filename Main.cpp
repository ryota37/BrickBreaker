#include <Siv3D.hpp>
#include "Ball.h"
#include "Bar.h"

void Main()
{
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	Ball ball{ Scene::CenterF().x, Scene::CenterF().y, 20.0,  RandomVec2(500)};
	Bar bar{ Scene::CenterF().x, Scene::Height() * 0.9, 200.0, 20.0, {500.0,0}};

	const Font font{ FontMethod::MSDF, 48, Typeface::Bold };
	const Font minifont{ FontMethod::MSDF, 24, Typeface::Bold };

	bool isGameStarted = false;
	bool isGameOver = false;
	bool isGameCleared = false;

	while (System::Update())
	{

		if (!isGameStarted)
		{
			font(U"BrickBreaker").drawAt(Scene::Center().x, Scene::Height() * 5/12);
			minifont(U"Press Enter to start!!").drawAt(Scene::Center().x, Scene::Height() * 2/3);

			if (SimpleGUI::Button(U"Licenses", Vec2{ Scene::Width() * 1/40, Scene::Height() * 1/40 }))
			{
				// ライセンス情報を表示
				LicenseManager::ShowInBrowser();
			}
		}

		if (KeyEnter.down())
		{
			isGameStarted = true;
			ball = { Scene::CenterF().x, Scene::CenterF().y, 20.0,  RandomVec2(500) };
			bar = { Scene::CenterF().x, Scene::Height() * 0.9, 200.0, 20.0, {500.0,0} };
		}

		if (isGameStarted && !isGameOver)
		{
			ball.update();
			ball.draw();
			bar.update();
			bar.draw();

			if ((ball.x <= ball.r) || (Scene::Width() <= (ball.x + ball.r)))
			{
				ball.reflect(true, false);
			}
			if (ball.y <= ball.r)
			{
				ball.reflect(false, true);
			}
			if (ball.intersects(bar))
			{
				ball.reflect(false, true);
			}

			if (Scene::Height() <= (ball.y + ball.r))
			{
				isGameOver = true;
			}
		}

		if (isGameStarted && isGameOver)
		{
			font(U"GameOver!").drawAt(Scene::Center());
		}

		if (isGameStarted)
		{
			if (KeySpace.down())
			{
				isGameStarted = false;
				isGameOver = false;
				isGameCleared = false;
			}
		}

	}
}
