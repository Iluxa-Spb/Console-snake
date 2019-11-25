#include "Coordinates.h"
#include "Library.h"

class Snake
{
private:
	static const int MAX_BODY = 400;
	static const int MAX_FIELD = 20;
	Coordinates body_[MAX_BODY];
	Coordinates temp_;
	int head_;
	int tail_;
public:
	Snake();
	~Snake();
	void defsnake();
	void push(Coordinates & ob);
	void step(char ob);
	void stepField(char ob);
	Coordinates gethead();
	Coordinates gettemp();
	void input();
	void output();
};

