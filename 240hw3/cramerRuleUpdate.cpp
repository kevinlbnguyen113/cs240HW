#include<iostream>
using namespace std;
short a, b, c, d, e, f, x, y;
short temp1 = 0;
short temp2 = 0;
short temp3 = 0;
short top = 0;
short bottom = 0;
short zero = 0;
short findXASM() {
	_asm 
	{
			mov		ax, c;
			imul		e;
			mov		temp1, ax;
			mov		ax, b;
			imul		f;
			sub		temp1, ax;
			mov		ax, temp1;
			mov		top, ax;
			mov 		ax, a;
			imul		ax, e;
			mov		temp1, ax;
			mov 		ax, b;
			imul 		ax, d;
			sub 		temp1, ax;
			mov 		ax, temp1;
			mov 		bottom, ax;
			mov 		ax, top;
			cwd
			idiv 		bottom;
			mov 		x, ax;
	}
	return x;
}
short findYASM() {
	_asm
	{
		mov 	ax, a
		imul 	ax, f
		mov 	temp1, ax
		mov 	ax, c
		imul 	ax, d

		sub 	temp1, ax
		mov 	ax, temp1
		mov 	top, ax

		mov 	ax, a
		imul 	ax, e
		mov 	temp1, ax
		mov 	ax, b
		imul 	ax, d

		sub 	temp1, ax
		mov 	ax, temp1
		mov 	bottom, ax

		xor 	dx, dx //ALWAYS SET DX, TO TO ZERO 
		mov 	ax, top
		idiv 	bottom
		mov 	y, ax
	}
	return y;
}

int main()
{
	cout << "This program sloves the system of" << endl;
	cout << "aX+by=c" << endl;
	cout << "dX + eY = f" << endl;
	cout << "enter the values of a,b, and c";
	cin >> a >> b >> c;
	cout << "enter the values of d, e , f ";
	cin >> d >> e >> f;
	findXASM();
	findYASM();
	cout << "X = " << x << endl;
	cout << "Y = " << y << endl;

	system("PAUSE");
	return 0;
}
