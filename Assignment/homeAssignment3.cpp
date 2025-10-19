#include <iostream>
using namespace std;
int listSize = 0; // global variable to count the list size;

struct node
{
    int data;
    struct node *next;
};

void menu();
struct node *createNewNode();
struct node *insertTail(struct node *head, struct node *newNode);
struct node *deleteHead(struct node *head);

int main()
{
    struct node *head = NULL;
    struct node *newNode = NULL;

    int choise;
    menu(); // Menu
    cin >> choise;

    while (choise != 0)
    {
        // Enqueue ;
        if (choise == 1)
        {
            newNode = createNewNode(); // Create Node;
            if (head == NULL)
            {
                listSize++;
                head = newNode;
            }
            else
            {
                listSize++;
                head = insertTail(head, newNode);
            }
            cout << "Enqueue Successfully." << endl;
        }

        // Dequeue;
        else if (choise == 2)
        {
            if (head != NULL)
            {
                listSize--;
                cout << head->data << " dequeued!" << endl;
                head = deleteHead(head);
            }
            else
            {
                cout << "Queue Empty! Nothing to dequeue." << endl;
            }
        }

        // QueueSize
        else if (choise == 3)
        {
            cout << "QueueSize: " << listSize << endl;
        }

        // FrontElement
        else if (choise == 4)
        {
            if (head == NULL)
            {
                cout << "Queue Empty!" << endl;
            }
            else
            {
                cout << "Front Element: " << head->data << endl;
            }
        }
        menu();
        cin >> choise;
        cout << endl;
    }
    return 0;
}

// Menu

void menu()
{
    printf("\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. QueueSize\n");
    printf("4. Front Element\n");
    printf("0. Exit\n");
    printf("Enter your choice:");
}

// Create Node;
struct node *createNewNode()
{
    struct node *newNode = new node;
    cout << "Enter Data:";
    cin >> newNode->data;
    newNode->next = NULL;
    cout << endl;
    return newNode;
}

// Insert Tail;
struct node *insertTail(struct node *head, struct node *newNode)
{
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    cout << endl;
    return head;
}

// Delete Head
struct node *deleteHead(struct node *head)
{
    struct node *temp = head;
    head = head->next;
    delete (temp);
    return head;
}
