﻿// ASStest1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std; 
int a[5] = { 9,3,22,8,1 };  //0//4//8//12//16//20
int countA = 5;
void print()
{
	for (int i = 0; i < countA; i++)
	{
		cout << a[i] << " ";
	}
}

int main()
{
	cout << "orginal array ";
	print();
	cout << endl;
	_asm
	{
		mov ecx, countA
		dec ecx

		nextscan : 
			mov ebx, ecx
			mov eax, 0

				nextcomp :

				mov edx, a[eax]
				mov edi, a[eax+4] // asm																		
				cmp edx, edi

				jl noswap

				mov a[eax], edi // swap
				mov a[eax+4], edx// <--
				noswap :
				add eax, 4
				sub ebx,1
				jnz nextcomp

				loop nextscan
	}
	cout << "new array ";
	print();
	cout << endl;

	system("pause");
    return 0;
}

