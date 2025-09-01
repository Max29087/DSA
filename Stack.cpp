#include <iostream>
using namespace std;
void manu();
int StackPush(int data[], int top, int v);
int StackPop(int data[], int top);
int main()
{
    int n, top = 0;
    cout << "Enter stack size:";
    cin >> n;
    int data[n];
    int choise, value;
    while (1)
    {
        manu();
        cout << "Enter Your Choice: ";
        cin >> choise;
        if (choise == 1)
        {
            if (top < n)
            {
                cout << "Enter a value: ";
                cin >> value;
                top = StackPush(data, top, value);
                cout << "Value added successfully." << endl;
                cout << endl;
            }
        }
        else if (ch == 2)
        {
            if (top > 0)
            {
                cout << StackPop(data, top) << " poped." << endl;
                top--;
            }
            else
            {
                cout << "Stack is empty." << endl;
            }
        }
        else if (ch == 3)
        {
            if (top == 0)
            {
                cout << "Stack is empty!" << endl;
                cout << endl;
            }
            else
            {
                cout << "Top element: " << data[top - 1] << endl;
                cout << endl;
            }
        }
        else if (ch == 4)
        {
            cout << "Size: " << top << endl;
            cout << endl;
        }
        else if (ch == 5)
        {
            return 0;
        }

        else
        {
            cout << "Enter valid input: ";
            cin >> ch;
        }
    }

    return 0;
}
void manu()
{
    cout << "1.Push" << endl;
    cout << "2.Pop" << endl;
    cout << "3.Print top element" << endl;
    cout << "4.Size" << endl;

    cout << "5.Exit" << endl;
}

int StackPush(int data[], int top, int v)
{
    data[top++] = v;
    return top;
}
int StackPop(int data[], int top)
{

    return data[top];
}