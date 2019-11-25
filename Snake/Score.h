#include "Library.h"

//using namespace std;

class Score
{
private:
	static const int MAX_STRING = 10;
	char name_[MAX_STRING];
	int score_;
	int playertime_;
public:
	Score();
	~Score();
	void setDefScore();
	void setNewScore(char* name, int score, int playertime);
	void input(std::fstream & file);
	void output(std::fstream & file);
	void show();
	int getscore();
};