#include <stdio.h>

int push(int data[], int stSize, int top);
int pop(int data[], int stSize, int top);
void stack_size(int top);
void top_element(int data[], int top);
void menu();

int main()
{
    int choice, qSize, front = 0, rear = 0;

    printf("Queue size: ");
    scanf("%d", &qSize);

    if (qSize <= 0)
    {
        printf("Invalid Queue size. Exiting.\n");
        return 1;
    }
    int data[qSize];

    menu();
    scanf("%d", &choice);

    while (choice != 0)
    {
        if (choice == 1)
        {
            if (qSize == rear)
            {
                printf("Queue Full!\n\n");
            }
            else
            {
                printf("data?");
                scanf("%d", &data[rear]);
                rear++;
            }
        }
        else if (choice == 2)
        {
            if (front == rear)
            {
                printf("Queue Empty!\n\n");
            }
            else
            {
                printf("%d dequeued!\n\n", data[front]);
                front++;
            }
        }
        else if (choice == 3)
        {
            printf("Current Queue Size: %d\n", rear - front);
        }
        else if (choice == 4)
        {
            if (front != rear)
            {
                printf("Front Element %d\n\n", data[front]);
            }
            else
            {
                printf("Empty Queue!\n");
            }
        }
        else
        {
            printf("Invalid Input!\n\n");
        }
        menu();
        scanf("%d", &choice);
    }

    return 0;
}

int push(int data[], int stSize, int top)
{
    if (top == stSize)
    {
        printf("Stack Overflow!\n\n");
    }
    else
    {
        printf("Enter value: ");
        scanf("%d", &data[top]);
        top++;
    }
    return top;
}

int pop(int data[], int stSize, int top)
{
    if (top == 0)
    {
        printf("Stack Underflow!\n\n");
    }
    else
    {
        top--;
        printf("%d Popped\n\n", data[top]);
    }
    return top;
}

void stack_size(int top)
{
    printf("Stack Size: %d\n\n", top);
}

void top_element(int data[], int top)
{
    if (top == 0)
    {
        printf("Stack Is Empty!\n\n");
    }
    else
    {
        printf("Top Element: %d\n\n", data[top - 1]);
    }
}

void menu()
{
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. QueueSize\n");
    printf("4. Front Element\n");
    printf("0. Exit\n");
    printf("Enter your choice:");
}
