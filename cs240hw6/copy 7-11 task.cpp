// copy 7-11 task.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;
float soda = 2.25;
float water = 1.75;
float juice = 2.80;
float inches10 = 3.45;
float inches12 = 5.25;
int numberofCustmers;
int numberofDrinks;
int numberofsandwichs;
float numberofDrinksF;
float numberofsandwichsF;
char kindsofdrinks;
int kindsofsandwitches;
float total = 0.00;
void displayCustomers()
{
	cout << "Customer 1:" << endl; 
}

void printTotalAmt()
{
	cout << "Your total bill is $"; 

	cout << total;
	cout << endl; 
	total = 0;
}

void displayTotal()
{

}
void floatnumDrinks()
{
	numberofDrinksF = numberofDrinks;
}
void floatnumSandwiches()
{
	numberofsandwichsF = numberofsandwichs;

}
void inputnumberOfCustomers()
{
	cout << "Enter the number of customers";
	cin >> numberofCustmers;
}
void takeinputCus()
{
	total = 0; 
	cout << "how many drinks?";
	cin >> numberofDrinks;
	cout << "what kinds of drinks (caps please S=soda, W=waater, J=juice)?";
	floatnumDrinks();
	cin >> kindsofdrinks;
	cout << "How many sandwitches";
	cin >> numberofsandwichs;
	floatnumSandwiches();
	cout << "what size of sandwitches (10/12)";
	cin >> kindsofsandwitches;
}



int main()
{
	cout << "-------7-11 Convenient Store-------" << endl; 
	cout << "Drinks" << endl; 
	cout << "  Soda(S)....................$2.25" << endl;
	cout << "  Water(W)...................$1.75" << endl;
	cout << "  Juice(J)...................$2.80" << endl;
	cout << "Sandwiches" << endl; 
	cout << "  10 inches.......................$3.45" << endl;
	cout << "  12 inches.......................$5.25" << endl;
	cout << std::fixed;
	cout << std::setprecision(2);
	_asm 
	{
		call inputnumberOfCustomers
		mainLoop: 
		cmp numberofCustmers,0
		je termProgram 
		call displayCustomers
		call takeinputCus
			
			mov al, kindsofdrinks
			cmp al, 'S'
			je calcSoda
			cmp al, 'J'
			je calcJuice // comparasions 
			jmp calcWater

			calcSoda:
			fld soda
			fld numberofDrinksF
			fmul
			fld total
			fadd
			fst total
			jmp Nextcalc

		

	
				calcJuice: 
				fld juice
				fld numberofDrinksF
				fmul
				fld total
				fadd
				fst total
				jmp nextCalc
				
			
					calcWater:
					fld water
					fld numberofDrinksF
					fmul
					fld total
					fadd
					fst total
					jmp nextCalc




						nextCalc:
						mov eax, kindsofsandwitches
						cmp eax,12 
						je Calc12inch
						jmp Calc10inch 

							calc12inch: 
						fld inches12
						fld numberofsandwichsF
						fmul 
						fld total
						fadd
						fst total
						jmp printTotal

							calc10inch:
							fld inches10
							fld numberofsandwichsF
							fmul
							fld total
							fadd
							fst total
							jmp printTotal

								printTotal: 
								call printTotalAmt
								dec numberofCustmers
								jmp mainLoop
								termProgram: 

	}

	cout << endl; 
	system("pause");
    return 0;
}

