// QuadraticEquation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<iomanip>
using namespace std; 
float a , b, c;
float neg1 = -1; 
float two = 2; 
float four = 4; 



int main()
{
	float resultX = 0; 

	cout << std::fixed;
	cout << std::setprecision(2);
	cout << "To see the two real roots of aX^2 + bX + c = 0 enter a,b,and c values";
		cin >> a >> b >> c;
	_asm
	{
		fld b
		fld b 
		fmul 
		fst resultX
		fld resultX
		fld four
		fld a
		fmul 
		fld c 
		fmul
		
		fsub 
		fst resultX

		fsqrt 
		fst resultX
		fld resultX
		fld b
		fld neg1
		fmul
		fadd
		fld a
		fld two
		fmul 
		fdiv	
		fst resultX

	}
	float resultx2; 
	_asm
	{
		fld b
		fld b
		fmul
		fld four
		fld a
		fmul
		fld c
		fmul
		fsub
		fsqrt
		
		fld b
		fld neg1
		fmul
		fsub
		fld a
		fld two
		fmul
		fdiv
		fmul neg1
		fst resultx2

	}
	cout <<"X1="<< resultX <<" X2="<<resultx2<< endl; 
	
	system("pause");
    return 0;
}

