// ASM_3D_array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std; 
int a[3][3][2] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18 }; //0,4,8,12,16,20,24,28,32,36,40,44,48,52,56,60,,64,68,72
int totalnumberofShirts = 0; 
int totalnumberofMeds = 0; 
int totalnumberofShorts = 0; 
int totalnumberOfReds = 0; 
int main()
{
	_asm {
		lea esi, a 

		mov ebx,18 
		SumTotal: 
		cmp ebx, 0
			jz termTotal
			mov eax, [esi]
			add esi, 4
			add totalnumberofShirts, eax
			sub ebx, 1;
			jmp SumTotal
			termTotal:

		lea esi, a
		add esi, 8  // start at index 3 
		mov ebx, 3 // i only want this to loop 3 times 
		sumTotalMedians:  // loop 
		mov eax, [esi]
		add totalnumberofMeds, eax // add the first index
		add esi, 4 // add the second index
		mov eax, [esi]
		add totalnumberofMeds, eax
		sub ebx, 1 
		cmp ebx, 0
		jz termMedians
		add esi, 20 // move up to the next  set of medium shirts 
		jmp sumTotalMedians
			termMedians:

		lea esi,a 
		mov ebx, 9
			SumTotalShorts: // <-- sum up the shorts 
			mov eax, [esi]
			add totalnumberofShorts, eax
			add esi,8
			sub ebx,1
			cmp ebx, 0
			jz termShort
			jmp SumTotalShorts
			termShort:

		
	

	lea esi, a
	mov ebx, 6 
		SumtotalRed: // <-- sums up the reds 
		cmp ebx,0 
		jz termRed
		mov eax, [esi]
		add totalnumberOfReds, eax 
		add esi,4 
		sub ebx,1
		jmp SumtotalRed
		termRed: 
		

	}
	cout << "total of all shirts " << totalnumberofShirts << endl; 
	cout << "total amt of medians " << totalnumberofMeds << endl;
	cout << "total amt of shorts sleeves " << totalnumberofShorts << endl;
	cout << "total amt of Reds " << totalnumberOfReds << endl;


	system("pause"); 
    return 0;
}

