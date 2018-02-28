#ifndef _gamePlatform
#define _gamePlatform
#include <iostream>  
#include <string>  
using namespace std;
class game
{
public:
	void enroll();//註冊
	void code();//密碼設定
	void setGameble();//設定賭資
	void chooseGame();//選擇遊戲
	int checkPassword();//確認密碼
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