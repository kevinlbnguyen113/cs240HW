// ASM_arrayloops.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int numberofblacks = 0 ;
int numberofgreens = 0 ;
int numberofreds = 0 ;
int numberofblues = 0;
int total = 0 ;
int numberoflarges = 0;
int rowsSumArray = 3;
int columnsSumArray = 4;
int storage = 0;
int rows = 4;
int col = 4;
void printNumbrOfBlacks()
{
	cout << "Total number of all blacK shirts " << numberofblacks << endl;
}
void printTotal()
{
	cout<<"Total number of all shirts " << total << endl;
}
void printTotalOflarge()
{
	cout << "Total number of all  larges " << numberoflarges << endl;
}
void outputnumber()
{
	cout << storage << endl; 
}
int a[4][4] = {
	{10,29,30,40}, //0 //4//8//12 <--- address in memoray 
	{20,10,40,30}, //16//20//24//28
	{5,15,20,25},  //32//36//40//44
	{30,25,20,15}, //48//52//56//60
};

int rowindex = 1; 

int main()

{
	int loopcounter = 0;

	_asm// 
	{
		lea esi, a

       
		loopPrintTotal:
		
		cmp loopcounter, 60
		jg TermloopT1
		add esi, 4
		mov eax, [esi]
		add total, eax
		add loopcounter, 4
		mov eax, 0
		jmp loopPrintTotal
			TermloopT1:
		call printTotal
			
		lea esi, a
		add esi,8

		mov loopcounter,0 
		LoopTotalLarge: 
		cmp loopcounter, 56 
		jg termLoopT2
		mov eax, [esi]
		add numberoflarges, eax 
		add esi, 16 
		add loopcounter, 16 
		jmp LoopTotalLarge
			termLoopT2:
		call printTotalOflarge

			lea esi, a
			add esi, 48
			mov loopcounter, 48
	
			LoopTotalBlacks :
		cmp loopcounter, 60 
			jg termLoopT3
			mov eax, [esi]
			add numberofblacks, eax
			add esi, 4
			add loopcounter, 4
			jmp LoopTotalBlacks
			termLoopT3 :
		call printNumbrOfBlacks


	
				
			
		




	

	
	}
	system("pause");



    return 0;
}

