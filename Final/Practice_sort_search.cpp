#include <iostream>
using namespace std;
int n;
void menu();
void printData(int arr[]);
void BubbleSort(int arr[]);
void selectionSort(int arr[]);
void insertSort(int arr[]);
void binarySearch(int arr[]);
int main()
{
    cout << "Enter Array Size: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "data[" << i << "]: ";
        cin >> arr[i];
    }
    menu();
    int choise;
    cin >> choise;
    while (choise != 0)
    {
        if (choise == 1)
        {
            printData(arr);
        }
        else if (choise == 2)
        {
            BubbleSort(arr);
            printData(arr);
        }
        else if (choise == 3)
        {
            selectionSort(arr);
            printData(arr);
        }
        else if (choise == 4)
        {
            insertSort(arr);
            printData(arr);
        }
        else if (choise == 5)
        {
            binarySearch(arr);
        }
        menu();
        cin >> choise;
    }
}
void menu()
{
    cout << "1.Print All data." << endl;
    cout << "2.Bubble Sort" << endl;
    cout << "3.Selection Sort" << endl;
    cout << "4.Insert Sort" << endl;
    cout << "5.Binary Search" << endl;
    cout << "0.Exit" << endl;
    cout << "Enter Your Choise: ";
}
void printData(int arr[])
{
    cout << "All Data: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
void BubbleSort(int arr[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(int arr[])
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[minIndex] > arr[j])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
void insertSort(int arr[])
{
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int previous = i - 1;
        while (previous >= 0 && arr[previous] > current)
        {
            arr[previous + 1] = arr[previous];
            previous--;
        }
        arr[previous + 1] = current;
    }
}
void binarySearch(int arr[])
{
    selectionSort(arr);
    int low = 0;
    int high = n - 1;
    int key;
    cout << "Enter Key: ";
    cin >> key;
    while (high >= low)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            cout << "Found." << endl;
            return;
        }
        else if (arr[mid] > key)
        {
            high = mid - 1;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
    }
    cout << "Not Found!" << endl;
}