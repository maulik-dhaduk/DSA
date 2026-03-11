#include <iostream>
using namespace std;

int main() {

    int size;
    cout << "Enter Array size: ";
    cin >> size;

    int arr[size];
    int Positive_Numbers = 0;
    int Negative_Numbers = 0;

    for (int i = 0; i < size; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> arr[i];

        if(arr[i] > 0){
            Positive_Numbers++;
        }else{
            Negative_Numbers++;
        }
    }
    
    cout << "Positive numbers: " << Positive_Numbers <<endl;
    cout << "Negative numbers: " << Negative_Numbers <<endl;
}