#include <iostream>
using namespace std;

int main()
{

    int num = 0, count = 0;

    cout << "Enter any number :- ";
    cin >> num;

    if (num == 0)
    {
        count = 1;
    }
    else
    {

        for (int i = num; num != 0; i++)
        {
            num = num / 10;
            count++;
        }
    }
    cout << "total numbers of digits :- " << count;
}