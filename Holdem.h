#ifndef _holdem
#define _holdem
#include<iostream>
#include<cstdlib>
#include<string>
#include <ctime>
using namespace std;
class Holdem{
public:
	void SHUFFLE(int array[]);
	void DEAL(int array[]);
	int PAIR(int array[]);
	int FLUSH(int array[]);
	int STRAIGHT(int array[]);
	int OU(int,int,int);
	int findmax0(int array[]);
	int findmax1(int array[]);
	void play(int fund);
	int money;

private:
	int k = 3;
	int player[4];
	int poker[52];
	int p1[5], p2[5], p3[5], p4[5];
	int pair;
	int straight;
	int flush;
	int score;
	
	int temp;
	int cmp[5];
	int max = 1;
	int maxc;
};
#endif