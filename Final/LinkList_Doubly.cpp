#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
    struct node *previous;
};
void menu();
struct node *createNewNode();
struct node *insertHead(struct node *head, struct node *newNode);
struct node *insertTail(struct node *head, struct node *newNode);
int listSize(struct node *head);
struct node *insert_Nth_Position(struct node *head);
struct node *deleteHead(struct node *head);
struct node *deleteTail(struct node *head);
struct node *deleteNthData(struct node *head);
void printList(struct node *temp);
int main()
{
    struct node *head = NULL;
    struct node *newNode = NULL;
    int choise;
    menu(); // Menu
    cin >> choise;
    while (choise != 0)
    {
        // Insert Head;
        if (choise == 1)
        {
            newNode = createNewNode(); // Create Node;
            head = insertHead(head, newNode);
        }

        // Insert Tail;
        else if (choise == 2)
        {
            newNode = createNewNode();
            head = insertTail(head, newNode);
        }

        // Insert Nth position;
        else if (choise == 3)
        {
            head = insert_Nth_Position(head);
        }

        // Delete Head
        else if (choise == 4)
        {
            if (head != NULL)
            {
                head = deleteHead(head);
            }
            else
            {
                cout << "List Empty! Nothing to delete." << endl;
            }
        }

        // Delete Tail
        else if (choise == 5)
        {
            if (head == NULL)
            {
                cout << "List Empty! Nothing to delete." << endl;
            }
            else
            {
                head = deleteTail(head);
            }
        }

        // Delete Nth position data;
        else if (choise == 6)
        {
            if (head == NULL)
            {
                cout << "List Empty! Nothing to delete." << endl;
            }
            else
            {
                head = deleteNthData(head);
            }
        }

        // Print List ;
        else if (choise == 9)
        {
            int size = listSize(head); // List Size;
            cout << "Size Of List: ";
            cout << size << endl;
            cout << endl;
            cout << "Data" << endl;
            printList(head);
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
    cout << endl;
    cout << "1. Create New Node & Insert Head." << endl;
    cout << "2. Create New Node & Insert Tail." << endl;
    cout << "3. Create New Node & Insert Nth Position." << endl;
    cout << "4. Delete Head." << endl;
    cout << "5. Delete Tail." << endl;
    cout << "6. Delete Nth position Data." << endl;
    cout << "9. Print List." << endl;
    cout << "0. Exit." << endl;
    cout << "Enter Your Choise: ";
}

// Create Node;
struct node *createNewNode()
{
    struct node *newNode = new node;
    cout << "Enter Data:";
    cin >> newNode->data;
    newNode->next = NULL;
    newNode->previous = NULL;
    cout << endl;
    cout << "New Node Create Successfully." << endl;
    return newNode;
}

// Insert Head;
struct node *insertHead(struct node *head, struct node *newNode)
{
    if (head != NULL)
    {
        newNode->next = head;
        head->previous = newNode;
    }
    head = newNode;
    cout << endl;
    cout << "Head Insert Successfully." << endl;
    return head;
}

// Insert Tail;
struct node *insertTail(struct node *head, struct node *newNode)
{
    if (head != NULL)
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->previous = temp;
        cout << endl;
        cout << "Tail Insert Successfully." << endl;
    }
    else
    {
        cout << "List is empty! So New Node added on the Head..." << endl;
        head = insertHead(head, newNode);
    }
    return head;
}

// Insert Nth position;
struct node *insert_Nth_Position(struct node *head)
{
    cout << "Enter Position: ";
    int position;
    cin >> position;
    int size = listSize(head);
    if (position == size + 1)
    {
        struct node *newNode = createNewNode();
        return insertTail(head, newNode);
    }
    else if (position == 1)
    {
        struct node *newNode = createNewNode();
        return insertHead(head, newNode);
    }
    else if (position < 1 || position > size + 1)
    {
        cout << "Invalid position!" << endl;
        return head;
    }
    else
    {
        struct node *newNode = createNewNode();
        struct node *temp = head;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->previous = temp;
        temp->next->previous = newNode;
        temp->next = newNode;
        cout << "Data Insert Nth Position." << endl;
    }
    return head;
}

// List Size;
int listSize(struct node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

// Print List ;
void printList(struct node *temp)
{
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Delete Head
struct node *deleteHead(struct node *head)
{
    struct node *temp = head;
    head = head->next;
    if (head != NULL)
    {
        head->previous = NULL;
    }
    delete (temp);
    cout << "Head delete Successfully." << endl;
    return head;
}

// Delete Tail
struct node *deleteTail(struct node *head)
{
    struct node *temp = head;
    if (head->next == NULL)
    {
        cout << "List size 1, So tail = head." << endl;
        delete (head);
        return NULL;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        struct node *del = temp->next;
        temp->next = NULL;
        delete (del);
        cout << "Tail delete Successfully." << endl;
    }
    return head;
}

// Delete Nth position data;
struct node *deleteNthData(struct node *head)
{
    int position;
    cout << "Enter Delete Position: ";
    cin >> position;
    if (position == 1)
    {
        cout << "Delete position 1, So head delete..." << endl;
        head = deleteHead(head);
    }
    else if (position == listSize(head))
    {
        cout << "Delete position = list size,So tail delete..." << endl;
        head = deleteTail(head);
    }
    else if (position > 1 && position < listSize(head))
    {
        struct node *temp = head;
        struct node *del;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        del = temp->next;
        temp->next = del->next;
        del->next->previous = temp;
        delete (del);
        cout << "Successfully Delete Nth Position Data." << endl;
    }
    else
    {
        cout << "Invalid Position!" << endl;
    }
    return head;
}