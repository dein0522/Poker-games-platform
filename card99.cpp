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
	cout << "�п�J�n�δX�ƵP: ";
	cin >> num;
	money = x;

	for (i = 0; i < 100; i++)
		for (j = 0; j < 5; j++)
			for (k = 0; k < 14; k++)
				icard[i][j][k] = false;//�٨S��쪺�P��false
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
	cout << "�[�_�Ӫ��I�Ƭ�" << result << endl;
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
		cout << 'p' << i << "���P��" << endl;
		for (j = 1; j < 6; j++)
		{
			player[i][j].outputmycard();
		}
		cout << 'p' << i << "�п�J�n��ĴX�i�P: ";
		if (i != 1)
		{
			temp = rand() % 5 + 1;
			cout << temp << endl;
		}
		else
		{
			cin >> temp;
		}
		string sen = { "spade" };//�ΨӤ��
		if (player[i][temp].number() == 1 && player[i][temp].color() == sen)//�®�1�����p
			result = 0;
		else if (player[i][temp].number() == 10)//10�����p
		{
			char input;
			cout << "�п�J�[�δ�: ";
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
		else if (player[i][temp].number() == 11)//j�����p
			result += 0;
		else if (player[i][temp].number() == 12)//Q�����p
		{
			char input;
			cout << "�п�J�[�δ�: ";
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
		else if (player[i][temp].number() == 13)//k�����p
			result = 99;

		else if (player[i][temp].number() == 5)//5�����p
		{
			cout << "�аݧA�n���w�ĴX�쪱�a:�@";
			if (i != 1)
			{
				i = rand() % 4 + 1;
				cout << i << endl;
			}
			else
			cin >> i;
			i--;
		}
		else if (player[i][temp].number() == 4)//4�����p
		{
			sort = false;
			break;
		}
		else
			result += player[i][temp].number();
		cout << endl << "�[�_�Ӫ��I�Ƭ�" << result << endl << endl;

		while (icard[a][b][c])//����P
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
				cout << "�A��o" << money << "��...." << endl;
				break;
			}
			else
			{
				cout << "�p��F...." << endl;
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

		cout << 'p' << k << "���P��" << endl;
		for (j = 1; j < 6; j++)
		{
			player[k][j].outputmycard();
		}
		cout << 'p' << k << "�п�J�n��ĴX�i�P: ";
		if (k != 1)
		{
			temp = rand() % 5 + 1;
			cout << temp << endl;
		}
		else
			cin >> temp;
		string sen = { "spade" };//�ΨӤ��
		if (player[k][temp].number() == 1 && player[k][temp].color() == sen)//�®�1�����p
			result = 0;
		else if (player[k][temp].number() == 10)//10�����p
		{
			char input;
			cout << "�п�J�[�δ�: ";
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
		else if (player[k][temp].number() == 11)//j�����p
			result += 0;
		else if (player[k][temp].number() == 12)//Q�����p
		{
			char input;
			cout << "�п�J�[�δ�: ";
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
		else if (player[k][temp].number() == 13)//k�����p
			result = 99;

		else if (player[k][temp].number() == 5)//5�����p
		{
			cout << "�аݧA�n���w�ĴX�쪱�a:�@";
			if (k != 1)
			{
				k = rand() % 4 + 1;
				cout << k << endl;
			}
			else
			cin >> k;
			k--;
		}
		else if (player[k][temp].number() == 4)//4�����p
		{
			sort = true;
			break;
		}
		else
			result += player[k][temp].number();
		cout << endl << "�[�_�Ӫ��I�Ƭ�" << result << endl << endl;

		while (icard[a][b][c])//����P
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
				cout << "�A��o" << money << "��...." << endl;
				break;
			}
			else
			{
				cout << "�p��F...." << endl;
				money = 0;
				break;
			}
		}
		i = 4;
	}


}