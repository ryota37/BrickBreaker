#include <Siv3D.hpp>

class Ball : public Circle
{
private:
	Vec2 velocity;
	bool isCollided;

public:
	Ball(double x, double y, double r, Vec2 initialVelocity);

	void setVelocity(Vec2 velocity);
    Vec2 getVelocity();

	void update();
	void reflect(bool Xaxis, bool Yaxis);
};
