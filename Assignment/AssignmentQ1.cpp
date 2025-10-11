#include <iostream>
using namespace std;

int data[100], qsize = 0, frnt = 0, rear = 0, vcount = 0;

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;

node *createNode(int x);
void printList(node *head);
node *insert_head(node *head, node *nn);
node *insert_tail(node *head, node *nn);
void enqueue(int x);
void dequeue();
int check_existence(int visited[], int now, int n);

int main()
{
    int n;
    printf("vertex: ");
    scanf("%d", &n);

    int graph[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            printf("%c-%c: ", i + 'A', j + 'A');
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d\t", graph[i][j]);
        printf("\n");
    }

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

    printf("Adjacency List:\n");
    for (int i = 0; i < n; i++)
    {
        cout << char(head_arr[i]->data + 'A') << ": ";
        printList(head_arr[i]);
    }

    qsize = 50;
    char src_ch, dest_ch;
    printf("Start from: ");
    scanf(" %c", &src_ch);
    printf("Find distance to: ");
    scanf(" %c", &dest_ch);

    int start = src_ch - 'A';
    int dest = dest_ch - 'A';

    int visited[n], dist[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        dist[i] = -1;
    }

    visited[start] = 1;
    dist[start] = 0;
    enqueue(start);

    while (vcount != 0)
    {
        int now = data[frnt];
        dequeue();

        node *temp = head_arr[now]->next;
        while (temp != NULL)
        {
            int v = temp->data;
            if (visited[v] == 0)
            {
                visited[v] = 1;
                dist[v] = dist[now] + 1;
                enqueue(v);
            }
            temp = temp->next;
        }
    }

    if (dist[dest] != -1)
        printf("Shortest distance between %c and %c is: %d\n", src_ch, dest_ch, dist[dest]);
    else
        printf("No path found between %c and %c\n", src_ch, dest_ch);

    return 0;
}

void dequeue()
{
    if (vcount <= 0)
        return;
    frnt = (frnt + 1) % qsize;
    vcount--;
}

void enqueue(int x)
{
    if (vcount == qsize)
        return;
    data[rear] = x;
    rear = (rear + 1) % qsize;
    vcount++;
}

int check_existence(int visited[], int now, int n)
{
    for (int i = 0; i < n; i++)
        if (visited[i] == now)
            return 1;
    return 0;
}

node *createNode(int x)
{
    node *nn = new node();
    nn->data = x;
    nn->next = NULL;
    return nn;
}

void printList(node *head)
{
    node *temp = head->next;
    if (temp == NULL)
    {
        cout << "NULL";
    }
    else
    {
        while (temp != NULL)
        {
            cout << char(temp->data + 'A');
            temp = temp->next;
            if (temp != NULL)
                cout << " -> ";
        }
    }
    cout << endl;
}

node *insert_head(node *head, node *nn)
{
    if (head != NULL)
        nn->next = head;
    head = nn;
    return head;
}

node *insert_tail(node *head, node *nn)
{
    node *temp = head;
    if (temp == NULL)
    {
        head = insert_head(head, nn);
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = nn;
    }
    return head;
}
