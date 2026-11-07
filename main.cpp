#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <ctime>
using namespace std;

short ReadNumber(string Message,short From,short To)
{
	short Number;
	Number = 0;
	int Count = 0;
	while (Number<From || Number>To)
	{
		if (Count == 0)
		{
			cout << Message << endl;
			cin >> Number;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Number," << Message << endl;
				cin >> Number;
				
			}
			Count++;
		}
		else
		{
			cout <<"\nYour Choice Is Out Of Range," << Message << endl;
			cin >> Number;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Number," << Message << endl;
				cin >> Number;
				Count++;
			}
		}
	}
	return Number;
}

short ReadRandomNumber(short From, short To)
{
	return  rand() % (To - From + 1) + From;
}

short WhoIsWinner(short Player, short Computer)
{
	if (Player == Computer)
		return 0;
	else if (Player == 1 && Computer == 2)
		return 2;
	else if ((Player == 2 && Computer == 3))
		return 2;
	else if ((Player == 3 && Computer == 1))
		return 2;
	else
		return 1;
}


void GameOverScreen(short Rounds, short Win, short Lose, short Draw)
{
	cout << "_____________________________________________________________________\n";
	cout << "                         GameOver\n";
	cout << "_____________________________________________________________________\n";
	cout << "__________________________[Game Results]_____________________________\n";
	cout << "GamePalyer : " << Rounds << endl;
	cout << "You Win : " << Win << endl;
	cout << "You Lose : " << Lose << endl;
	cout << "Draw : " << Draw << endl;
	cout << "_____________________________________________________________________\n\n";
}


string ChangeToChoice(short Number)
{
	if (Number == 1)
		return "Rock";
	else if (Number == 2)
		return "Paper";
	else
		return "Scissors";
}


void Results()
{
	short Rounds = ReadNumber("Please Enter Rounds You Want To Play From 1 To 10 \n",1,10);

	short  Draw = 0, Win = 0, Lose = 0;
	for (int i = 0; i < Rounds; i++)
	{
		cout << "Round [" << i + 1 << "] :\n";
		short Player = ReadNumber("Enter Choice : [Rock] = 1,[Paper] = 2,[Scissors] = 3 ",1,3);
		short Computer = ReadRandomNumber(1, 3);
		short Result = WhoIsWinner(Player, Computer);

		if (Result == 0)
		{
			cout << "**************************************\n";
			cout << "You : " << ChangeToChoice(Player) << endl;
			cout << "Computer : " << ChangeToChoice(Computer) << endl << endl;
			system("color 6F");
			cout << "Draw\n";
			cout << "**************************************\n";
			Draw++;

		}
		else if (Result == 1)
		{
			cout << "**************************************\n";
			cout << "You : " << ChangeToChoice(Player) << endl;
			cout << "Computer : " << ChangeToChoice(Computer) << endl << endl;
			system("color AF");
			cout << "You Are Winner\n";
			cout << "**************************************\n";
			Win++;

		}
		else
		{
			cout << "**************************************\n";
			cout << "You : " << ChangeToChoice(Player) << endl;
			cout << "Computer : " << ChangeToChoice(Computer) << endl << endl;
			system("color 4F");
			cout << "\a";
			cout << "Computer Win\n";
			cout << "**************************************\n";
			Lose++;
		}
	}


	GameOverScreen(Rounds, Win, Lose, Draw);

}



int main()
{
	srand((unsigned)time(NULL));
	char Again = 'Y';
	while (Again == 'y' || Again == 'Y')
	{
		system("cls");
		system("color 0F");
		Results();
		cout << "Do You Want To Play Again ?(Y/N)\n";
		cin >> Again;
	}
	return 0;
}

