#ifndef _21point
#define _21point
#include <iostream>  
#include <string>
#include <time.h>
using namespace std;
class member
{
public:
	void setCard(int, int);//�]�w���d�t�d
	void toChar();//�Ʀr�d��r��
	void playGame();//AI�ۤv���C��
	int drawAcard();//���
	void change10();//JQK=10
	void finalScore();//�̫��I��
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