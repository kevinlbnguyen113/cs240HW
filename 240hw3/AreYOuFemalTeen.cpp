// ASM 7-11 Conveniet_Store.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
char name;
int age = 13;
char gender;

void femaleteen()
{
	cout << "you are a female teen" << endl;
}
void notFemaleteen()
{
	cout << "you are not a female teen" << endl;
}
int main()
{
	char name; 
	int age = 10	; 
	char gender = 'f'; 

	_asm
	{
	
		cheeck19:
		cmp age, 19
		jg notfemaleteen
		cheeck12:
		cmp age, 12
		jl notfemaleteen
		cheeckgender:
		cmp gender, 'f'
		jne notfemaleteen
		call femaleteen
		jmp cont

			notfemaleteen:
		call notFemaleteen
			jmp cont

		



		
		cont:







	}
	system("pause");
	
    return 0;
}

