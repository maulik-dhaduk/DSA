#include <iostream>
#include <stack>
using namespace std;

void Display(stack<int> s){
    if(s.empty()){
        cout << "Stack is empty!" << endl;
        return;
    }

    cout << "Stack elements : ";
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

void UpdateAtPosition(stack<int> &s, int pos, int val){
    int n = s.size();
    if(pos <= 0 || pos > n){
        cout << "Invalid position!" << endl;
        return;
    }

    stack<int> temp;
    for(int i = 1; i < pos; i++){ 
        temp.push(s.top());
        s.pop();
    }

    s.pop();
    s.push(val);

    while(!temp.empty()){
        s.push(temp.top());
        temp.pop();
    }

    cout << "Updated successfully at position" << endl;
}

int main(){
    stack<int> data;
    int choice, element, position;

    do{
        cout << endl << "1. Add" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Update" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice){

            case 1:
                cout << "Enter value: ";
                cin >> element;
                data.push(element);
            break;

            case 2:
                if(data.empty()){
                    cout << "Stack Underflow!" << endl;
                } else {
                    cout << "Deleted: " << data.top() << endl;
                    data.pop();
                }
            break;

             case 3:
                if(data.empty()){
                    cout << "Stack is empty!" << endl;
                } else {
                    cout << "Enter position to update : ";
                    cin >> position;
                    cout << "Enter new value: ";
                    cin >> element;
                    UpdateAtPosition(data, position, element);
                }
            break;

            case 4:
                Display(data);
            break;

            case 5:
                cout << "Exiting..." << endl;
            break;

            default:
                cout << "Invalid choice!" << endl;
        }

    }while(choice != 5);
}