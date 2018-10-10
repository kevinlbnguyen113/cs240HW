#include "stdafx.h"
#include<iostream>
using namespace std;
int sizef = 5;
int a[5] = { 7,2,4,5,1 };
void print()
{
	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << " ";
	}
}


int main()
{
	cout << "original array "; 
	print();
	cout << endl; 
	_asm
	{
		mov ecx, sizef // ECS MUST BE USED
		dec ecx // <--- ecx must be used for this methhod
		
		nextScan: // moves to the next index 
		mov ebx, ecx
		mov eax,0 

			Nextcomp:
			mov edx, a[eax] // edx and edi will be used to store our indexs
			mov edi, a[eax+4]
			cmp edx,edi
			jl noswap // jmp if less than 
			mov a[eax], edi // <--- swap
			mov a[eax+4], edx
			noswap:
			add eax,4
			sub ebx,1
			jnz nextcomp
			loop nextScan // subtracts 1 from ecs regeistor and if ecs is zero it does not jump 
		
	}
	cout << "new array ";
	print();
	cout << endl;
	system("pause");
    return 0;
}
