#ifndef _gamePlatform
#define _gamePlatform
#include <iostream>  
#include <string>  
using namespace std;
class game
{
public:
	void enroll();//���U
	void code();//�K�X�]�w
	void setGameble();//�]�w���
	void chooseGame();//��ܹC��
	int checkPassword();//�T�{�K�X
	int getPoker(){ return poker; };
	int getFund(){ return gamebleFund; };
	string getAccount(){ return account; };
	string getPassword(){ return password; };
	string getID(){ return ID; };
	
	
private:
	string account;
	string password;
	string ID;
	int gamebleFund;
	int poker;


};
#endif