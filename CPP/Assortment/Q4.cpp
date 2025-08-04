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

    int rowNum, rowSum = 0, colNum, colSum = 0;

    cout << "\nEnter row number : ";
    cin >> rowNum;

    if (rowNum >= 0 && rowNum < r)
    {
        cout << "Elements of row " << rowNum << " : ";
        for (int j = 0; j < c; j++)
        {
            cout << array[rowNum][j];
            rowSum += array[rowNum][j];
            if (j < c - 1)
                cout << ", ";
        }
        cout << "\nThe sum of a row " << rowNum << " : " << rowSum << endl;
    }

    cout << "\nEnter column number : ";
    cin >> colNum;

    if (colNum >= 0 && colNum < c)
    {
        cout << "Elements of row " << colNum << " : ";
        for (int i = 0; i < r; i++)
        {
            cout << array[colNum][i];
            colSum += array[colNum][i];
            if (i < r - 1)
                cout << ", ";
        }
        cout << "\nThe sum of a row " << colNum << " : " << colSum << endl;
    }
}