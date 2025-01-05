#include <Siv3D.hpp>

class Bar : public RectF
{
private:

	Vec2 velocity;

public:
	Bar(double x, double y, double w, double h, Vec2 initialVelocity);

	void setVelocity(Vec2 newVelocity);
    Vec2 getVelocity();

	void update();
};
