#include <iostream>
using namespace std;
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void SelectionSort(int arr[], int n)
{

    for (int i = 0; i < n-1; i++)
    {
        int MinIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[MinIndex])
            {
                MinIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[MinIndex];
        arr[MinIndex] = temp;
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[100], R[100];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int n, int key)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int choice, key;
    do
    {
        cout << "1. Selection Sort\n";
        cout << "2. Merge Sort\n";
        cout << "3. Linear Search\n";
        cout << "4. Binary Search\n";
        cout << "5. Print Array\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            SelectionSort(arr, n);
            cout << "Array after Selection Sort: ";
            printArray(arr, n);
            break;

        case 2:
            mergeSort(arr, 0, n - 1);
            cout << "Array after Merge Sort: ";
            printArray(arr, n);
            break;

        case 3:
            cout << "Enter element to search: ";
            cin >> key;
            {
                int index = linearSearch(arr, n, key);
                if (index != -1)
                    cout << "Element found at index " << index << endl;
                else
                    cout << "Element not found.\n";
            }
            break;

        case 4:
            cout << "Enter element to search: ";
            cin >> key;
            {
                int index = binarySearch(arr, n, key);
                if (index != -1)
                    cout << "Element found at index " << index << endl;
                else
                    cout << "Element not found.\n";
            }
            break;

        case 5:
            cout << "Current Array: ";
            printArray(arr, n);
            break;

        case 0:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}