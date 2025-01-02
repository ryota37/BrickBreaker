#include <Siv3D.hpp>

class Bar
{
private:
	double barHeight;
	double barWidth;
	Vec2 pos;
	Vec2 velocity;

public:
	Bar(double barHeight, double barWidth, Vec2 initialPos, Vec2 initialVelocity);

	void setHeight(double barHeight);
	double getHeight();
	void setWidth(double barWidth);
    double getWidth();
	void setPos(Vec2 pos);
    Vec2 getPos();
	void setVelocity(Vec2 velocity);
    Vec2 getVelocity();

	void update();
};
