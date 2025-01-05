#include <Siv3D.hpp>
#include "Block.h"

Block::Block(double x, double y, double w, double h, bool isBroken)
	:RectF(x,y,w,h), isBroken(isBroken)
{

}

void Block::setBroken(bool newStatus)
{
	isBroken = newStatus;
}
bool Block::getBroken()
{
	return isBroken;
}
