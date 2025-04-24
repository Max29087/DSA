#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    int n;
    cout << "Enter array Size:";
    cin >> n;
    int arr[n];
    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10; // Initialize arry with random number;
    }

    cout << "UnSorted Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int SmallestIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[SmallestIndex])
            {
                SmallestIndex = j;
            }
        }
        swap(arr[i], arr[SmallestIndex]);
    }

    cout << "Sorted Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}