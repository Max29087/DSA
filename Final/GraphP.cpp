#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
node *createNode(int x);
node *insertTail(node *head, node *nn);
void printList(node *head);
int n;
int main()
{
    cout << "Enter the number of Vertex: ";
    cin >> n;
    int graph[n][n];

    // Graph Initialize with 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    // Print the graph;
    cout << "Before Insert Connection:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << graph[i][j] << "\t\t";
        }
        cout << endl;
    }

    // Insert connection
    cout << "Insert Connection:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            cout << char('A' + i) << "-" << char('A' + j) << "= ";
            cin >> graph[i][j];
            graph[j][i] = graph[i][j];
        }
    }
    // Print the graph;
    cout << "After Insert Connection:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << graph[i][j] << "\t\t";
        }
        cout << endl;
    }

    // Adjacency List;

    // Create n sonkhok head;
    node *head[n], *nn;
    for (int i = 0; i < n; i++)
    {
        head[i] = createNode(i);
    }

    // Insert Connection on Adjacency List;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 1)
            {
                nn = createNode(j);
                head[i] = insertTail(head[i], nn);
            }
        }
    }

    // Print Adjacency List;
    cout << "Adjacency List: " << endl;
    for (int i = 0; i < n; i++)
    {
        printList(head[i]);
    }
    return 0;
}

// Create Node;
node *createNode(int x)
{
    node *nn = new node();
    nn->data = x;
    nn->next = NULL;
    return nn;
}

// Insert tail;
node *insertTail(node *head, node *nn)
{
    node *temp = head;
    if (temp->next == NULL)
    {
        temp->next = nn;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nn;
    }
    return head;
}

// Print List
void printList(node *head)
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        if (count == 0)
        {
            cout << char(temp->data + 'A') << ": ";
            temp = temp->next;
            count = 1;
        }
        cout << char(temp->data + 'A');
        temp = temp->next;
        if (temp != NULL)
        {
            cout << " -> ";
        }
    }
    cout << endl;
}