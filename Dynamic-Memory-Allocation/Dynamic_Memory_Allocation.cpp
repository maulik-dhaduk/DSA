#include <iostream>
using namespace std;

class Dynamic_Memory_Allocation
{
public:
    int data;
    Dynamic_Memory_Allocation *nextnode;
    Dynamic_Memory_Allocation *Head;

    Dynamic_Memory_Allocation()
    {
        Head = NULL;
    }

    void append(int val)
    {
        Dynamic_Memory_Allocation *Newnode = new Dynamic_Memory_Allocation();
        Newnode->data = val;
        Newnode->nextnode = NULL;

        if (Head == NULL)
        {
            Head = Newnode;
            return;
        }

        Dynamic_Memory_Allocation *temp = Head;
        while (temp->nextnode != NULL)
        {
            temp = temp->nextnode;
        }
        temp->nextnode = Newnode;
    }

    void display()
    {
        Dynamic_Memory_Allocation *temp = Head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->nextnode;
        }
        cout << endl;
    }

    void Insert_At_Beginning(int val)
    {
        Dynamic_Memory_Allocation *Newnode = new Dynamic_Memory_Allocation();
        Newnode->data = val;
        Newnode->nextnode = Head;
        Head = Newnode;
    }

    void Search(int val)
    {
        Dynamic_Memory_Allocation *temp = Head;
        int position = 1;
        while (temp != NULL)
        {
            if (temp->data == val)
            {
                cout << "Element found at position " << position << endl;
                return;
            }
            temp = temp->nextnode;
            position++;
        }
        cout << "Element not found" << endl;
    }

    void Deletion(int val)
    {
        Dynamic_Memory_Allocation *temp = Head;
        Dynamic_Memory_Allocation *prev = NULL;

        if (temp != NULL && temp->data == val)
        {
            Head = temp->nextnode;
            delete temp;

            cout << "Node deleted" << endl;
            return;
        }

        while (temp != NULL && temp->data != val)
        {
            prev = temp;
            temp = temp->nextnode;
        }

        if (temp == NULL)
        {
            cout << "Element not found" << endl;
            return;
        }

        prev->nextnode = temp->nextnode;
        delete temp;
        cout << "Node deleted" << endl;
    }

    void reverse()
    {
        Dynamic_Memory_Allocation *prev = NULL;
        Dynamic_Memory_Allocation *curr = Head;
        Dynamic_Memory_Allocation *next = NULL;

        while (curr != NULL)
        {
            next = curr->nextnode;
            curr->nextnode = prev;
            prev = curr;
            curr = next;
        }
        Head = prev;
    }
};
int main()
{

    Dynamic_Memory_Allocation dma;

    dma.append(10);
    dma.append(20);
    dma.append(30);

    cout << "Initial List: ";
    dma.display();

    dma.Insert_At_Beginning(45);
    cout << "After Insert at Beginning: ";
    dma.display();

    dma.Search(30);

    dma.Deletion(20);
    cout << "After Deletion: ";
    dma.display();

    dma.reverse();
    cout << "After Reversing: ";
    dma.display();
}