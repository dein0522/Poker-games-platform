#ifndef _imple21point
#define _imple21point
#include <iostream>  
#include <string>  
#include <time.h>
#include <iomanip>
#include <vector>
#include "21point.h"
using namespace std;
class imple21point
{
public:
	void dealing();//發牌
	void initializeForAI();//AI的所有動作
	void output();//結果
	void gameble();//計算賭資
	void play();//玩的過程
	int test(vector<int>);//是否超過21點
	void newCard();//抽一張
	void total(vector<int>, int);//計算總點數
	void POINT21(int fund);//整個玩的過程
	void play21point(int);//自己抽牌玩的過程
	void Double();//是否double賭資
	void setFund(int);
	int getFund(){ return gamebleFund; };
private:
	int numOfplayers;
	int gamebleFund;
	int max = 0;
	int out = 0;
	vector<member> player;
	vector<int> cards;
};
#endif