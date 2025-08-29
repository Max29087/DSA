#include <iostream>
using namespace std;
void menu();
void printData(int data[], int n);
void bubbleSort(int data[], int n);
void selectionSort(int data[], int n);
void insertSort(int data[], int n);
int binarySearch(int data[], int n, int key);
int main()
{
    int n;
    cout << "Enter Array Size: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Data[" << i << "]: ";
        cin >> arr[i];
    }
    menu();
    int choice;
    cin >> choice;
    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            printData(arr, n);
            break;
        case 2:
            bubbleSort(arr, n);
            printData(arr, n);
            break;
        case 3:
            selectionSort(arr, n);
            printData(arr, n);
            break;
        case 4:
            insertSort(arr, n);
            printData(arr, n);
            break;
        case 5:
            int key;
            cout << "Enter key Value: ";
            cin >> key;
            int x = binarySearch(arr, n, key);
            break;
        default:
            break;
        }
        menu();
        cin >> choice;
    }
}

void printData(int data[], int n)
{
    cout << endl;
    cout << "All Data:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << data[i] << endl;
    }
    cout << endl;
}

void menu()
{
    cout << "0) Exit" << endl;
    cout << "1) Print List" << endl;
    cout << "2) Bubble Sort" << endl;
    cout << "3) Selection Sort" << endl;
    cout << "4) Insert Sort" << endl;
    cout << "5) Binary Search" << endl;
    cout << "Enter Your Choice: ";
}

void bubbleSort(int data[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (data[j] > data[j + 1])
            {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}
void selectionSort(int data[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (data[min_index] > data[j])
            {
                min_index = j;
            }
        }
        swap(data[i], data[min_index]);
    }
}
void insertSort(int data[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = data[i];
        int previous = i - 1;
        while (previous >= 0 && data[previous] > current)
        {
            data[previous + 1] = data[previous];
            previous--;
        }
        data[previous + 1] = current;
    }
}
int binarySearch(int data[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (key == data[mid])
        {
            return 1;
        }
        else if (key > data[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}