#include <iostream>
using namespace std;
int main()
{
    // int n;
    // cout <<"enter the value of a : ";
    // cin >> n;

    // if (n %2==0)
    // {
    //     cout<<"the number is even"<< endl;
    // }
    // else{
    //     cout<<"the number is odd\n";
    // // }
    // char ch;

    // cout << "Enter the ch\n";
    // cin >> ch;

    // if (ch >= 'a' && ch <= 'z')
    // {
    //     cout << "lowercase";
    // }
    // else
    // {
    //     cout << "uppercase";
    // }
    // return 0;
    // int count = 1;

    // while(count <=5){
    //     cout<<count << " ";
    //     count++;
    // }

    // for(count <1; count<=5; count++){
    //     cout<<count << "  ";
    // }

    // int n,sum=0;

    // cout << "enter the value of n ";
    // cin >> n;

    // for (int i = 1; i <=n; i++)
    // {
    //     sum+=i;
    // }
    // cout << "The sum is : " << sum;

    // int n, sum = 0, i = 0;

    // cout << "enter the value of n : ";
    // cin >> n;

    // cout << "the odd numbers are : " ;
    // for (i = 1; i <= n; i++)
    // {
    //     if (i % 2 != 0)
    //     {
    //         sum += i;
    //         cout << i << "  ";
    //     }
    // }

    // cout<<endl << "the sum of odd number is : " << sum;

    // int n;
    // bool isPrime = true;

    // cout << "enter the value of n : ";
    // cin >> n;

    // for (int i = 2; i < n; i++)
    // {
    //     if (n % i == 0)
    //     {
    //         isPrime = false;
    //         break;
    //     }
    // }

    // if (isPrime == true)
    // {
    //     cout << "prime\n";
    // }
    // else
    // {
    //     cout << "non-prime";
//     // }

//     int i, sum = 0, n;

//     cout << "Enter the value of n : ";
//     cin >> n;

//     cout << "the divisbile numbers are : ";
//     for (i = 1; i <= n; i++)
//     {
//         if (i % 3 == 0)
//         {
//             cout << i << " ";
//             sum += i;
//         }
//     }
//     cout << endl << "sum of all numbers from 1 to n which are divisible by 3 is :  " << sum;

    int n,fact=1;

    cout << "Enter the value of n : ";
    cin >> n;
    for (int i = 1; i <=n ; i++)
    {
        fact = fact * i;
    }
    
    cout << "the factorial of "<< n << "is : " << fact;

    return 0;
}