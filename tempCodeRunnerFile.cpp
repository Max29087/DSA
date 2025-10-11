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
int check_existence(int visited[], int now, int n);
void dequeue();

int main()
{
    int n;
    printf("vertex: ");
    scanf("%d", &n);
    int graph[n][n];

    // assign 0 to each index
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            graph[row][col] = 0;
        }
    }

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row == col)
            {
                continue;
            }
            printf("%c-%c:", row + 'A', col + 65);
            scanf("%d", &graph[row][col]);
        }
    }

    // print the graph
    printf("Adjacency Matrix:\n");
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            printf("%d\t\t", graph[row][col]);
        }
        printf("\n");
    }

    node *head_arr[n], *nn;
    for (int i = 0; i < n; i++)
    {
        head_arr[i] = createNode(i);
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

    printf("Adjacency List: \n");
    for (int i = 0; i < n; i++)
    {
        cout << head_arr[i]->data;
        printList(head_arr[i]);
    }
    int visited[n];
    qsize = 50;
    char ch;
    printf("Start from: ");
    // getchar();
    scanf(" %c", &ch); // A/B/C/D...
    int start = ch - 65;
    visited[0] = start;

    node *temp = head_arr[start]->next;
    while (temp != NULL)
    {
        enqueue(temp->data);
        temp = temp->next;
    }

    int now, i = 1;
    while (vcount != 0)
    {
        now = data[frnt];
        int check = check_existence(visited, now, i);

        if (check == 0)
        {
            visited[i] = now;
            i++;
            dequeue();

            temp = head_arr[now]->next;
            while (temp != NULL)
            {
                enqueue(temp->data);
                temp = temp->next;
            }
        }
        else
        {
            dequeue();
        }
    }

    printf("BFS: ");
    for (int i = 0; i < n; i++)
    {
        printf("%c ", visited[i] + 65);
    }
    cout << endl;

    return 0;
}

void dequeue()
{
    if (vcount <= 0)
    {
        printf("Queue Empty!\n\n");
    }
    else
    {
        frnt = (frnt + 1) % qsize;
        vcount--;
    }
}

int check_existence(int visited[], int now, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == now)
        {
            return 1;
        }
    }
    return 0;
}

void enqueue(int x)
{
    if (vcount == qsize)
    {
        printf("Queue Full!\n\n");
    }
    else
    {
        data[rear] = x;
        rear = (rear + 1) % qsize;
        vcount++;
    }
}
node *createNode(int x)
{
    node *nn = new node();
    nn->data = x;
    nn->next = NULL;
    return nn;
}

// Print List
void printList(node *head)
{
    cout << char(head->data + 'A') << ": ";

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
            {
                cout << " -> ";
            }
        }
    }
    cout << endl;
}

node *insert_head(node *head, node *nn)
{
    node *temp = head;
    if (head != NULL)
    {
        nn->next = head;
    }
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
        {
            temp = temp->next;
        }
        temp->next = nn;
    }
    return head;
}
