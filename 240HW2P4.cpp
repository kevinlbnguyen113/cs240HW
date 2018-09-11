//
//  main.cpp
//  240HWp4
//
//  Created by Tram-Anh Tran on 9/9/18.
//  Copyright © 2018 loc. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(){
    int digits,sum=0;
    int ten=10,hundred=100;
    int temp1,temp2,temp3,temp4,temp5,temp6;
    cout<<"Enter a 3 digit integer number: ";
    cin>>digits;
    __asm{
        mov     eax, digits;
        cdq
        idiv    hundred;
        mov     temp1,eax;
        mov     eax,temp1;
        mul     hundred;
        mov     temp2,eax;
        mov     eax, digits;
        sub     eax,temp2;
        mov     temp3,eax;
        mov     eax, temp3;
        idiv    ten;
        mov     temp4,eax;
        mov     eax,temp4;
        mul     ten;
        mov     temp5, eax;
        mov     eax,temp3;
        sub     eax,temp5;
        mov     temp6,eax;
        mov     eax,temp1;
        add     eax,temp4;
        add     eax,temp6;
        mov     sum,eax;
     
    }
    cout<<"The Total of digits in "<<digits<<" is "<< sum<<endl;

    return 0;
}
