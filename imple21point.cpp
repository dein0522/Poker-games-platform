#include <iostream>  
#include <string>
#include <time.h>
#include <iomanip>
#include <vector>
#include "imple21point.h"
using namespace std;
string nameList[13] = { "You", "Banker", "Bob", "Yeh", "Dennis", "Andy", "David", "Ted", "Ken", "Cooper", "Monster", "Danial", "Frank" };
void imple21point::POINT21(int fund)
{
	out=max = 0;
	player.clear();
	cards.clear();
	gamebleFund = fund;
	cout << "How many players" << endl;
	cin >> numOfplayers;
	numOfplayers += 2;
	dealing();
	initializeForAI();
	play();
	output();
}
void imple21point::setFund(int fund)
{
	gamebleFund = fund;
}
void imple21point::dealing()
{
	int k, unk;
	for (int i = 0; i < numOfplayers; i++)
	{
		member mem;
		k = rand() % 13 + 1;
		unk = rand() % 13 + 1;
		mem.setCard(k, unk);
		player.push_back(mem);
		player[i].toChar();
	}
}
void imple21point::initializeForAI()
{
	cout << endl << "Cards of every player" << endl << endl;
	for (int i = 1; i < numOfplayers; i++)
	{
		cout << nameList[i] << setw(3) << player[i].getkCard() << endl;
		player[i].change10();
		player[i].playGame();
		player[i].finalScore();
		if (player[i].getPoint()>max)
			max = player[i].getPoint();
	}
}
void imple21point::output()
{
	cout << endl << "Total Points" << endl << endl;
	for (int i = 0; i < numOfplayers; i++)
	{
		cout << nameList[i] << setw(3) << player[i].getScore();
		if (player[i].getPoint() == max)cout << " WINNER!!" << endl;
		else cout << endl;

	}
	gameble();
	
}
void imple21point::gameble()
{
	if (player[0].getPoint() == max)
		gamebleFund *= 2;
	else
		gamebleFund = 0;
}
void imple21point::newCard()
{
	string card;
	int newCard;
	newCard = rand() % 13 + 1;
	card = to_string(newCard);
	if (newCard == 11)
		card = "J";
	else if (newCard == 12)
		card = "Q";
	else if (newCard == 13)
		card = "K";
	else if (newCard == 1)
		card = "A";
	cout << "You get this card" << card << endl;
	if (newCard > 10)newCard = 10;
	cards.push_back(newCard);
	
}
void imple21point::play()
{
	int  proceed, cardA, cardB, point;
	string card;
	cout << endl << "You first" << endl << "Your card is " << player[0].getkCard() << " " << player[0].getUnkCard() << endl << "Do you want another card?" << endl;
	cout << "(0)YES (1)NO" << endl;
	cin >> proceed;
	player[0].change10();
	if (player[0].getKnown() == 1 || player[0].getUnknown() == 1)
	{
		if (player[0].getKnown() == 1){
			cardA = player[0].getKnown();
			cardB = player[0].getUnknown();
		}
		else if (player[0].getUnknown() == 1){
			cardA = player[0].getUnknown();
			cardB = player[0].getKnown();
		}
	}
	play21point(proceed);
	if (!out)Double();

	if (!out){
		if (player[0].getKnown() == 1 || player[0].getUnknown() == 1){
			cout << "Do you want A to be 1 or 11?" << endl;
			cin >> cardA;
			point = cardA + cardB;
		}
		else
			point = player[0].getKnown() + player[0].getUnknown();
		total(cards, point);
	}
}
void imple21point::play21point(int proceed)
{
	while (!proceed)
	{
		newCard();
		if (test(cards)){
			cout << "You are out!" << endl;
			player[0].setCard(0, 0);
			player[0].finalScore();
			out = 1;
			break;
		}
		cout << "Another card?" << endl;
		cout << "(0)YES (1)NO" << endl;
		cin >> proceed;
	}
}
void imple21point::Double()
{
	int proceed;
	cout << "Do you want to double your money and get another card?" << endl;
	cout << "(0)YES (1)NO" << endl;
	cin >> proceed;
	if (!proceed)
	{
		gamebleFund *= 2;
		newCard();
		if (test(cards)){
			cout << "You are out!" << endl;
			player[0].setCard(0, 0);
			player[0].finalScore();
			out = 1;
		}
	}
}
int imple21point::test(vector<int> cards)
{
	int sum = 0;
	for (int i = 0; i < cards.size(); i++)
		sum += cards[i];
	sum += player[0].getKnown() + player[0].getUnknown();
	if (sum > 21)
		return 1;
	return 0;
}
void imple21point::total(vector<int> cards, int point)
{
	int sum = point;
	for (int i = 0; i < cards.size(); i++)
	{
		if (cards[i] == 1)
		{
			cout << "Do you want A to be 1 or 11?" << endl;
			cin >> cards[i];
		}
		sum += cards[i];
	}
	if (sum > 21)sum = 0;
	if (sum>max)
		max = sum;
	player[0].setCard(sum, 0);
	player[0].finalScore();
}