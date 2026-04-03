#include <iostream>
using namespace std;

class Box{
    public:
        int data;
        Box* next;
};

void Insert_Start(Box *&Head , int first){
    Box *newnode = new Box;
    newnode->data = first;
    newnode->next = Head;
    Head = newnode;
}

void Insert_End(Box *&Head, int last){
    Box *newnode = new Box;
    newnode->data = last;
    newnode->next = NULL;
    
    if(Head == NULL){
        Head = newnode;
        return;
    }
    
    Box *tail = Head;
    while (tail->next != NULL){
        tail = tail->next;
    }
    tail->next = newnode;
}

void Insert_At_Position(Box *&Head, int pos, int val){
    Box* newnodedata = new Box;
    newnodedata->data = val;
    newnodedata->next = NULL;
    
    if(pos == 1){
        newnodedata->next = Head;
        Head = newnodedata;
        return;
    }
    
    Box* temp = Head;
    for(int i = 1; i < pos-1 && temp != NULL; i++){
        temp = temp->next;
    }
    
    if(temp == NULL){
        cout << "Position out of range! Adding at end." << endl;
        Insert_End(Head, val);
        delete newnodedata;
        return;
    }
    
    newnodedata->next = temp->next;
    temp->next = newnodedata;   
}

void Update_At_Position(Box *&Head,int pos,int val){
    if(pos <= 0){
        cout << "Invalid position!" << endl;
        return;
    }

    Box *temp = Head;
    for(int i=1; i<pos && temp!=NULL; i++){
        temp = temp->next;
    }

    if(temp == NULL){
        cout << "Position out of range!" << endl;
        return;
    }

    temp->data = val;
    cout << "Updated successfully!" << endl;
}

void Delete_First(Box *&Head){
    if(Head == NULL){
        cout << "List is empty!" << endl;
        return;
    }

    Box *deltmp = Head;
    Head = Head->next;
    delete deltmp;
}

void Delete_Last(Box *&Head){
    if(Head == NULL){
        cout << "List is empty!" << endl;
        return;
    }

    if(Head->next == NULL){
        delete Head;
        Head = NULL;
        return;
    }

    Box *secondLast = Head;
    while (secondLast->next->next != NULL){
        secondLast = secondLast->next;
    }

    delete secondLast->next;
    secondLast->next = NULL;
}

void Delete_Any_Position(Box *&Head, int pos){
    if (Head == NULL){
        cout << "List is empty!" << endl;
        return;
    }

    if (pos <= 0){
        cout << "Invalid position!" << endl;
        return;
    }

    if (pos == 1){
        Delete_First(Head);
        return;
    }

    Box *current = Head;
    Box *prev = NULL;

    for (int i = 1; i < pos; i++){
        prev = current;
        current = current->next;

        if (current == NULL){
            cout << "Position out of range!" << endl;
            return;
        }
    }
    prev->next = current->next;
    delete current;
}


void Display(Box *Head){
    while (Head != NULL)
    {
       cout << Head->data << " ";
       Head = Head->next;
    }
}

int main(){
    Box *Head = NULL;
    int choice,data,position;
    
    do{
        cout << endl << "1. Insert" << endl;
        cout << "2. Delete Top (Pop)" << endl;
        cout << "3. Delete at Position" << endl;
        cout << "4. Update at Position" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;
        cout << endl << "Enter  Choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter value: ";
                cin >> data;
                Insert_Start(Head,data);
                cout << endl;
            break;

            case 2:
                cout << "Enter value: ";
                cin >> data;
                Insert_End(Head,data);
                cout << endl;
            break;

            case 3:
                cout << "Enter position: ";
                cin >> position;
                cout << "Enter value: ";
                cin >> data;
                Insert_At_Position(Head, position, data);
                cout << endl;
            break;

            case 4:
                cout << "Enter position: ";
                cin >> position;
                cout << "Enter new value: ";
                cin >> data;
                Update_At_Position(Head, position, data);
            break;

            case 5:
                Delete_First(Head);
            break;

            case 6:
                Delete_Last(Head);
            break;

            case 7:
                cout << "Enter position: ";
                cin >> position;
                Delete_Any_Position(Head, position);
            break;

            case 8:
                Display(Head);
            break;

            case 9:
                cout << "Exiting..." << endl;
            break;

            default:
                cout << "Invalid choice!" << endl;

        }
    }while(choice != 9);
}