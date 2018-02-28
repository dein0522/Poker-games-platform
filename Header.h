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
	void nine9();

private:
	string my_color;//花色
	int my_number;//牌的數字
};