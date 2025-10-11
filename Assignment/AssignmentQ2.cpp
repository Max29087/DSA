#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;

node *push(node *head, int val)
{
    node *nn = new node();
    nn->data = val;
    nn->next = head;
    head = nn;
    return head;
}

node *pop(node *head, int *val)
{
    if (head == NULL)
        return NULL;
    node *temp = head;
    *val = temp->data;
    head = head->next;
    delete temp;
    return head;
}

int topElement(node *head)
{
    if (head == NULL)
        return -1;
    return head->data;
}

int isEmpty(node *head)
{
    return head == NULL;
}

void menu()
{
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Front Element\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

int main()
{
    node *stack1 = NULL, *stack2 = NULL;
    int choice, val;
    menu();
    scanf("%d", &choice);

    while (choice != 0)
    {
        if (choice == 1)
        {
            printf("Enter data: ");
            scanf("%d", &val);
            stack1 = push(stack1, val);
            printf("%d enqueued!\n\n", val);
        }
        else if (choice == 2)
        {
            if (isEmpty(stack1) && isEmpty(stack2))
            {
                printf("Queue Empty!\n\n");
            }
            else
            {
                if (isEmpty(stack2))
                {
                    while (!isEmpty(stack1))
                    {
                        stack1 = pop(stack1, &val);
                        stack2 = push(stack2, val);
                    }
                }
                stack2 = pop(stack2, &val);
                printf("%d dequeued!\n\n", val);
            }
        }
        else if (choice == 3)
        {
            if (isEmpty(stack1) && isEmpty(stack2))
            {
                printf("Queue Empty!\n\n");
            }
            else
            {
                if (isEmpty(stack2))
                {
                    while (!isEmpty(stack1))
                    {
                        stack1 = pop(stack1, &val);
                        stack2 = push(stack2, val);
                    }
                }
                printf("Front Element: %d\n\n", topElement(stack2));
            }
        }
        else
        {
            printf("Invalid Choice!\n\n");
        }

        menu();
        scanf("%d", &choice);
    }

    printf("Program Ended!\n");
    return 0;
}
