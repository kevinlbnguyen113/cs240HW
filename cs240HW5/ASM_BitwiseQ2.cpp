// ASM_Bitwise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
char input; 
short convert;
short c, temp,two=2;
void printValid()
{
	cout << "valid";
	
}
void printInvalid()
{
	cout << "invalid ID ";
	 
}
void takeInput()
{

}
void funct(short a)
{
	_asm
	{
		mov ax, a
		mov c, 0x000F
		and c, ax
		mov bx, c

		mov c, 0x000f
		shr ax, 4
		and c, ax
		add bx, c

		mov c, 0x000f
		shr ax, 4
		and c, ax
		add bx, c

		mov c, 0x000f
		shr ax, 4
		and c, ax
		add bx, c
		mov temp, bx
		mov ax, temp

		cwd
		idiv  two
		cmp dx, 1
		je _odd
		_even :
		call printValid
			jmp cont
			_odd :
		call printInvalid





		cont:

	}

}
int main()

{

	short beef = 0xBEEF; 
	short Fade = 0xFADE; 
	short Cabde = 0xCABE;
	cout << "BEEF is " ; 
	funct(beef);
	cout << "for the family" << endl;
		cout << "Fade is ";
	funct(Fade);
	cout << "for the family" << endl;
	cout << "Cabe is ";
	funct(Cabde);
	cout << "for the family" << endl;


	
	system("pause");
    return 0;
}

