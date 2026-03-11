#include <iostream>
using namespace std;

int main() {

    int size;
    cout << "Enter Array size: ";
    cin >> size;

    int arr[size],even[200],e_index=0,odd[200],o_index=0,tmp;

    for (int i = 0; i < size; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> arr[i];

        if(arr[i] %2 == 0){
            even[e_index] = arr[i];
            e_index++;
        }else{
            odd[o_index] = arr[i];
            o_index++;
        }
    }

    for (int i = 0; i < e_index - 1; i++)
    {
        for (int j = 0; j < e_index - i - 1; j++)
        {
            if (even[j] > even[j + 1])
            {
                tmp = even[j];
                even[j] = even[j + 1];
                even[j + 1] = tmp;
            }
        }
    }

    for (int i = 0; i < o_index - 1; i++)
    {
        for (int j = 0; j < o_index - i - 1; j++)
        {
            if (odd[j] < odd[j + 1])
            {
                tmp = odd[j];
                odd[j] = odd[j + 1];
                odd[j + 1] = tmp;
            }
        }
    }

    cout << "Result:" << endl;

    for(int i = 0; i < e_index; i++)
    {
        cout << even[i] << " ";
    }

    for(int i = 0; i < o_index; i++)
    {
        cout << odd[i] << " ";
    }
}