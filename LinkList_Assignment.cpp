#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
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
struct node *updateNodeValue(struct node *head);
void reverseLinkedList(struct node *head);
struct node *BinarySearch(struct node *head, int key);
struct node *midFind(struct node *start, struct node *end);
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
            cout << "Head Insert Successfully." << endl;
            cout << endl;
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

        // Update a Node Value.
        else if (choise == 7)
        {
            head = updateNodeValue(head);
        }

        // Reverse the Linked List.
        else if (choise == 8)
        {
            reverseLinkedList(head);
        }

        // Search and Modify the List.
        else if (choise == 9)
        {
            int key;
            cout << "Current List: ";
            printList(head);
            cout << "Enter Key:";
            cin >> key;
            head = BinarySearch(head, key);
            cout << "Updated List: ";
            printList(head);
        }

        // Print List ;
        else if (choise == 10)
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
    cout << "7. Update a Node Value." << endl;
    cout << "8. Reverse the Linked List." << endl;
    cout << "9. Search and Modify the List." << endl;
    cout << "10. Print List & Size." << endl;
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
    }
    head = newNode;
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
    int size = listSize(head);
    int position;
    cout << "Enter Delete Position: ";
    cin >> position;
    if (position == 1)
    {
        cout << "Delete position 1, So head delete..." << endl;
        head = deleteHead(head);
    }
    else if (position == size)
    {
        cout << "Delete position = list size,So tail delete..." << endl;
        head = deleteTail(head);
    }
    else if (position > 1 && position < size)
    {
        struct node *temp = head;
        struct node *del;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        del = temp->next;
        temp->next = del->next;
        delete (del);
        cout << "Successfully Delete Nth Position Data." << endl;
    }
    else
    {
        cout << "Invalid Position!" << endl;
    }
    return head;
}

// Update a Node Value.
struct node *updateNodeValue(struct node *head)
{
    int position;
    int size = listSize(head);
    if (head != NULL)
    {
        cout << "Current List: ";
        printList(head);
        cout << "Enter Position: ";
        cin >> position;
        if (position == 1)
        {
            cout << "Enter new value: ";
            cin >> head->data;
            cout << "Updated List: ";
            printList(head);
        }
        else if (position > 1 && position <= size)
        {
            struct node *temp = head;
            for (int i = 1; i < position; i++)
            {
                temp = temp->next;
            }
            cout << "Enter new value: ";
            cin >> temp->data;
            cout << "Updated List: ";
            printList(head);
        }
        else
        {
            cout << "Invalit Position!" << endl;
        }
    }
    else
    {
        cout << "List Empty!" << endl;
    }
    return head;
}

// Reverse the Linked List.
void reverseLinkedList(struct node *head)
{
    int size = listSize(head);
    if (head == NULL)
    {
        cout << "List empty!" << endl;
    }
    else
    {
        cout << "Current List: ";
        printList(head);
        struct node *tempList = NULL;
        struct node *temp = head;
        for (int i = 1; i <= size; i++)
        {
            struct node *newNode = new node;
            newNode->data = temp->data;
            newNode->next = NULL;
            tempList = insertHead(tempList, newNode);
            temp = temp->next;
        }
        cout << "Reversed List: ";
        printList(tempList);
        cout << endl;
    }
}

// Search and Modify the List.
struct node *BinarySearch(struct node *head, int key)
{
    struct node *start = head;
    struct node *end = NULL;
    while (start != end)
    {
        struct node *mid = midFind(start, end);
        if (mid == NULL)
        {
            return head;
        }
        else if (mid->data == key)
        {
            if (mid == head)
            {
                head = head->next;
                delete (mid);
                cout << "Key found and deleted." << endl;
                return head;
            }
            else
            {
                struct node *temp = head;
                while (temp->next != mid)
                {
                    temp = temp->next;
                }
                temp->next = mid->next;
                delete (mid);
                cout << "Key found and deleted." << endl;
                return head;
            }
        }
        else if (mid->data > key)
        {
            end = mid;
        }
        else
        {
            start = mid->next;
        }
    }
    cout << "Key not found, so inserted at the end" << endl;
    struct node *newNode = new node;
    newNode->data = key;
    newNode->next = NULL;
    head = insertTail(head, newNode);
    return head;
}

// Find Mid
struct node *midFind(struct node *start, struct node *end)
{
    struct node *slow = start;
    if (start == NULL)
    {
        return NULL;
    }
    struct node *fast = start->next;
    while (fast != end)
    {
        fast = fast->next;
        if (fast != end)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}