//
//  main.cpp
//  hw240hwp2
//
//  Created by Tram-Anh Tran on 9/8/18.
//  Copyright © 2018 loc. All rights reserved.
//

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int a, b, c, h, _length, width, trianglePerimeter, triangleArea, rectanglePerimeter, rectangleArea, two = 2;
	cout << "Enter the values of a, b, c, h:";
	cin >> a >> b >> c >> h;
	cout << "Enter the values of length and width of the rectangle:";
	cin >> _length >> width;
	__asm {
		mov     eax, c;
		imul    h;
		div     two;
		mov     triangleArea, eax;
		mov     eax, a;
		add     eax, b;
		add     eax, c;
		mov     trianglePerimeter, eax;
		mov     eax, width;
		imul    _length;
		mov     rectangleArea, eax;
		mov     eax, width;
		add     eax, _length;
		imul    two;
		mov     rectanglePerimeter, eax;
	}
	cout << "\t" << "Triangle\n";
	cout << "   /\ " << endl;
	cout << "a /|h\ b"<< endl;
	cout << " / |  \ " << endl;
	cout << "/__|___\ " << endl;
	cout << "    c   " << endl;
	cout << "\t" << "\t" << "Area" << setw(30) << setfill('.') << right << triangleArea << endl;
	cout << "\t" << "\t" << "Perimeter" << setw(25) << setfill('.') << right << trianglePerimeter << endl;
	cout << "\t" << "Rectangle\n";
	
	cout << "___________ " << endl;
	cout << "|          |" << endl;
	cout << "|          | w " << endl;
	cout << "|          |" << endl;
	cout << "|          |" << endl;
	cout << "___________ " << endl;
	cout << "     len " << endl;
	cout << "\t" << "\t" << "Area" << setw(30) << setfill('.') << right << rectangleArea << endl;
	cout << "\t" << "\t" << "Perimeter" << setw(25) << setfill('.') << right << rectanglePerimeter << endl;
	return 0;
}
