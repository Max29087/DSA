#include <iostream>
using namespace std;

int Linear_search(int array[], int SearchNumber)
{
    for (int i = 0; i < 10; i++)
    {
        if (array[i] == SearchNumber)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int array[10];

    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        array[i] = rand() % 100;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << endl;
    }

    int search_Number;
    cout << "Enter A Number: ";
    cin >> search_Number;

    int index = Linear_search(array, search_Number);
    if (index < 0)
    {
        cout << "\n\nNot Found\n\n";
    }
    else
    {
        cout << array[index] << endl;
    }

    return 0;
}