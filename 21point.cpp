#include <iostream>  
#include <string>  
#include <time.h>
#include "21point.h"
using namespace std;
void member::setCard(int k, int unk)
{
	known = k;
	unknown = unk;
	point = k + unk;
}
void member::toChar()
{
	if (known == 1)
		kCard = "A";
	else if (known == 11)
		kCard = "J";
	else if (known == 12)
		kCard = "Q";
	else if (known == 13)
		kCard = "K";
	else if (known == 10)
		kCard = "10";
	else
		kCard = to_string(known);
	if (unknown == 1)
		unkCard = "A";
	else if (unknown == 11)
		unkCard = "J";
	else if (unknown == 12)
		unkCard = "Q";
	else if (unknown == 13)
		unkCard = "K";
	else if (unknown == 10)
		unkCard = "10";
	else
		unkCard = to_string(unknown);

}
void member::playGame()
{
	int newCard,cardA,cardB;
	point = known + unknown;
	if (known == 1 || unknown == 1)
	{
		
		if (known == 1){
			cardA = known;
			cardB = unknown;
		}
		else if (unknown == 1){
			cardA = unknown;
			cardB = known;
		}
		if (cardB + 11 > 16)point = cardB + 11;
		else
		while(point<17)
		{
			newCard = drawAcard();
			if (newCard + cardB + 11> 16 && newCard + cardB + 11<22)point = newCard + cardB + 11;
			else 
				point += newCard;
		}
	}
	else
		while (point<17)
		{
			newCard = drawAcard();
			point += newCard;

		}
	if (point > 21)
		point = 0;
}
int member::drawAcard()
{
	srand(time(0));
	int newCard;
	newCard = rand() % 13 + 1;
	return newCard;
}
void member::change10()
{
	if (known > 10)known = 10;
	if (unknown > 10)unknown = 10;

}
void member::finalScore()
{
	if (point == 0)
		score = "  OUT!";
	else
		score = to_string(point);

}