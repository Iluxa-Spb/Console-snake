#include "Functions.h"
void menu()
{
	static const int MAX_EL = 10;
	Field field;
	Snake snake;
	Score score[MAX_EL];
	std::fstream file;
	double movetime;
	char name[MAX_EL][MAX_EL];
	bool endGame = false;
	char symbol;
	file.open("SCORE.ini");
	for ( int i = 0; i < MAX_EL; i++)
	{
		if (file.eof())
			break;
		score[i].input(file);
	}
	file.close();
	field.input();
	snake.input();
	while (!endGame)
	{
		system("cls");
		std::cout << "**********SNAKE********** \n";
		std::cout << "1: continue game \n"
			<< "2: start new game \n"
			<< "3: push for set speed \n"
			<< "4: push for score \n"
			<< "5: push for exit \n";
		std::cout << "*************************" << "\n";
		symbol = getch();
		switch (symbol)
		{
		case'1':
		{
				   if (field.getGameOver())
				   {
					   snake.defsnake();
					   field.defField();
				   }
				   continueGame(field, snake, movetime);
				   if (field.getPause() == 'p')
				   {
					   field.delPause();
					   break;
				   }
				   system("cls");
				   for (int i = 0; i < MAX_EL; i++)
				   {
					   if (score[i].getscore() < field.getscore())
					   {
						   std::cout << "Congratulations! You have " << i + 1 << " top score!" << "\n";
						   std::cout << "Enter you name." << "\n";
						   char winName[MAX_EL + 1];
						   for (int i = 0; i < MAX_EL+1; i++)
						   {
							   winName[i] = '\0';
						   }
						   std::cin.getline(winName, MAX_EL + 1);
						   score[MAX_EL - 1].setNewScore(winName, field.getscore(), movetime);
						   Score temp;
						   for (int j = MAX_EL - 1; j > i; --j)
						   {
							   temp = score[j];
							   score[j] = score[j - 1];
							   score[j - 1] = temp;
						   }
						   break;
					   }
				   }
				   break;
		}
		case'2':
		{
				   run(field, snake, movetime);
				   system("cls");
				   for (int i = 0; i < MAX_EL; i++)
				   {
					   if (score[i].getscore() < field.getscore())
					   {
						   std::cout << "Congratulations! You have " << i + 1 << " place!" << "\n";
						   std::cout << "Enter you name." << "\n";
						   char winName[MAX_EL+1];
						   std::cin.getline(winName, MAX_EL+1);
						   score[MAX_EL - 1].setNewScore(winName, field.getscore(), movetime);
						   Score temp;
						   for (int j = MAX_EL - 1; j > i; --j)
						   {
							   temp = score[j];
							   score[j] = score[j - 1];
							   score[j - 1] = temp;
						   }
						   break;
					   }
				   }
				   break;
		}
		case'3':
		{
				   field.setspeed();
				   break;
		}
		case'4':
		{
				   system("cls");
				   file.open("SCORE.ini");
				   std::printf( "**********SCORE********** \n");
				   for (int i = 0; i < MAX_EL; i++)
				   {
					   score[i].show();
				   }
				   std::cout << "************************* \n";
				   file.close();
				   system("pause");
				   break;
		}
		case'5':
		{
				   std::cout << "Are you sure? (Y/N) \n";
				   symbol = getch();
				   while ((symbol != 'n') && (symbol != 'y'))
				   {
					   symbol = getch();
				   }
				   if (symbol == 'y')
				   {
					   endGame = true;
					   file.open("SCORE.ini");
					   for (size_t i = 0; i < MAX_EL; i++)
					   {
						   score[i].output(file);
					   }
					   file.close();
					   snake.output();
					   field.output();
				   }
					   
				   break;
		}
		default:
			break;
		}
	}
}
void run(Field & field, Snake & snake, double & movetime)
{
	clock_t t0 = clock();
	field.defField();
	snake.defsnake();
	field.show();
	while (!field.getGameOver())
	{
		clock_t fps0 = clock();
		if (field.checkItem())
			field.generateItem();
		if (field.checkField(snake.gethead()))
		{
			if (field.checkField2(snake.gethead()))
			{
				snake.stepField(field.getDirection());
			}
		}
		else
			snake.step(field.getDirection());
		if (field.checkChange(snake.gethead()))
		{
			snake.push(field.getItem());
			field.push(snake.gethead());
			field.addscore();
		}
		else
			field.change(snake.gettemp(), snake.gethead());
		field.show();
		field.setDirection();
		clock_t fps1 = clock();
		std::cout << "Fps: " << (double)(fps1 - fps0) / CLOCKS_PER_SEC << "\n";
		if (field.getPause() == 'p')
			break;
		field.checkOver(snake.gethead());
	}
	clock_t t1 = clock();
	movetime = (t1 - t0) / CLOCKS_PER_SEC;
	std::cout << "time: " << movetime << "\n";
	system("pause");
}

void continueGame(Field & field, Snake & snake, double & movetime)
{
	clock_t t0 = clock();
	field.show();
	while (!field.getGameOver())
	{
		
		clock_t fps0 = clock();
		if (field.checkItem())
			field.generateItem();
		if (field.checkField(snake.gethead()))
		{
			if (field.checkField2(snake.gethead()))
			{
				snake.stepField(field.getDirection());
			}
		}
		else
			snake.step(field.getDirection());
		if (field.checkChange(snake.gethead()))
		{
			snake.push(field.getItem());
			field.push(snake.gethead());
			field.addscore();
		}
		else
			field.change(snake.gettemp(), snake.gethead());
		field.show();
		field.setDirection();
		clock_t fps1 = clock();
		std::cout << "Fps: " << (double)(fps1 - fps0) / CLOCKS_PER_SEC << "\n";
		if (field.getPause() == 'p')
			break;
		field.checkOver(snake.gethead());
	}
	clock_t t1 = clock();
	movetime = (t1 - t0) / CLOCKS_PER_SEC;
	std::cout << "time: " << movetime << "\n";
	system("pause");
}