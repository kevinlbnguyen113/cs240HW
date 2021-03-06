// Study ASM Bitwise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std; 
short loop_count = 0; 
short sprinkler = 0x6A2F; 
short s_Count = 0; 
void displayLoopCount()
{
	cout << loop_count << " "; 
}


int main()
{
	_asm
	{
		mov bx, sprinkler;
		
		pt1: 
		cmp loop_count, 16; 
			je Done_pt1; 
			mov ax, bx; 
			and ax, 0000000000000001b; // and ax 
			cmp ax, 0000000000000001b; // compare ax to 1 
			je IncCount; 
			shr bx, 1; 
			inc loop_count;  // count ++ 
			
			jmp pt1; 
	
		

		IncCount:
			inc s_Count;
			inc loop_count; 
			shr bx, 1;
			jmp pt1; 
			done_pt1:
	}
	cout << "number of active sprinklers" << endl; 
	cout << s_Count;
	cout << endl;
	cout << "the defective sprinklers ... ";
	_asm 
	{
		mov loop_count,16
		mov bx, sprinkler
		pt2:
	
		cmp loop_count,0 
		je donePt2
		
		mov ax,bx 
		and ax, 1000000000000000b
		cmp ax, 1000000000000000b
		jne returnpos
		shl bx,1
		dec loop_count
		jmp pt2

			returnpos: 
		call displayLoopCount
			shl bx, 1
			dec loop_count; 
		jmp pt2;
		donePt2:

	}
	system("pause");
    return 0;
}

