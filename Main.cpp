#include <Siv3D.hpp>
#include "Ball.h"
#include "Bar.h"
#include "Block.h"

void Main()
{
	// Initial setting
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	Ball ball{ Scene::CenterF().x, Scene::CenterF().y, 20.0,  RandomVec2(100)};
	Bar bar{ Scene::CenterF().x, Scene::Height() * 0.9, Scene::Width()*0.25, 20.0, {100.0,0}};
	Array<Block> blocks;
	for (int32 i = 0; i < 4; ++i)
	{
		blocks << Block{ Scene::Width() * i *0.25, Scene::Height() * 0.25, 180.0, 50.0, false };
	}
	
	const Font font{ FontMethod::MSDF, 48, Typeface::Bold };
	const Font minifont{ FontMethod::MSDF, 24, Typeface::Bold };

	bool isGameStarted = false;
	bool isGameOver = false;
	bool isGameCleared = false;

	// Main loop
	while (System::Update())
	{

		if (!isGameStarted)
		{
			font(U"BrickBreaker").drawAt(Scene::Center().x, Scene::Height() * 5/12);
			minifont(U"Press Enter to start!!").drawAt(Scene::Center().x, Scene::Height() * 2/3);

			if (SimpleGUI::Button(U"Licenses", Vec2{ Scene::Width() * 1/40, Scene::Height() * 1/40 }))
			{
				// Display license information
				LicenseManager::ShowInBrowser();
			}
		}

		// Initialize the objects when the game starts
		if (KeyEnter.down())
		{
			isGameStarted = true;
			ball = { Scene::CenterF().x, Scene::CenterF().y, 20.0,  RandomVec2(500) };
			bar = { Scene::CenterF().x, Scene::Height() * 0.9, 200.0, 20.0, {500.0,0} };
			for (auto& block : blocks)
			{
				block.setBroken(false);
			}
		}

		// Playing the game
		if (isGameStarted && !isGameOver && !isGameCleared)
		{
			// Rendering and update of the objects
			ball.update();
			ball.draw();
			bar.update();
			bar.draw();
			for (auto& block : blocks)
			{
				if (!block.getBroken())
				{
					block.draw();
				}
			}

			// Debug code for pausing the ball movement
			if (KeyD.down() && KeyE.down())
			{
				ball.setVelocity({ 0.0,0.0 });
			}

			// Collision detection of balls
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
			for (auto& block : blocks)
			{
				if (ball.intersects(block) && !block.getBroken())
				{
					ball.reflect(false, true);
					block.setBroken(true);
				}
			}

			// Gameover judgement
			if (Scene::Height() <= (ball.y + ball.r))
			{
				isGameOver = true;
			}

			// Gameclear judgement
			for (auto& block : blocks)
			{
				bool result = all_of(blocks.begin(), blocks.end(), [](auto& block) {return block.getBroken(); });
				if (result)
				{
					isGameCleared = true;
				}
			}
		}

		// Gameover screen
		if (isGameStarted && isGameOver)
		{
			font(U"GameOver!").drawAt(Scene::Center());
			minifont(U"Press Space to go back to title!!").drawAt(Scene::Center().x, Scene::Height() * 2 / 3);
		}

		// Gameclear screen
		if (isGameStarted && isGameCleared)
		{
			font(U"GameClear!").drawAt(Scene::Center());
			minifont(U"Press Space to go back to title!!").drawAt(Scene::Center().x, Scene::Height() * 2 / 3);
		}

		// Go back to the title screen
		if (isGameStarted)
		{
			if (KeySpace.down())
			{
				isGameStarted = false;
				isGameOver = false;
				isGameCleared = false;
				for (auto& block : blocks)
				{
					block.setBroken(false);
				}
			}
		}
	}
}
