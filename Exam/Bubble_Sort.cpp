#include <iostream>
using namespace std;

void Sort_Array(int arr[],int size){
    for (int i = 0; i < size-1; i++){
        for (int j = 0; j < size-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void Print_Array(int arr[],int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    
    int size;

    cout << "Enter array size: ";
    cin >> size;

    int arr[size];
    
    for (int i = 0; i < size; i++){
        cout << "a[" << i << "] = ";
        cin >> arr[i];
    }
    
    cout << endl << "Original array: ";
    Print_Array(arr, size);

    Sort_Array(arr, size);
    
    cout << "\nSorted array: ";
    Print_Array(arr, size);
    
}