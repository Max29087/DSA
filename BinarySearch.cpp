#include <iostream>
using namespace std;
int BinarySearch(int array[], int target);
int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 10, 14, 16};
    int target;
    cout << "Enter Your Target: ";
    cin >> target;
    int index = BinarySearch(array, target);
    if (index >= 0)
    {
        cout << "Index: " << index << endl;
        cout << "Value: " << array[index] << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    return 0;
}
int BinarySearch(int array[], int target)
{
    int start = 0;
    int end = 9;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (target < array[mid])
        {
            end = mid - 1;
        }
        else if (target > array[mid])
        {
            start = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}