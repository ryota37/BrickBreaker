# include <Siv3D.hpp>

class Ball
{
private:
	const double ballRadius;
	Vec2 pos;
	Vec2 velocity;

public:
	Ball(double ballRadius, Vec2 initialPos, Vec2 initialVelocity)
		: ballRadius(ballRadius), pos(initialPos), velocity(initialVelocity)
	{

	}

	void setRadius(double ballRadius)
	{
		ballRadius = ballRadius;
	}
	double getRadius()
	{
		return ballRadius;
	}

	void setPos(Vec2 pos)
	{
		pos = pos;
	}
	Vec2 getPos()
	{
		return pos;
	}

	void setVelocity(Vec2 velocity)
	{
		velocity = velocity;
	}
	Vec2 getVelocity()
	{
		return velocity;
	}

	void update()
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
};

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
