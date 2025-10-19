#include <stdio.h>
void menu();

int main()
{
    int choice, qSize, front = 0, rear = 0, vcount = 0;

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
            if (vcount == qSize)
            {
                printf("Queue Full!\n\n");
            }
            else
            {
                printf("data?");
                scanf("%d", &data[rear]);
                rear = (rear + 1) % qSize;
                vcount++;
            }
        }
        else if (choice == 2)
        {
            if (vcount <= 0)
            {
                printf("Queue Empty!\n\n");
            }
            else
            {
                printf("%d dequeued!\n\n", data[front]);
                front = (front + 1) % qSize;
                vcount--;
            }
        }
        else if (choice == 3)
        {
            printf("Queue Size: %d\n\n", vcount);
        }
        else if (choice == 4)
        {
            if (vcount > 0 && vcount <= qSize)
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

void menu()
{
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. QueueSize\n");
    printf("4. Front Element\n");
    printf("0. Exit\n");
    printf("Enter your choice:");
}
