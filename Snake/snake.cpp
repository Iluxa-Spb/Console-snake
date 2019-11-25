#include "snake.h"
Snake::Snake()
{
}

Snake::~Snake()
{
}

void Snake::defsnake()
{
	body_[0].setnewcoord(1, 1);
	for (int i = 1; i < MAX_BODY; i++)
	{
		body_[i].setnewcoord(0, 0);
	}
	temp_.setnewcoord(2, 2);
	body_[0].setnewcoord(10, 10);
	head_ = 1;
	tail_ = 0;
}

void Snake::push(Coordinates & ob)
{
	try
	{
		if (head_ == MAX_BODY)
			throw "You Win!";
		++head_;
		for (int i = head_ - 1; i > 0; --i)
		{
			body_[i] = body_[i-1];
		}
		body_[tail_] = temp_;
	}
	catch (char*)
	{
		throw;
	}
}

void Snake::step(char ob)
{
	Coordinates temp;
	temp_ = body_[head_ - 1];
	for (int i = head_ - 1; i >= 0; --i)
	{
		temp = body_[i];
		body_[i] = body_[head_ - 1];
		body_[head_ - 1] = temp;
	}
	temp = body_[head_ - 1];
	body_[head_ - 1] = temp_;
	temp_ = temp;
	switch (ob)
	{
	case'w':
	{
			   body_[head_ - 1].setx(body_[head_ - 1].getx() - 1);
			   break;
	}
	case's':
	{
			   body_[head_ - 1].setx(body_[head_ - 1].getx() + 1);
			   break;
	}
	case'a':
	{
			   body_[head_ - 1].sety(body_[head_ - 1].gety() - 1);
			   break;
	}
	case'd':
	{
			   body_[head_ - 1].sety(body_[head_ - 1].gety() + 1);
			   break;
	}
	default:
		break;
	}
}

void Snake::stepField(char ob)
{
	Coordinates temp;
	temp_ = body_[head_ - 1];
	for (int i = head_ - 1; i >= 0; --i)
	{
		temp = body_[i];
		body_[i] = body_[head_ - 1];
		body_[head_ - 1] = temp;
	}
	temp = body_[head_ - 1];
	body_[head_ - 1] = temp_;
	temp_ = temp;
	switch (ob)
	{
	case'w':
	{
			   body_[head_ - 1].setx(MAX_FIELD - 2);
			   break;
	}
	case's':
	{
			   body_[head_ - 1].setx(1);
			   break;
	}
	case'a':
	{
			   body_[head_ - 1].sety(MAX_FIELD - 2);
			   break;
	}
	case'd':
	{
			   body_[head_ - 1].sety(1);
			   break;
	}
	default:
		break;
	}
}

Coordinates Snake::gettemp()
{
	return temp_;
}

Coordinates Snake::gethead()
{
	return body_[head_ - 1];
}

void Snake::input()
{
	int x, y;
	std::ifstream file("Snake.ini");
	for (int i = 0; i < MAX_BODY; i++)
	{
		file >> x;
		file >> y;
		body_[i].setx(x);
		body_[i].sety(y);
	}
	file >> x;
	file >> y;
	temp_.setx(x);
	temp_.sety(y);
	file >> head_;
	file >> tail_;
	file.close();
	std::cout << "Snake input completed. \n";
}

void Snake::output()
{
	std::ofstream file("Snake.ini");
	char temp = ' ';
	for (int i = 0; i < MAX_BODY; i++)
	{
		file << body_[i].getx() << temp;
		file << body_[i].gety() << temp;
	}
	file << temp_.getx() << temp;
	file << temp_.gety() << temp;
	file << head_ << temp;
	file << tail_;
	file.close();
	std::cout << "Snake output completed. \n";
}