#include <iostream>
using namespace std;

int main()
{
    int size;

    cout << "Enter Array size: ";
    cin >> size;

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> arr[i];
    }

    int count = 0;

    cout << "Unique Elements: ";

    for (int i = 0; i < size; i++)
    {
        int check = 0;

        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                check = 1;
                break;
            }
        }

        if (check == 0)
        {
            arr[count] = arr[i];
            cout << arr[count] << " ";
            count++;
        }
    }

    return 0;
}