#pragma once

class Coordinates
{
private:
	int x_;
	int y_;
public:
	Coordinates();
	~Coordinates();
	void setdefcoord();
	void setnewcoord(int ob1, int ob2);
	void setx(int ob);
	void sety(int ob);
	int getx();
	int gety();
};

