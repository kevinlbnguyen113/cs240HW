//
//  main.cpp
//  240hw2try
//
//  Created by Tram-Anh Tran on 9/7/18.
//  Copyright © 2018 loc. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


int main() {
    short total=0,numberDrink,numberFood;
    cout<<"-----------Menu-----------"<<endl;
    cout<<"Drinks"<<setw(25)<< setfill('.')<< setw(19)<<right<<"$4"<<endl;
    cout << "Sandwiches"<<setw(25)<<setfill ('.')<<setw(15)<<right<< "$7"<<endl;
    cout<<"How many drinks?";
    cin>>numberDrink;
    cout<<"How many sandwiches?";
    cin>> numberFood;
    __asm
    {
        mov     ax,4;
        mul     numberDrink;
        mov     total, ax;
        mov     ax,7;
        mul     numberFood;
        add     ax,total;
        mov     total,ax;
    };
    cout<<"Your total bill " <<total<<" dollars"<<endl;
    return 0;
}

