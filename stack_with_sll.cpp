#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};
typedef struct Node node;

void menu();
node* createNode();
void printList(node* head);
node* insert_head(node* head, node* nn);
node* insert_tail(node* head, node* nn);
node* delete_head(node *head);
int ListSize(node* head);
node* delete_tail(node *head);


int main()
{
    node* head = NULL, *nn;
    int choice,stackSize,top=-1;
    printf("Stack Size?");
    scanf("%d",&stackSize);
    menu();
    scanf("%d",&choice);

    while(choice!=0){
        if(choice==1){
            if(stackSize==top+1){
                printf("Stack Overflow!\n\n");
            }else{
                top++;
                nn = createNode();
                if(head==NULL){
                    head = insert_head(head,nn);
                }else{
                    head = insert_tail(head,nn);
                }
            }
        }else if(choice==2){
            if(top==-1){
                printf("Stack Underflow!\n\n");
            }else{
                top--;
                head = delete_tail(head);
            }
        }else if(choice==3){
            printList(head);
        }else if(choice==4){
            printf("current size: %d\n",top+1);
        }else{
            printf("Invalid Choice!\n\n");
        }
        menu();
        scanf("%d",&choice);
    }

    printf("\nYour pressed the Exit button!\nbye...\n");
}

node* createNode()
{
    node* nn=new node();
    printf("Enter data:");
    scanf("%d",&nn->data);
    nn->next = NULL;
    return nn;
}

void printList(node* head)
{
    node* temp = head;
    if(temp==NULL)
    {
        printf("Empty Stack!\n");
    }
    else
    {
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        printf("top Element: %d\n\n",temp->data);
    }
    printf("\n");
}

node* insert_head(node* head, node* nn)
{
    node* temp = head;
    if(head!=NULL)
    {
        nn->next=head;
    }
    head=nn;
    printf("Node inserted in Head!\n\n");
    return head;
}

node* insert_tail(node* head, node* nn)
{
    node* temp = head;
    if(temp==NULL)
    {
        head = insert_head(head,nn);
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nn;
    }
    printf("Node inserted in Tail!\n\n");
    return head;
}

node* delete_head(node *head)
{
    if(head == NULL)
    {
        printf("nothing to delete\n\n");
    }
    else
    {
        node *temp;
        temp = head;

        head = head->next;
        printf("%d poped!\n",temp->data);
        delete(temp);
    }
    return head;
}

int ListSize(node* head)
{
    node* temp= head;
    int counter=0;
    while(temp != NULL)
    {
        counter++;
        temp=temp->next;
    }
    return counter;
}

node* delete_tail(node *head)
{
    int n;
    n = ListSize(head);

    if(n <= 1)
    {
        head = delete_head(head);
    }
    else
    {
        int i;
        node *temp;
        temp = head;

        for(i = 1; i <= n-2; i++)
        {
            temp = temp->next;
        }
        printf("%d poped!\n",temp->next->data);
        delete(temp->next);
        temp->next = NULL;
    }
    return head;
}

void menu()
{
    printf("1) Push()\n");
    printf("2) Pop()\n");
    printf("3) Peek()\n");
    printf("4) Current Size\n");
    printf("0) Exit!\n");
    printf("Enter your choice:");
}
