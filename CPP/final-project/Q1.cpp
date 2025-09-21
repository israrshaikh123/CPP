#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *head = NULL;

void insertAtEnd(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Node inserted with value " << value << endl;
}

void deleteNode(int value)
{
    if (head == NULL)
    {
        cout << "List is empty, nothing to delete!" << endl;
        return;
    }

    Node *temp = head;

    if (head->data == value)
    {
        head = head->next;
        delete temp;
        cout << "Node with value " << value << " deleted." << endl;
        return;
    }

    Node *prev = NULL;
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Value " << value << " not found in list!" << endl;
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Node with value " << value << " deleted." << endl;
}

void displayList()
{
    if (head == NULL)
    {
        cout << "Linked List is empty!" << endl;
        return;
    }
    Node *temp = head;
    cout << "Linked List: ";
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "0" << endl;
}

void linkedListMenu()
{
    int choice, value;
    do
    {
        cout << "1. Insert at End" << endl;
        cout << "2. Display List" << endl;
        cout << "3. Delete The Node" << endl;
        cout << "4. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            insertAtEnd(value);
            break;
        case 2:
            displayList();
            break;
        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            deleteNode(value);
            break;
        case 4:
            cout << "Returning to Main Menu..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 4);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void sortingMenu()
{
    int n, choice;
    cout << "\nEnter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    do
    {
        cout << "1. Merge Sort" << endl;
        cout << "2. Quick Sort" << endl;
        cout << "3. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            mergeSort(arr, 0, n - 1);
            cout << "Array after Merge Sort: ";
            printArray(arr, n);
            break;
        case 2:
            quickSort(arr, 0, n - 1);
            cout << "Array after Quick Sort: ";
            printArray(arr, n);
            break;
        case 3:
            cout << "Returning to Main Menu..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 3);
}

int binarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

void binarySearchMenu()
{
    int n, key;
    cout << "\nEnter size of array: ";
    cin >> n;
    int arr[n];

    cout << "Enter " << n << " elements (sorted order): ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    int result = binarySearch(arr, n, key);
    if (result != -1)
        cout << "Element " << key << " found at index " << result << endl;
    else
        cout << "Element not found in the array." << endl;
}

int main()
{
    int choice;

    do
    {
        cout << "1. Linked List Operation" << endl;
        cout << "2. Sorting (Merge Sort / Quick Sort)" << endl;
        cout << "3. Binary Search" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            linkedListMenu();
            break;
        case 2:
            sortingMenu();
            break;
        case 3:
            binarySearchMenu();
            break;
        case 4:
            cout << "Exiting programe..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }

    } while (choice != 4);

    return 0;
}
