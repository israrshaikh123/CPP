#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class T>
class MemoryCalculate
{
private:
    T id;
    string name;

public:
    MemoryCalculate(T id, string name)
    {
        this->id = id;
        this->name = name;
    }

    void display()
    {
        cout << "ID: " << id << " | Name: " << name << endl;
    }

    T getId()
    {
        return id;
    }
};
int main()
{
    vector<MemoryCalculate<int>> student;
    int choice;

    do
    {
        cout << "Student Management System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All Student" << endl;
        cout << "3. Remove Student By ID" << endl;
        cout << "4. Search Student By ID" << endl;
        cout << "0. For Exit" << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;

        if (choice == 1)
        {
            int id;
            string name;

            cout << "Enter Students ID : ";
            cin >> id;

            cout << "Enter Students Name : ";
            cin >> name;

            student.push_back(MemoryCalculate<int>(id, name));
            cout << "Student Added Successfully" << endl;
        }

        else if (choice == 2)
        {
            cout << "Students List " << endl;
            if (student.empty())
            {
                cout << "Students List is Empty";
            }
            else
            {
                for (int i = 0; i < student.size(); i++)
                {
                    student[i].display();
                }
            }
        }
        else if (choice == 3)
        {
            int id;
            cout << "Enter Student ID to Remove : ";
            cin >> id;
            bool found = false;
            for (int i = 0; i < student.size(); i++)
            {
                if (student[i].getId() == id)
                {
                    student.erase(student.begin() + i);
                    cout << "Student Removed Successfully." << endl;
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Student Not Found...." << endl;
            }
        }
        else if (choice == 4)
        {
            int id;
            cout << "Enter Student ID To Search : ";
            cin >> id;
            bool found = false;
            for (int i = 0; i < student.size(); i++)
            {
                if (student[i].getId() == id)
                {
                    student[i].display();
                    found = true;

                    break;
                }
            }

            if (!found)
            {
                cout << "Student Not Found...." << endl;
            }
        }
        else if (choice == 0)
        {
            cout << "Exiting Program......Byeeeee" << endl;
        }
        else
        {
            cout << "Invalid Choice.";
        }

    } while (choice != 0);
    return 0;
}
