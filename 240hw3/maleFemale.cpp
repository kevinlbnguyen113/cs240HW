
#include <iostream>
#include <string>
using namespace std;
string name;
int age;
char gender;
void getInfo(){
    cout<<"Enter your name:";
    cin>> name;
    cout<<name<<", how old are you?";
    cin>>age;
    cout<< name <<", what s your gender(m/f)?";
    cin >> gender;
}
void displayFemale(){
    cout<<"Hi "<<name<<", you are a female teenager\n";
}
void displayNotFemale(){
    cout<<"Hi "<<name<<", you are not a female teenager\n";
}
void (*displayNotFemalePointer)()= displayNotFemale;
void (*displayFemalePointer)()= displayFemale;
void (*infoPointer)()=getInfo;
void asmProgram(){
    asm{
        call    infoPointer;
        mov     eax, age;
        cmp     eax,13;
        jg      check19;
    notTeen:
        call    displayNotFemalePointer;
        jmp     cont;
    check19:
        mov     eax,age;
        cmp     eax,19;
        jl      checkFemale;
    over19Teen:
        jmp     notTeen;
    checkFemale:
        mov     al,gender;
        cmp     al,'f';
        jne     checkUpperFemale;
    iAmFemale:
        call    displayFemalePointer;
        jmp     cont;
    checkUpperFemale:
        mov     al, gender;
        cmp     al, 'F';
        je     iAmFemale;
    notFemale:
        jmp     notTeen;
        
    cont:
    }
}
int main(){
    asmProgram();
    asmProgram();
    
    return 0;
}
