// Asm_pratice_bubble sort_loop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std; 
int a[5] = { 2, 3, 8, 4, 1 };
void print()
{
	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << " "; 
	}
}
int sizeA = 5; 
int main()
{
	_asm{
		mov ebx, sizeA
		sub sizeA,1

		MainLoop:
		mov ebx, sizeA
		mov eax, 0 
		
			nextscan: 
		mov edx , a[eax]
		mov edi, a[eax+4]
		cmp edx, edi 
			jl noswap
			mov a[eax], edi
			mov a[eax+4],edx 
			noswap:
		add eax, 4
			sub ebx, 1
			cmp ebx, 0
			jnz nextscan
			sub sizeA, 1
			cmp sizeA, 0
			jnz mainLoop


	



	}
	cout << "sorted array";

	print();
	cout << endl; 
	system("pause");
    return 0;
}

