//
//  main.cpp
//  240HWp3
//
//  Created by Tram-Anh Tran on 9/8/18.
//  Copyright © 2018 loc. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    short fahrenheit,celcius,nine=9,five=5,thirtytwo=32;
    cout<< "Enter temperature in Fahrenheit: ";
    cin>> fahrenheit;
    __asm{
        mov     ax, fahrenheit;
        sub     ax, thirtytwo;
        imul    five;
        idiv    nine;
        mov     celcius,ax;
    }
    cout<<fahrenheit<<"F is º"<< celcius<< "C ;
    return 0;
}
