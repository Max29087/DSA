#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
    int n;
    cout << "\nEnter array Size: ";
    cin >> n;
    int arr[n];
    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100 + 1; // Store random number between (1-100);
    }

    cout << "UnSorted Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    for (int i = 1; i < n; i++) // loop run (n-1) time;
    {
        int curr = arr[i];
        int prev = i - 1;
        while (prev >= 0 && arr[prev] > curr)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }

    cout << "Sorted Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}