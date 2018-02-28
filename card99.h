#include<iostream>
#include<string>
#include <stdlib.h>
#include <time.h>
using namespace std;

class card99
{
public:
	card99()
	{
		my_color = { "\0" };
		my_number = 0;
	}
	void color(int a);
	void number(int b);

	string color();
	int number();
	void outputmycard();

	void function1();
	void function2();
	void nine9(int a);
	int money;//賭資
private:
	string my_color;//花色
	int my_number;//牌的數字
	int result = 0;//加起來的點數
	int num;//用幾副牌

	int temp;//出第幾張牌
	int a, b, c;
	int i, j, k = 1;
	bool sort = true;//true代表順時針　false代表逆時針
	bool icard[100][5][53];//第一個正列是第幾副牌,第二個正列是花色1是黑桃2是紅心3是方塊4是梅花,第三個正列是牌的數字

};