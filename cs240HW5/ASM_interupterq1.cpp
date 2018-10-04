// ASM_interupter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> 
using namespace std; 


int main()
{
	
	short networks; 
	short floppydrives; 
	short mem;
	
	//short c = 1100111010011100b;
	short bc = 0x0b;

	_asm {
		mov ax, 1100111010011100b;
		shr ax,1 // bit1
		mov ax, 1100111010011100b;
		shr ax, 2 // bit2
		mov ax, 1100111010011100b;

		shr ax,3// bit 3
		mov bx,ax


		and ax ,bc
		cmp ax,0
		je Set_mem16
		cmp ax, 1
		je Set_mem32
		cmp ax, 2
		je Set_mem42
		cmp ax, 3
		je Set_mem64
			Set_mem16:
			mov mem,16
			jmp cont1
			Set_mem32:
			mov mem, 32
			jmp cont1 
			Set_mem42:
			mov mem, 42
			jmp cont1 
		
			Set_mem64:
			mov mem, 64
			jmp cont1
			
				cont1:


		
			mov ax, 1100111010011100b;
		mov bc , 0xf000
		shr ax,7 // bit 7
	
		and ax,bc
		cmp ax, 0 
		je floppy1
		cmp ax, 1 
		je floppy2
			floppy1:
		mov floppydrives, 1
			jmp cont2
			floppy2:
		mov floppydrives,2
			jmp cont2

			cont2:

		mov ax, 1100111010011100b;
		shr ax, 14
		mov networks ,ax
	
	

		
	
		
		
		cont:



	}

	cout <<"number of n pritners connected to computer "<< networks << endl;

	cout <<"number of floopy drives "<< floppydrives << endl;

	cout << "the size of ram in Gigs " << mem << endl; 
	system("pause");

    return 0;
}

