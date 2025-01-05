#include <Siv3D.hpp>

class Block : public RectF
{
private:
	bool isBroken;

public:
	Block(double x, double y, double w, double h, bool isBroken);
	void setBroken(bool newStatus);
	bool getBroken();
};
