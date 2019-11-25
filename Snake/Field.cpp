#include "Field.h"

Field::Field()
{
}

Field::~Field()
{
}

void Field::defField()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if ((i == 0) || (i == MAX-1) || (j == 0) || (j == MAX-1))
				field_[i][j] = symbolField_;
			else
				field_[i][j] = '\0';
		}
	}
	field_[MAX/2][MAX/2] = symbolSnake_;
	item_.setnewcoord(0, 0);
	direction_ = 'd';
	score_ = 0;
	gameOver = false;
}

void Field::change(Coordinates & ob1, Coordinates & ob2) //ob1 - temp, ob2 - head
{
	field_[ob1.getx()][ob1.gety()] = '\0';
	field_[ob2.getx()][ob2.gety()] = symbolSnake_;
}

void Field::push(Coordinates & ob) // head - 1
{
	field_[ob.getx()][ob.gety()] = symbolSnake_;
}
bool Field::checkChange(Coordinates & ob) //ob - head
{
	if (field_[ob.getx()][ob.gety()] == symbolItem_)
		return true;
	else
		return false;
}

void Field::show()
{
	system("cls");
	
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			printf("%c", field_[i][j], "\0");
		}
		std::cout << "\n";
	}
	std::cout << "Score: " << score_ << "\n";
}

char Field::setDirection()
{
	char input = '\0';
	int n = 0;
	//Sleep(speed_);
	if (kbhit())
		input = getch();
	switch (input)
	{
	case'w':
	{
			   if (direction_ != 's')
				   return direction_ = input;
			   break;
	}
	case's':
	{
			   if (direction_ != 'w')
				   return direction_ = input;
			   break;
	}
	case'a':
	{
			   if (direction_ != 'd')
				   return direction_ = input;
			   break;
	}
	case'd':
	{
			   if (direction_ != 'a')
				   return direction_ = input;
			   break;
	}
	case'p':
	{
			   pause_ = 'p';
			   break;
	}
	default:
		break;
	}
}

char Field::getDirection()
{
	return direction_;
}

bool Field::checkOver(Coordinates & ob) // head_- 1 coordinates
{
	switch (direction_)
	{
	case'w':
	{
			   if (field_[ob.getx() - 1][ob.gety()] == symbolSnake_)
			   {
				   gameOver = true;
				   return true;
			   }
			   else
				   return false;
	}
	case's':
	{
			   if (field_[ob.getx() + 1][ob.gety()] == symbolSnake_)
			   {
				   gameOver = true;
				   return true;
			   }
			   else
				   return false;
	}
	case'd':
	{
				if (field_[ob.getx()][ob.gety() + 1] == symbolSnake_)
			   {
				   gameOver = true;
				   return true;
			   }
			   else
				   return false;
	}
	case'a':
	{
			   if (field_[ob.getx()][ob.gety() - 1] == symbolSnake_)
			   {
				   gameOver = true;
				   return true;
			   }
			   else
				   return false;
	}
	default:
		break;
	}
}

bool Field::checkField(Coordinates & ob) // head_- 1 coordinates
{
	switch (direction_)
	{
	case'w':
	{
			   return (field_[ob.getx() - 1][ob.gety()] == symbolField_);
	}
	case's':
	{
			   return (field_[ob.getx() + 1][ob.gety()] == symbolField_);
	}
	case'd':
	{
			   return (field_[ob.getx()][ob.gety() + 1] == symbolField_);
	}
	case'a':
	{
			   return (field_[ob.getx()][ob.gety() - 1] == symbolField_);
	}
	default:
		break;
	}
}

bool Field::checkField2(Coordinates & ob) // head_- 1 coordinates
{
	switch (direction_)
	{
	case'w':
	{
			   if (field_[MAX - 2][ob.gety()] == symbolSnake_)
				   gameOver = true;
			   return true;
	}
	case's':
	{
			   if (field_[1][ob.gety()] == symbolSnake_)
				   gameOver = true;
			   return true;
	}
	case'd':
	{
			   if (field_[ob.getx()][1] == symbolSnake_)
				   gameOver = true;
			   return true;
	}
	case'a':
	{
			   if (field_[ob.getx()][MAX - 2] == symbolSnake_)
				   gameOver = true;
			   return true;
	}
	default:
		break;
	}
}


void Field::generateItem()
{
	std	::default_random_engine generator;
	std::uniform_int_distribution<int> distribution1(1, MAX - 1);
	Sleep(1);
	std::uniform_int_distribution<int> distribution2(1, MAX - 1);
	int x = distribution1(generator);
	Sleep(1);
	int y = distribution2(generator);
	while (field_[x][y] != '\0')
	{
		x = distribution1(generator);
		Sleep(1);
		y = distribution2(generator);
	}
	item_.setnewcoord(x, y);
	field_[x][y] = symbolItem_;
}

bool Field::checkItem()
{
	if (field_[item_.getx()][item_.gety()] == symbolItem_)
		return false;
	else true;
}

Coordinates Field::getItem()
{
	return item_;
}

int Field::addscore()
{
	return score_++;
}

int Field::getscore()
{ 
	return score_;
}

bool Field::getGameOver()
{
	return gameOver;
}

void Field::setspeed()
{
	std::cout << "Enter speed 1 - 5" << "\n";
	char ob = getch();
	while ((ob != '1') && (ob != '2') && (ob != '3') && (ob != '4') && (ob != '5'))
	{
		std::cout << "Wrong number! \n" << "Enter again. \n";
		ob = getch();
	}
	switch (ob)
	{
	case'1':
	{
			   speed_ = 5;
			   break;
	}
	case'2':
	{
			   speed_ = 15;
			   break;
	}
	case'3':
	{
			   speed_ = 30;
			   break;
	}
	case'4':
	{
			   speed_ = 50;
			   break;
	}
	case'5':
	{
			   speed_ = 100;
			   break;
	}
	default:
		break;
	}
	std::cout << "Set speed successful. \n";
}

void Field::input()
{
	std::ifstream file("Field.ini");
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			field_[i][j] = file.get();
		}
	}
	int x, y;
	file >> score_;
	file >> x;
	file >> y;
	item_.setx(x);
	item_.sety(y);
	file >> direction_;
	file >> gameOver;
	file.close();
	std::cout << "Field input completed.";
}

void Field::output()
{
	std::ofstream file("Field.ini");
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			file << field_[i][j];
		}
	}
	char temp = ' ';
	file << temp << score_;
	file << temp << item_.getx();
	file << temp << item_.gety();
	file << temp << direction_;
	file << temp << gameOver;
	file.close();
	std::cout << "Field output completed.";
}

void Field::delPause()
{
	pause_ = '\n';
}

char Field::getPause()
{
	return pause_;
}