#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Linkedlist
{
private:
    Node *head;
    int count;

public:
    Linkedlist()
    {
        head = NULL;
        count = 0;
    }

    ~Linkedlist()
    {
        Node *curr = head;
        while (curr != NULL)
        {
            Node *next = curr->next;
            delete curr;
            curr = next;
        }
    }

    void InsertAtBeginning(int data)
    {
        Node *NewNode = new Node(data);
        if (head == NULL)
        {
            head = NewNode;
            return;
        }
        else
        {
            NewNode->next = head;
            head = NewNode;
        }
    }
    void append(int data)
    {
        Node *new_node = new Node(data);
        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }
        count++;
        cout << "Node appended at end successfully." << endl;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void Search(int key)
    {
        Node *temp = head;
        int pos = 1;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                cout << "Element" << key << " Found at position" << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Element" << key << " not found in the list";
    }
    void delete_node(int key)
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *temp = head;
        Node *prev = NULL;

        if (temp->data == key)
        {
            head = temp->next;
            delete temp;
            count--;
            cout << "Node with value " << key << " deleted successfully." << endl;
            return;
        }

        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Node with value " << key << " not found." << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
        count--;
        cout << "Node with value " << key << " deleted successfully." << endl;
    }
    void reverse()
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
        cout << "Linked list is reversed successfully." << endl;
    }
};

int main()
{
    Linkedlist list;
    int choice, value;

    do
    {
        cout << "\n--- Linked List Menu ---" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Append at End" << endl;
        cout << "3. Display List" << endl;
        cout << "4. Search Element" << endl;
        cout << "5. Delete Node" << endl;
        cout << "6. Reverse List" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at beginning: ";
            cin >> value;
            list.InsertAtBeginning(value);
            break;

        case 2:
            cout << "Enter value to append at end: ";
            cin >> value;
            list.append(value);
            break;

        case 3:
            cout << "Linked List: ";
            list.display();
            break;

        case 4:
            cout << "Enter value to search: ";
            cin >> value;
            list.Search(value);
            break;

        case 5:
            cout << "Enter value to delete: ";
            cin >> value;
            list.delete_node(value);
            break;

        case 6:
            list.reverse();
            break;

        case 7:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 7);
}