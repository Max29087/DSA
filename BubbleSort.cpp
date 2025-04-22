#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    int n;
    cout << "Enter Array Size: ";
    cin >> n;
    int arr[n];
    srand(time(NULL)); // Unique random Number;

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10; // Initialize array with random number;
    }

    cout << "\nUnSorted Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl; // Print Unsort array data ;
    }

    // Bubble Sort;
    for (int i = 0; i < n - 1; i++)
    {
        bool isSwap = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }
        if (!isSwap) // array is already sorted;
        {
            break;
        }
    }

    // Print Sorted Array data ;
    cout << "\nSorted Array: " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}