#include<iostream>
using namespace std;

int main(){

    int num=0,lastDigit,FirsDigit;

    cout << "enter the number :- ";
    cin >> num;

    lastDigit = num % 10;

    cout << "The last digit of number is :-" << lastDigit;

    while (num >=10)
    {
        num = num/10;
    }

    FirsDigit = num;

    cout << "\nThe first digit of number is :-" << FirsDigit;
    
    cout <<"\n The sum of First and Last digit is :- "<< (FirsDigit+lastDigit);
    return 0;
    
}