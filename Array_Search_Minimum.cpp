#include <iostream>
using namespace std;
int main()
{
    int array[10];
    srand(time(NULL)); // Random Number Genarate
    for (int i = 0; i < 10; i++)
    {
        array[i] = rand() % 100; // Store random number on the array [The numbers lessthen 100];
    }
    // print arrays all data ;
    cout << "\nArray data\n\n";
    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << "\t";
    }
    cout << "\n\n";
    int minimumNumber = INT_MAX;
    for (int i = 0; i < 10; i++)
    {
        minimumNumber = min(array[i], minimumNumber);
    }
    cout << "Minimum Number: " << minimumNumber << "\n\n";
    return 0;
}