// ASM_CramersRule.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"
#include<iostream>
using namespace std; 
short a, b, c, d, e, f, x, y;
short findXASM() {
	_asm {
		mov ax, c
		imul ax, e
		mov temp1, ax
		mov ax, b
		imul ax, f
		sub temp1, ax
		mov ax, temp1
		mov top, ax

		mov ax, a
		imul ax, e
		mov temp1, ax
		mov ax, b
		imul ax, d
		sub temp1, ax
		mov ax, temp1
		mov bottom, ax

		mov ax, 0 
		mov bx, 0

		//ALWAYS SET DX, TO TO ZERO 
		xor dx, dx
		mov ax, top
		idiv bottom
		mov x, ax
	}
	return x;
}
short findYASM() {

}

int main()
{
	short a, b, c, d, e, f, x, y;
	cout << "This program sloves the system of" << endl; 
    cout << "aX+by=c" << endl;
    cout << "dX + eY = f" << endl;
	cout << "enter the values of a,b, and c" << endl;
	cin >> a >> b >> c; 
	cout << "enter the values of d, e , f " << endl; 
	cin >> d >> e >> f;
	short temp1 =0 ; 
	short temp2 = 0; 
	short temp3 = 0; 
	short top = 0 ; 
	short bottom = 0; 
	
	short zero = 0;
	_asm
	{
		mov ax, a
		imul ax, f
		mov temp1, ax
		mov ax, c
		imul ax, d

		sub temp1, ax
		mov ax, temp1
		mov top, ax

		mov ax, a
		imul ax, e
		mov temp1, ax
		mov ax, b
		imul ax, d

		sub temp1, ax
		mov ax, temp1
		mov bottom, ax

		xor dx, dx //ALWAYS SET DX, TO TO ZERO 
		mov ax, top
		idiv bottom
		mov y, ax
		

		mov ax , c
		imul ax, e 
		mov temp1, ax
		mov ax, b
		imul ax, f 
		sub temp1, ax 
		mov ax, temp1 
		mov top, ax 

		mov ax,a 
		imul ax,  e 
		mov temp1, ax 
		mov ax, b
		imul ax,d 
		sub temp1, ax 
		mov ax, temp1
		mov bottom, ax 

		//mov ax, 0 
		//mov bx, 0

		 //ALWAYS SET DX, TO TO ZERO 
		 xor dx, dx
		 mov ax,top
		 idiv bottom
		 mov x, ax







		






	}
	//cout << top << endl;
	//cout << bottom << endl; 

	cout << "y "  << y << endl; 
	cout << "x " << x << endl; 

	system("PAUSE");
    return 0;
}

