#include <iostream>
using namespace std;

void Sort_Array(int arr[],int size){
    for (int i = 0; i < size; i++){
        for (int j = i+1; j < size; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void Print_Array(int arr[],int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}

void Search_element(int arr[], int size, int ele){
    int low = 0, high = size-1, mid, found=0;

    while (low <= high)
    {
        mid = (low+high) / 2;

        if(arr[mid] == ele){
            cout << "Element found at index " << mid;    
            found = 1;
            break;
        } else if(ele < arr[mid]){
            high = mid - 1;
        } else{
            low = mid + 1;
        }
    }

    if(found == 0){
        cout << "Element not found";
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
    
    cout << endl << "Sorted array: ";
    Print_Array(arr, size);
    
    int element;

    cout << endl << "Enter element to search: ";
    cin >> element;
    
    Search_element(arr,size,element);
}