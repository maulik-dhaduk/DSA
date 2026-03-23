#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int size;
    int Index;

public:

    Stack(int s) {
        size = s;
        arr = new int[size];
        Index = 0;
    }

    ~Stack() {
        delete[] arr;
    }

    virtual void push(int value) {
        if (Index >= size) {
            cout << "Stack Overflow!" << endl;
        } else {
            arr[Index] = value;
            cout << value << " pushed into stack at position " << Index << endl;
            Index++;
        }
    }


    virtual void pop() {
        if (Index == 0) {
            cout << "Stack Underflow!" << endl;
        } else {
            Index--;
            cout << arr[Index] << " popped from stack." << endl;
        }
    }

    
    virtual void top() {
        if (Index == 0) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Top element: " << arr[Index - 1] << endl;
        }
    }

   
    bool isEmpty() {
        return Index == 0;
    }

    bool isFull() {
        return Index == size;
    }
};

class AdvancedStack : public Stack {
public:
    AdvancedStack(int s) : Stack(s) {
        
    }

    void push(int value) override {
        cout << "[AdvancedStack] ";
        Stack::push(value);
    }

    void pop() override {
        cout << "[AdvancedStack] ";
        Stack::pop();
    }

    void top() override {
        cout << "[AdvancedStack] ";
        Stack::top();
    }
};
int main() {

    int size;
    cout << "Enter stack size: ";
    cin >> size;

    AdvancedStack s(size);
    int choice, value;

    do {
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Check Empty" << endl;
        cout << "5. Check Full" << endl;
        cout << "0. Exit" << endl;
        
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s.push(value);
                break;
                
            case 2:
                s.pop();
                break;
                
            case 3:
                s.top();
                break;
                
            case 4:
                if(s.isEmpty()){
                    cout << "Stack is empty." << endl;
                }else{
                    cout << "Stack is not empty." << endl;
                }
                break;
                
            case 5:
                if(s.isFull()){
                    cout << "Stack is full." << endl;
                }else{
                    cout << "Stack is not full." << endl;
                }
                break;
                
            case 0:
                cout << "Exiting..." << endl;
                break;
                
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}