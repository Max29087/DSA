#include <iostream>
#include <stdio.h>
using namespace std;

int dataQ[100], qsize = 0, frnt = 0, rear = 0, vcount = 0;

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;

node *createNode(int x);
void printList(node *head);
node *insert_tail(node *head, node *nn);

void enqueue(int x);
int dequeue();
int check_existence(int visited[], int now, int n);

int main()
{
    int n;
    printf("Number of vertices? ");
    scanf("%d", &n);

    int graph[n][n];

    // initialize matrix with 0
    for (int row = 0; row < n; row++)
        for (int col = 0; col < n; col++)
            graph[row][col] = 0;

    // input edges (undirected)
    for (int row = 0; row < n; row++)
    {
        for (int col = row + 1; col < n; col++)
        {
            printf("%c-%c: ", row + 'A', col + 'A');
            scanf("%d", &graph[row][col]);
            graph[col][row] = graph[row][col];
        }
    }

    // print adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
            printf("%d\t", graph[row][col]);
        printf("\n");
    }

    // adjacency list creation
    node *head_arr[n], *nn;
    for (int i = 0; i < n; i++)
    {
        nn = createNode(i);
        head_arr[i] = nn;
    }

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (graph[row][col] == 1)
            {
                nn = createNode(col);
                head_arr[row] = insert_tail(head_arr[row], nn);
            }
        }
    }

    printf("\nAdjacency List:\n");
    for (int i = 0; i < n; i++)
    {
        printList(head_arr[i]);
    }

    // ---------------- BFS with Shortest Distance ----------------
    int visited[n], dist[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        dist[i] = -1;
    }

    qsize = 50;
    char ch;
    printf("\nStart vertex (A/B/C...): ");
    fflush(stdin);
    scanf(" %c", &ch);
    int start = ch - 'A';

    enqueue(start);
    visited[start] = 1;
    dist[start] = 0; // distance of start from itself = 0

    while (vcount != 0)
    {
        int now = dequeue();

        node *temp = head_arr[now]->next;
        while (temp != NULL)
        {
            int neigh = temp->data;
            if (visited[neigh] == 0)
            {
                enqueue(neigh);
                visited[neigh] = 1;
                dist[neigh] = dist[now] + 1; // distance update
            }
            temp = temp->next;
        }
    }

    // print BFS distance results
    printf("\nShortest distance from %c:\n", start + 'A');
    for (int i = 0; i < n; i++)
    {
        printf("%c : %d\n", i + 'A', dist[i]);
    }

    return 0;
}

// ---------------- Queue Functions ----------------

void enqueue(int x)
{
    if (vcount == qsize)
    {
        printf("Queue Full!\n");
    }
    else
    {
        dataQ[rear] = x;
        rear = (rear + 1) % qsize;
        vcount++;
    }
}

int dequeue()
{
    if (vcount <= 0)
    {
        printf("Queue Empty!\n");
        return -1;
    }
    else
    {
        int val = dataQ[frnt];
        frnt = (frnt + 1) % qsize;
        vcount--;
        return val;
    }
}

// ---------------- Linked List Functions ----------------

node *createNode(int x)
{
    node *nn = new node();
    nn->data = x;
    nn->next = NULL;
    return nn;
}

void printList(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%c ", temp->data + 'A');
        temp = temp->next;
    }
    printf("\n");
}

node *insert_tail(node *head, node *nn)
{
    if (head == NULL)
        return nn;

    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = nn;
    return head;
}
