#include"Holdem.h"

void Holdem::SHUFFLE(int array[]){
	for (int i = 0; i < 52; i++){
		int j = rand() % 52; 
		int tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}

void Holdem::DEAL(int array[]){
	int temp;
	for (int i = 0; i < 5; i++)
		for (int j = i + 1; j < 5; j++)
			if (array[i] % 13 < array[j] % 13 || (array[i] % 13 == array[j] % 13 && array[i] < array[j]))
			{
				temp = array[i]; array[i] = array[j]; array[j] = temp;
			}
}

int Holdem::PAIR(int array[]){ 
	int P = 0;
	for (int i = 0; i < 5; i++)
		for (int j = i + 1; j < 5; j++)
			if ((array[i] - array[j]) % 13 == 0) P++;
	return(P);
}

int Holdem::FLUSH(int array[]){
	int F = 0;
	for (int i = 0; i < 4; i++) F = abs(array[i] / 13 - array[i + 1] / 13) + F;
	if (F > 0) F = 1;
	return(F);
}

int Holdem::STRAIGHT(int array[]){ 
	int S = 1;
	for (int i = 1; i < 4; i++) S = (array[i] % 13 - array[i + 1] % 13)*S;
	if (S == 1 && (array[0] % 13 - array[1] % 13 == 1 || array[0] % 13 - array[1] % 13 == 9)) S = 1;
	else S = 0;
	return(S);
}

int Holdem::OU(int i, int j, int k){
	int o;
	switch (i){
	case 1:
	case 2:
	case 3: o = i; break;
	case 4: o = 6; break;
	case 6: o = 7; break;
	default: switch (10 * j + k){
	case 11: o = 8; break;
	case 1: o = 4; break;
	case 10: o = 5; break;
	default: o = 0;
	}
	}
	return o;
}

int Holdem::findmax0(int array[])
{
	int max=0;
	for (int j = 0; j < 5; j++)
	{
		if (array[j]>max)
			max = array[j];
	}
	return max;
}
int Holdem::findmax1(int array[])
{
	int max=0;
	for (int i = 0; i < 5; i++)
		for (int j = i+1; j < 5; j++)
		{
			if (array[i] == array[j])
				max = i;
		}
	return max;
}

//執行遊戲
void Holdem::play(int fund)
{
	char suit[4][5] = { "梅花", "方塊", "紅心", "黑桃" };
	char number[13][3] = { "２", "３", "４", "５", "６", "７", "８", "９", "10", "Ｊ", "Ｑ", "Ｋ", "Ａ" };
	char out[9][7] = { "無賴", "一對", "兔胚", "三條", "順子", "同花", "葫蘆", "鐵枝", "同花順" };
	for (int i = 0; i < 52; i++) poker[i] = i;
	SHUFFLE(poker);
	DEAL(poker);

	//暗牌
	cout << "請問要下注多少錢: ";
	cin >> money;
	cout << "暗牌:" << endl << endl;
	for (int j = 1; j < 5; j++){
		cout << j << " 號參賽者的牌為:" << endl;
		for (int i = 3; i < 5; i++){
			cout << suit[poker[k] / 13] << number[poker[k] % 13] << "\t" << endl;

			if (j == 1){
				p1[i] = poker[k];
			}
			if (j == 2){
				p2[i] = poker[k];
			}
			if (j == 3){
				p3[i] = poker[k];
			}
			if (j == 4){
				p4[i] = poker[k];
			}
			k++;
		}
		if (j == 1)
		{
			cout << "是否繼續下注(1是0否): ";
			cin >> temp;
			if (temp == 1)
			{
				cout << "請問要繼續押注多少錢: ";
				cin >> temp;
				money += temp;
			}
			else
			{
				cout << "你選擇了不跟..." << endl;
				money = 0;
				break;
			}
			//亮牌
			cout << "亮牌:" << endl << endl;
			for (int i = 0; i <3; i++){
				cout << suit[poker[i] / 13] << number[poker[i] % 13] << "\t";
				p1[i] = poker[i];
				p2[i] = poker[i];
				p3[i] = poker[i];
				p4[i] = poker[i];
			}
			cout << endl;

			pair = PAIR(p1);
			straight = STRAIGHT(p1);
			flush = 1 - FLUSH(p1);
			score = OU(pair, flush, straight);
			cmp[j] = score;
		}
		if (j == 2)
		{
			pair = PAIR(p2);
			straight = STRAIGHT(p2);
			flush = 1 - FLUSH(p2);
			score = OU(pair, flush, straight);
			cmp[j] = score;
		}
		if (j == 3)
		{
			pair = PAIR(p3);
			straight = STRAIGHT(p3);
			flush = 1 - FLUSH(p3);
			score = OU(pair, flush, straight);
			cmp[j] = score;
		}
		if (j == 4)
		{
			pair = PAIR(p4);
			straight = STRAIGHT(p4);
			flush = 1 - FLUSH(p4);
			score = OU(pair, flush, straight);
			cmp[j] = score;
		}

		cout << endl << j << "號牌型為" << out[score] << endl << endl;
	}
	maxc = findmax0(p1);
	//比較誰勝出
	for (int i = 2; i < 5; i++)
	{
		if (cmp[i]>cmp[max])
			max = i;
		if (cmp[i] == cmp[max])
		{
			if (cmp[i] == 0)
			{
				if (i == 2)
					if (findmax0(p2) > maxc)
						max = i;
				if (i == 3)
					if (findmax0(p3) > maxc)
						max = i;
				if (i == 4)
					if (findmax0(p4) > maxc)
						max = i;
			}
			if (cmp[i] == 1)
			{
				if (i == 2)
					if (findmax1(p2) > maxc)
						max = i;
				if (i == 3)
					if (findmax1(p3) > maxc)
						max = i;
				if (i == 4)
					if (findmax1(p4) > maxc)
						max = i;
			}

		}

	}
	if (max != 1)
	{
		cout << "妳輸了..." << endl;
		cout << "你獲得0元..." << endl;
		money = 0;
	}
	else
	{
		cout << "妳贏了..." << endl;
		money *= 4;
		cout << "你獲得" << money << "元..." << endl;
	}
}