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
	int money;//���
private:
	string my_color;//���
	int my_number;//�P���Ʀr
	int result = 0;//�[�_�Ӫ��I��
	int num;//�δX�ƵP

	int temp;//�X�ĴX�i�P
	int a, b, c;
	int i, j, k = 1;
	bool sort = true;//true�N���ɰw�@false�N��f�ɰw
	bool icard[100][5][53];//�Ĥ@�ӥ��C�O�ĴX�ƵP,�ĤG�ӥ��C�O���1�O�®�2�O����3�O���4�O����,�ĤT�ӥ��C�O�P���Ʀr

};