// Fstub ASM.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<iomanip>
using namespace std;
float a, b, c, h, width, length1;
float two = 2;
void enterTriVals()
{
	cout << "enter the values of for the triangle a b c  and h : "; 
	cin >> a >> b >> c >> h; 

}
void enterSquarevalue()
{
	cout << "enter the values of for the square (width and length)";
	cin >> width >> length1; 
}

int main()
{
	cout << "   /\\        __________ " << endl;
	cout << "a /|h\\ b    |          |"    << endl;
	cout << " / |  \\     |          | width" << endl;
	cout << "/__|___\\    |__________|  " << endl;
	cout << "    c           length " << endl;
	enterTriVals();
	enterSquarevalue();
	float resultA = 0;
	_asm // calculate the area of  a triangle 
	{
		fld b; // base times height
		fld h;
		fmul 
		fld two
		fdiv // divided by 2 
		fst resultA
	}
	float resultTP;
	_asm  // perimeter of a triangle 
	{
		fld a
		fld b
		fadd
		fld c // add a + b + c
		fadd
		fst resultTP
	}
	float resultSQA;
	_asm
	{
		fld width;
		fld length1; // width  times height
		fmul 
		fst resultSQA
	}
	float resultSQP; 
	_asm
	{
		fld width;
		fld length1;
		fadd //width plus length times 2  
		fmul two
		fst resultSQP
	}
	cout << std::fixed;
	cout << std::setprecision(2);
	cout << "Area of the triangle .... " << resultA << endl;
	cout << "Perimeter of the trinagle...." << resultTP << endl; 
	cout << "Area of the rectangle....." << resultSQA << endl; 
	cout << "per of the rectangle....." << resultSQP << endl; 


	system("pause");
    return 0;
}

