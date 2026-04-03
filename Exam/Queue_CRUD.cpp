#include<iostream>
#include<queue>
using namespace std;

void Display(queue<int> q) {
    if(q.empty()){
        cout << "Queue is empty!" << endl;
        return;
    }

    cout << "Queue elements : ";
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}


void UpdateAtPosition(queue<int> &q, int pos, int val){
    int n = q.size();
    if(pos <= 0 || pos > n){
        cout << "Invalid position!" << endl;
        return;
    }

    queue<int> temp;
    for(int i = 1; i <= n; i++){
        
        int x = q.front();
        q.pop();

        if(i == pos){
            x = val;
        }

        temp.push(x);
    }

    q = temp;
    cout << "Updated successfully at position"<< endl;
}

void DeleteFront(queue<int> &q){
    if(q.empty()){
        cout << "Queue Underflow!" << endl;
    } else {
        cout << "Deleted: " << q.front() << endl;
        q.pop();
    }
}

int main(){
    queue<int> q;
    int choice, element, position;

    do{
        cout << endl << "1. Add" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Update at Position" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> element;
                q.push(element);
            break;

            case 2:
                DeleteFront(q);
            break;

            case 3:
                if(q.empty()){
                    cout << "Queue is empty!" << endl;
                } else {
                    cout << "Enter position to update: ";
                    cin >> position;
                    cout << "Enter new value: ";
                    cin >> element;
                    UpdateAtPosition(q, position, element);
                }
            break;

            case 4:
                Display(q);
            break;

            case 5:
                cout << "Exiting..." << endl;
            break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while(choice != 5);
}