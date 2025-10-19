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

// ---------------- Queue Functions ----------------
void enqueue(int x)
{
    if (vcount == qsize)
        printf("Queue Full!\n");
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

// ---------------- Main Function ----------------
int main()
{
    int n;
    printf("Number of vertices? ");
    scanf("%d", &n);

    int graph[n][n];

    // initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    // input edges (undirected)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c-%c: ", i + 'A', j + 'A');
            scanf("%d", &graph[i][j]);
        }
    }

    // print adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d\t", graph[i][j]);
        printf("\n");
    }

    // adjacency list
    node *head_arr[n], *nn;
    for (int i = 0; i < n; i++)
        head_arr[i] = createNode(i);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 1)
            {
                nn = createNode(j);
                head_arr[i] = insert_tail(head_arr[i], nn);
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
    char startCh, endCh;
    printf("\nStart vertex (A/B/C...): ");
    fflush(stdin);
    scanf(" %c", &startCh);

    printf("Destination vertex (A/B/C...): ");
    fflush(stdin);
    scanf(" %c", &endCh);

    int start = startCh - 'A';
    int end = endCh - 'A';

    // enqueue start
    enqueue(start);
    visited[start] = 1;
    dist[start] = 0;

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
                dist[neigh] = dist[now] + 1;
            }
            temp = temp->next;
        }
    }

    // ---------------- Output ----------------
    printf("\nBFS Traversal (from %c): ", start + 'A');
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            printf("%c ", i + 'A');
    }

    printf("\nShortest distance from %c to %c = %d\n", start + 'A', end + 'A', dist[end]);

    return 0;
}
