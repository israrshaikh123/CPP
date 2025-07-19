#include <iostream>
using namespace std;

int main()
{
    int score;
    char ch;

    cout << "Enter the score : ";
    cin >> score;

    if (score <= 100)
    {
        ch = (score > 35 && score >= 90) ? 'A' :
             (score > 35 && score >= 80) ? 'B' :
             (score > 35 && score >= 70) ? 'C' :
             (score > 35 && score >= 50) ? 'D' :
             (score >= 35)               ? 'E' :
                                           'F';

        cout << "Your Grade is : " << ch << endl;

        switch (ch)
        {
        case 'A':
            cout << "Top Grade!";
            break;
        case 'B':
            cout << "Very Good!";
            break;
        case 'C':
            cout << "Good!";
            break;
        case 'D':
            cout << "Average!";
            break;
        case 'E':
            cout << "Just Passed!";
            break;
        case 'F':
            cout << "Fail!";
            break;
        }
    }
    else
    {
        cout << "Invalid score!" << endl;
    }

    return 0;
}
