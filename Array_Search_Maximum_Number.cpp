#include <iostream>
using namespace std;
int main()
{
    int array[10];
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        array[i] = rand() % 100;
    }
    cout << "\nArray Value\n\n";
    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << "\t";
    }
    int Maximum = INT_MIN;
    for (int i = 0; i < 10; i++)
    {
        Maximum = max(array[i], Maximum);
    }
    cout << "\n\nMaximum Number: " << Maximum << "\n\n";
    return 0;
}