#include "Coordinates.h"

Coordinates::Coordinates()
{
}

Coordinates::~Coordinates()
{
}

void Coordinates::setdefcoord()
{
	x_ = 0;
	y_ = 0;
}

void Coordinates::setnewcoord(int ob1, int ob2)
{
	x_ = ob1;
	y_ = ob2;
}

void Coordinates::setx(int ob)
{
	x_ = ob;
}

void Coordinates::sety(int ob)
{
	y_ = ob;
}

int Coordinates::getx()
{
	return x_;
}

int Coordinates::gety()
{
	return y_;
}