//
//  main.cpp
//  hw3p1
//
//  Created by Tram-Anh Tran on 9/16/18.
//  Copyright © 2018 loc. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

int drink,food,again,inches,total,tempFood1,tempFood2;
char typeOfdrink;
int asmMath(){
    __asm{
        mov     al,typeOfdrink;
        cmp     al,'s';
        jne     checkW
    s:
        mov     eax,2;
        imul    drink;
        mov     total,eax;
        jmp     nextItem;
    checkW:
        mov     eax, 1;
        imul    drink;
        mov     total,eax;
        jmp     nextItem;
    nextItem:
        mov     eax, inches;
        cmp     eax, 10;
        jne     twelveInches;
    tenInches:
        mov     eax, 3;
        imul    food;
        mov     tempFood1,eax;
        mov     eax, total;
        add     eax,tempFood1;
        mov     total, eax;
        jmp     moveTotal;
    twelveInches:
        mov     eax, 5;
        imul    food;
        mov     tempFood1,eax;
        mov     eax, total;
        add     eax,tempFood1;
        mov     total, eax;
        jmp     moveTotal;
    moveTotal:
        mov     total,eax;
    }
    return total;
}
void getDrink(){
    cout<<"How many drinks?";
    cin>> drink;
    cout<<"\tWhat kind of drink(s = soda, w = water)?";
    cin>> typeOfdrink;
}
void getFood(){
    cout<<"How many Sandwiches";
    cin>>food;
    cout<<"\tWhat size of sandwich(10 or 12 inches)?";
    cin>>inches;
}
int main(){
    cout<<right<<setw(30)<<setfill('-')<<" 7-11 Convenient Store"<<left<<setw(10)<<setfill('-')<<" "<<endl;
    cout<<"Drinks:\n";
    cout<<"\t Soda (s)"<<right<<setw(20)<<setfill ('.')<<"$2\n";
    cout<<"\t Water(w)"<<right<<setw(20)<<setfill('.')<<"$1\n";
    cout<<"Sandwiches\n";
    cout<<"\t 10 inches"<<right<<setw(19)<<setfill ('.')<<"$3\n";
    cout<<"\t 12 inches"<<right<<setw(19)<<setfill ('.')<<"$5\n";
    getDrink();
    getFood();
    total = asmMath();
    cout<<"Your total bill= "<<total<<endl;
    getDrink();
    getFood();
    total= asmMath();
    cout<<"Your total bill= "<<total<<endl;
    return 0;
}
