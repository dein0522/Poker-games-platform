#include"card99.h"

card99 player[5][6];


void card99::color(int a)
{
	if (a == 1)
		my_color = { "spade" };
	if (a == 2)
		my_color = { "heart" };
	if (a == 3)
		my_color = { "diamond" };
	if (a == 4)
		my_color = { "club" };

}

string card99::color()
{
	return my_color;
}

void card99::number(int b)
{
	my_number = b;
}

int card99::number()
{
	return my_number;
}

void card99::outputmycard()
{
	cout << my_color;
	if (my_number == 11)
		cout << 'J' << endl;
	if (my_number == 12)
		cout << 'Q' << endl;
	if (my_number == 13)
		cout << 'K' << endl;
	if (my_number<11)
		cout << my_number << endl;
}

void card99::nine9(int x)
{
	cout << "請輸入要用幾副牌: ";
	cin >> num;
	money = x;

	for (i = 0; i < 100; i++)
		for (j = 0; j < 5; j++)
			for (k = 0; k < 14; k++)
				icard[i][j][k] = false;//還沒抽到的牌為false
	k = 0;
	srand((unsigned) time(NULL));
	for (j = 1; j < 5; j++)
	{
		i = 1;
		while (i != 6)
		{
			a = rand() % num + 1;
			b = rand() % 4 + 1;
			c = rand() % 13 + 1;
				if (icard[a][b][c] == false)
			{
				player[j][i].color(b);
				player[j][i].number(c);
				icard[a][b][c] = true;
				i++;
			}
		}
		cout << endl;
	}
	cout << "加起來的點數為" << result << endl;
	while (result<100)
	{
		if (sort == true)
			function1();
		if (sort == false && result<100)
			function2();
	}
	result = 0;
}

void card99::function1()
{
	if (k == 4)
		k = 1;
	else
		k++;
	for (i = k; i < 5; i++)
	{
		cout << 'p' << i << "的牌為" << endl;
		for (j = 1; j < 6; j++)
		{
			player[i][j].outputmycard();
		}
		cout << 'p' << i << "請輸入要丟第幾張牌: ";
		if (i != 1)
		{
			temp = rand() % 5 + 1;
			cout << temp << endl;
		}
		else
		{
			cin >> temp;
		}
		string sen = { "spade" };//用來比對
		if (player[i][temp].number() == 1 && player[i][temp].color() == sen)//黑桃1的情況
			result = 0;
		else if (player[i][temp].number() == 10)//10的情況
		{
			char input;
			cout << "請輸入加或減: ";
			if (i != 1)
			{
				input = '+';
				cout << input << endl;
			}
			else
				cin >> input;

			if (input == '+')
				result += 10;
			else
				result -= 10;
		}
		else if (player[i][temp].number() == 11)//j的情況
			result += 0;
		else if (player[i][temp].number() == 12)//Q的情況
		{
			char input;
			cout << "請輸入加或減: ";
			if (i != 1)
			{
				input = '+';
				cout << input << endl;
			}
			else
				cin >> input;
			if (input == '+')
				result += 20;
			else
				result -= 20;
		}
		else if (player[i][temp].number() == 13)//k的情況
			result = 99;

		else if (player[i][temp].number() == 5)//5的情況
		{
			cout << "請問你要指定第幾位玩家:　";
			if (i != 1)
			{
				i = rand() % 4 + 1;
				cout << i << endl;
			}
			else
			cin >> i;
			i--;
		}
		else if (player[i][temp].number() == 4)//4的情況
		{
			sort = false;
			break;
		}
		else
			result += player[i][temp].number();
		cout << endl << "加起來的點數為" << result << endl << endl;

		while (icard[a][b][c])//重抽牌
		{
			a = rand() % num + 1;
			b = rand() % 4 + 1;
			c = rand() % 13 + 1;
			if (icard[a][b][c] == false)
			{
				player[i][temp].color(b);
				player[i][temp].number(c);
				icard[a][b][c] = true;
				break;
			}
		}
		if (result > 99)
		{
			if (i != 1)
			{
				money += money / 3;
				cout << "你獲得" << money << "元...." << endl;
				break;
			}
			else
			{
				cout << "妳輸了...." << endl;
				money = 0; 
				break;
			}
		}
		k = 1;
	}
}

void card99::function2()
{
	if (i == 1)
		i = 4;
	else
		i--;
	for (k = i; k > 0; k--)
	{

		cout << 'p' << k << "的牌為" << endl;
		for (j = 1; j < 6; j++)
		{
			player[k][j].outputmycard();
		}
		cout << 'p' << k << "請輸入要丟第幾張牌: ";
		if (k != 1)
		{
			temp = rand() % 5 + 1;
			cout << temp << endl;
		}
		else
			cin >> temp;
		string sen = { "spade" };//用來比對
		if (player[k][temp].number() == 1 && player[k][temp].color() == sen)//黑桃1的情況
			result = 0;
		else if (player[k][temp].number() == 10)//10的情況
		{
			char input;
			cout << "請輸入加或減: ";
			if (k != 1)
			{
				input = '+';
				cout << temp <<endl;
			}
			else
				cin >> input;
			if (input == '+')
				result += 10;
			else
				result -= 10;
		}
		else if (player[k][temp].number() == 11)//j的情況
			result += 0;
		else if (player[k][temp].number() == 12)//Q的情況
		{
			char input;
			cout << "請輸入加或減: ";
			if (k != 1)
			{
				input = '+';
				cout << temp <<endl;
			}
			else
				cin >> input;
			if (input == '+')
				result += 20;
			else
				result -= 20;
		}
		else if (player[k][temp].number() == 13)//k的情況
			result = 99;

		else if (player[k][temp].number() == 5)//5的情況
		{
			cout << "請問你要指定第幾位玩家:　";
			if (k != 1)
			{
				k = rand() % 4 + 1;
				cout << k << endl;
			}
			else
			cin >> k;
			k--;
		}
		else if (player[k][temp].number() == 4)//4的情況
		{
			sort = true;
			break;
		}
		else
			result += player[k][temp].number();
		cout << endl << "加起來的點數為" << result << endl << endl;

		while (icard[a][b][c])//重抽牌
		{
			a = rand() % num + 1;
			b = rand() % 4 + 1;
			c = rand() % 13 + 1;
			if (icard[a][b][c] == false)
			{
				player[k][temp].color(b);
				player[k][temp].number(c);
				icard[a][b][c] = true;
				break;
			}
		}
		if (result > 99)
		{
			if (k != 1)
			{
				money += money / 3;
				cout << "你獲得" << money << "元...." << endl;
				break;
			}
			else
			{
				cout << "妳輸了...." << endl;
				money = 0;
				break;
			}
		}
		i = 4;
	}


}