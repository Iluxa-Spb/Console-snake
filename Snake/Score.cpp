#include "Score.h"

Score::Score()
{
}

Score::~Score()
{
}

void Score::setDefScore()
{
	for (int i = 0; i < MAX_STRING; i++)
		name_[i] = '\0';
	score_ = 0;
	playertime_ = 0;
}

void Score::setNewScore(char* name, int score, int playertime)
{
	for (int i = 0; i < MAX_STRING; i++)
		name_[i] = name[i];
	score_ = score;
	playertime_ = playertime;
}

void Score::input(std::fstream & file)
{
	for (int i = 0; i < MAX_STRING; i++)
	{
		name_[i] = file.get();
	}
	file >> score_;
	file >> playertime_;
	char temp;
	temp = file.get();
}

void Score::output(std::fstream & file)
{
	for (int i = 0; i < MAX_STRING; i++)
	{
		file << name_[i];
	}
	file << ' ' << score_;
	file << ' ' << playertime_ << '\n';
}

void Score::show()
{
	for (int i = 0; i < MAX_STRING; i++)
	{
		printf("%c", name_[i]);
	}
	std::cout << " " << score_;
	std::cout << " " << playertime_ << "\n";
}

int Score::getscore()
{
	return score_;
}