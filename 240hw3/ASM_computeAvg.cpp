// ASM_computeAvg.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int Score; 
int total;
int numberOfentries; 
int one = 1; 
int average;
void inputscore()
{
	cin >> Score;
}
int main()
{
	cout << "lets compute your scorces advergae " << endl;
	_asm
	{
	enterScore: 
		call inputscore
			cheeckNegOne:
		cmp Score, -1; 
		je calcAvg
		mov eax, Score
		add total, eax
		mov eax, numberOfentries
		add eax, one
		mov numberOfentries, eax
		jmp enterScore

			calcAvg:
		xor edx, edx
		mov eax, total
		idiv numberOfentries
		mov average, eax
		


	}
	cout << "here is your avg " << average << endl; 
	system("PAUSE"); 
    return 0;
}

