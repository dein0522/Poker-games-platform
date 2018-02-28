#ifndef _21point
#define _21point
#include <iostream>  
#include <string>
#include <time.h>
using namespace std;
class member
{
public:
	void setCard(int, int);//設定明卡暗卡
	void toChar();//數字卡轉字元
	void playGame();//AI自己玩遊戲
	int drawAcard();//抽排
	void change10();//JQK=10
	void finalScore();//最後點數
	int getKnown(){ return known; };
	int getUnknown(){ return unknown; };
	int getPoint(){ return point; };
	string getkCard(){ return kCard; };
	string getUnkCard(){ return unkCard; };
	string getName(){ return name; };
	string getScore(){ return score; };
private:
	int i = 0;
	int point;
	int known;
	int unknown;
	string name;
	string kCard;
	string unkCard;
	string score;
};
#endif