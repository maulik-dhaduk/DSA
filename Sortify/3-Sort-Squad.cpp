#include <iostream>
using namespace std;

int main()
{

    int size;
    cout << "Enter Array size: ";
    cin >> size;

    int arr[size], tmp;

    for (int i = 0; i < size; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> arr[i];
    }

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }

    cout << "Ascending Order: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    cout << endl << "Descending Order: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}