#pragma warning(disable : 4996)

#include "snake.h"
#include "Library.h"

class Field
{
private:
	static const int MAX = 20;
	const char symbolField_ = '*';
	const char symbolSnake_ = '#';
	const char symbolItem_ = '+';
	char field_[MAX][MAX];
	char direction_;
	char pause_;
	int score_;
	int speed_ = 50;
	bool gameOver = false;
	Coordinates item_;
public:
	Field();
	~Field();
	void defField();
	void show();
	void change(Coordinates & ob1, Coordinates & ob2); // tail_, head - 1 coordinates
	bool checkField(Coordinates & ob); // head_ - 1 coordinates
	bool checkField2(Coordinates & ob); // head_ - 1 coordinates
	bool checkOver(Coordinates & ob); // head_ - 1 coordinates
	bool checkChange(Coordinates & ob); // head - 1 coordinates
	void push(Coordinates & ob);
	void generateItem();
	char setDirection();
	char getDirection();
	bool checkItem();
	Coordinates getItem();
	bool getGameOver();
	int addscore();
	int getscore();
	void setspeed();
	void input();
	void output();
	void delPause();
	char getPause();
};

