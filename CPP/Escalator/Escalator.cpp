#include <iostream>
using namespace std;

class Stack
{
    int *data;
    int topIndex;
    int capacity;

public:
    Stack(int cap)
    {
        capacity = cap;
        data = new int[capacity];
        topIndex = -1;
    }

    void push(int val)
    {
        if (isFull())
        {
            cout << "Stack Overflow! Cannot push " << val << "." << endl;
        }
        else
        {
            data[++topIndex] = val;
            cout << val << " pushed successfully." << endl;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow! Nothing to pop." << endl;
        }
        else
        {
            cout << data[topIndex--] << " popped successfully." << endl;
        }
    }

    void topElement() const
    {
        if (isEmpty())
        {
            cout << "Stack is empty. No top element." << endl;
        }
        else
        {
            cout << "Current top element: " << data[topIndex] << endl;
        }
    }

    bool isEmpty() const
    {
        return topIndex == -1;
    }

    bool isFull() const
    {
        return topIndex == capacity - 1;
    }

    ~Stack()
    {
        delete[] data;
    }
};

int main()
{
    int size;
    cout << "Enter stack size: ";
    cin >> size;

    Stack s(size);
    int choice, value;

    cout << "\n--- Stack Program ---" << endl;

    do
    {
        cout << "\n1. Push an element" << endl;
        cout << "2. Pop an element" << endl;
        cout << "3. Show Top element" << endl;
        cout << "4. Check if Empty" << endl;
        cout << "5. Check if Full" << endl;
        cout << "6. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.topElement();
            break;
        case 4:
            cout << (s.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
            break;
        case 5:
            cout << (s.isFull() ? " Stack is full." : "Stack is not full.") << endl;
            break;
        case 6:
            cout << "Exiting program... Goodbye!" << endl;
            break;
        default:
            cout << "Invalid option! Try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
