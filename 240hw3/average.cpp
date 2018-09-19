//
//  main.cpp
//  240HW3p2
//
//  Created by Tram-Anh Tran on 9/17/18.
//  Copyright © 2018 loc. All rights reserved.
//

#include <iostream>
using namespace std;
int score,average,sum=0,counter=0,one=-1;

int getScore(){
    cout<<"Enter your score (-1) to stop:";
    cin>>score;
    return score;
}
    int (*scorePointer)()=getScore;

int main(){

    cout<<"let's compute your score's average:\n";
    getScore();
    __asm{
    startingPoint:
        mov     eax,score;
        cmp     eax,one;
        jne     keepAdding;
    equalone:
        mov     eax, sum;
        cdq
        idiv    counter;
        jmp     cont;
    keepAdding:
        mov     eax,sum;
        add     eax,score;
        mov     sum,eax;
        inc     counter;
        call    scorePointer;
        jmp     startingPoint;
    cont:
        mov     average,eax;
    }
    cout<<"Your average is : "<<average<<endl;
    return 0;
}


