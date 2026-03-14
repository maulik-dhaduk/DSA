#include <iostream>
#include <vector>
using namespace std;

template <typename T>

class Memory_Calculate
{
private:
    T Id;
    string Name;

public:
    Memory_Calculate(T i, string n)
    {
        Id = i;
        Name = n;
    }

    void Display()
    {
        cout << endl
             << "Student ID: " << Id << endl;
        cout << "Student Name: " << Name << endl;
        cout << endl;
    }

    T getId()
    {
        return Id;
    }
};
int main()
{
    vector<Memory_Calculate<int>> Students;
    int choice, id;
    string name;

    do
    {
        cout << "===== Student Management System =====" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Remove Student by ID" << endl;
        cout << "4. Search Student by ID" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                cout << "Enter Student Id:";
                cin >> id;

                cout << "Enter Student Name:";
                cin >> name;

                cout << endl;

                int exist = 0;

                for (int i = 0; i < Students.size(); i++)
                {
                    if (id == Students[i].getId())
                    {
                        exist = 1;
                        break;
                    }
                }
                if (exist == 0)
                {
                    Students.push_back(Memory_Calculate<int>(id, name));
                    cout << "Student Added Successfully" << endl
                            << endl;
                }
                else
                {
                    cout << "Student ID already exists." << endl
                            << endl;
                }
                break;
            }

            case 2:
                if (Students.empty())
                {
                    cout << "No Students Found\n";
                }
                else
                {
                    for (int i = 0; i < Students.size(); i++)
                    {
                        Students[i].Display();
                    }
                    cout << endl;
                }
                break;

            case 3:
            {
                cout << "Enter ID to Remove: ";
                cin >> id;

                cout << endl;

                int check = 0;
                for (int i = 0; i < Students.size(); i++)
                {
                    if (id == Students[i].getId())
                    {
                        Students.erase(Students.begin() + i);
                        cout << "Student Removed Successfully" << endl << endl;
                        check = 1;
                        break;
                    }
                }

                if (check == 0)
                {
                    cout << "Student Not Found" << endl << endl;
                }
                break;
            }

            case 4:
            {
                cout << "Enter ID to Search: ";
                cin >> id;

                cout << endl;

                int check = 0;
                for (int i = 0; i < Students.size(); i++)
                {
                    if (id == Students[i].getId())
                    {
                        cout << "Student Found" << endl;
                        Students[i].Display();
                        check = 1;
                        break;
                    }
                }

                if (check == 0)
                {
                    cout << "Student Not Found" << endl << endl;
                }
                break;
            }

            case 5:
                cout << endl << "Exiting Program...";
                break;
            default:
                cout << endl << "Invalid Choice" << endl;
                break;
        }
    } while (choice != 5);
}