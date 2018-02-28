#include <iostream>  
#include <string>  
#include <windows.h>
#include "gamePlatform.h"
using namespace std;
void game::enroll()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	cout << "		Account:: ";
	SetConsoleTextAttribute(hConsole, 10);
	cin >> account;
	code();
	while (checkPassword())
		code();
	SetConsoleTextAttribute(hConsole, 14);
	cout << "		Games:: ";
	SetConsoleTextAttribute(hConsole, 10);
	cin >> ID;
	chooseGame();
	
	
}
void game::chooseGame()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 11);
	cout << "	Which game do you want to play?" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << "	(1) 21ÂI	(2) 99		(3)Holdem	(4)Laying Out Sevens" << endl;
	cin >> poker;
	setGameble();
}
void game::code()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	cout << "		Password:: ";
	SetConsoleTextAttribute(hConsole, 0);
	cin >> password;
}
int game::checkPassword()
{
	string check;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	cout << "		Confirm password: ";
	SetConsoleTextAttribute(hConsole, 0);
	cin >> check;
	if (check == password)
		return 0;
	else{
		SetConsoleTextAttribute(hConsole, 15);
		cout << "		Wrong password! enter again" << endl;
		return 1;
	}

}
void game::setGameble()
{
	cout << "How much money you want to put in?" << endl;
	cin >> gamebleFund;
}
