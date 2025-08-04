#include <iostream>
using namespace std;
int main()
{

    int size;

    cout << "Enter the size of array : ";
    cin >> size;

    int arr[size];

    cout << "Enter arrays elements : " << endl;
    for (int i = 0; i <= size - 1; i++)
    {
        cout << "arr[" << i << "] : ";
        cin >> arr[i];
    }
    cout << endl
         << "your negative elements are : ";

    for (int i = 0; i <= size - 1; i++)
    {
        if (arr[i] < 0)
        {
            cout << arr[i] << " ";
        }
    }

    return 0;
}