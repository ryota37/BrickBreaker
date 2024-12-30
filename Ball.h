#include <Siv3D.hpp>

class Ball
{
private:
	double ballRadius;
	Vec2 pos;
	Vec2 velocity;

public:
	Ball(double ballRadius, Vec2 initialPos, Vec2 initialVelocity);

	void setRadius(double ballRadius);
    double getRadius();
	void setPos(Vec2 pos);
    Vec2 getPos();
	void setVelocity(Vec2 velocity);
    Vec2 getVelocity();

	void update();
};
