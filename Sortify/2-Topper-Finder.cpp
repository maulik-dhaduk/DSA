#include <iostream>
using namespace std;

int main() {

    int size;
    cout << "Enter Array size: ";
    cin >> size;

    int arr[size];
    int max = -1,secondmax = -1;

    for (int i = 0; i < size; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> arr[i];

        if(max < arr[i]){
            max = arr[i];
        }
    }

    for (int i = 0; i < size; i++)
    {
        if(arr[i] != max && secondmax < arr[i]){
            secondmax = arr[i];
        }
    }
    
    if (max == -1) {
        cout << "There is no largest element." <<endl;
    } else {
        cout << "The largest element is: "<< max <<endl;
    }

    if (secondmax == -1) {
        cout << "There is no second largest element." <<endl;
    } else {
        cout << "The second largest element is: "<< secondmax;
    }
    
}