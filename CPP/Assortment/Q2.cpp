#include <iostream>
using namespace std;
int main()
{

    int r, c;

    cout << "Enter the arrays row size : ";
    cin >> r;
    cout << "Enter the arrays column size : ";
    cin >> c;

    int array[r][c];
    cout << "Enter arrays element : " << endl;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << "array[" << i << "][" << j << "] : ";
            cin >> array[i][j];
        }
    }

    int LargestElement = array[0][0];

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (array[i][j] > LargestElement)
            {
                LargestElement = array[i][j];
            }
        }
    }
    cout << "\nThe largest Element is : " << LargestElement;
    ;
    return 0;
}