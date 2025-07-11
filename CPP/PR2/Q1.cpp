#include<iostream>
using namespace std;

int main(){

    char ch='A';
    do
    {
        cout << ch << " ";
        ch+=4;
    } while (ch<='Z');
    
}