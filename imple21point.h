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
	void dealing();//�o�P
	void initializeForAI();//AI���Ҧ��ʧ@
	void output();//���G
	void gameble();//�p����
	void play();//�����L�{
	int test(vector<int>);//�O�_�W�L21�I
	void newCard();//��@�i
	void total(vector<int>, int);//�p���`�I��
	void POINT21(int fund);//��Ӫ����L�{
	void play21point(int);//�ۤv��P�����L�{
	void Double();//�O�_double���
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