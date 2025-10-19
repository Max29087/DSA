#include <stdio.h>
struct Node
{
    int data;
    struct Node *left, *right;
};
typedef struct Node node;

int menu();
node *insert_bst(node *temp, node *nn);
node *min_node(node *temp);
node *delete_data(node *current, int key);
node *search_bst(node *temp, int n);
void in_order(node *temp);
void post_order(node *temp);
void pre_order(node *temp);

int main()
{
    node *root = NULL, *nn;
    int choice = menu();

    while (choice != 0)
    {
        if (choice == 1)
        {
            nn = new node();
            nn->left = NULL;
            nn->right = NULL;
            printf("Enter Data:");
            scanf("%d", &nn->data);
            root = insert_bst(root, nn);
        }
        else if (choice == 2)
        {
            int key;
            printf("key:");
            scanf("%d", &key);
            root = delete_data(root, key);
        }
        else if (choice == 3)
        {
            printf("Search Key?");
            int n;
            scanf("%d", &n);

            if (search_bst(root, n) != NULL)
            {
                printf("Found!\n");
            }
            else
            {
                printf("Not Found!\n");
            }
        }
        else if (choice == 4)
        {
            printf("In-order:\n");
            in_order(root);
            printf("\n");
        }
        else if (choice == 5)
        {
            printf("Pre-order:\n");
            pre_order(root);
            printf("\n");
        }
        else if (choice == 6)
        {
            printf("Post-order:\n");
            post_order(root);
            printf("\n");
        }
        else
        {
            printf("Invalid Input!\n");
        }
        choice = menu();
    }

    return 0;
}

void post_order(node *root)
{ // left, right, root
    if (root != NULL)
    {
        post_order(root->left);
        post_order(root->right);
        printf("%d ", root->data);
    }
}

void pre_order(node *root)
{ // root, left,right
    if (root != NULL)
    {
        printf("%d ", root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
}

void in_order(node *root)
{ // left,root,right;
    if (root != NULL)
    {
        in_order(root->left);
        printf("%d ", root->data);
        in_order(root->right);
    }
}
node *search_bst(node *temp, int n)
{
    if (temp == NULL || temp->data == n)
    {
        return temp;
    }
    else if (n < temp->data)
    {
        return search_bst(temp->left, n);
    }
    else
    {
        return search_bst(temp->right, n);
    }
}

node *delete_data(node *current, int key)
{
    if (current == NULL)
    {
        return current;
    }
    else if (key < current->data)
    {
        current->left = delete_data(current->left, key);
    }
    else if (key > current->data)
    {
        current->right = delete_data(current->right, key);
    }
    else
    {
        if (current->left == NULL)
        {
            node *temp = current->right;
            return temp;
        }
        else if (current->right == NULL)
        {
            node *temp = current->left;
            return temp;
        }

        node *minNode = min_node(current->right);
        current->data = minNode->data;
        current->right = delete_data(current->right, minNode->data);
    }
    return current;
}

node *min_node(node *temp)
{
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

node *insert_bst(node *temp, node *nn)
{
    if (temp == NULL)
    {
        return nn;
    }
    else if (nn->data < temp->data)
    {
        temp->left = insert_bst(temp->left, nn); // nn
    }
    else
    {
        // nn->data > temp->data;
        temp->right = insert_bst(temp->right, nn); // 1)root:50,nn=70, returned:70
                                                   // 2)root:NULL,nn=70, returned:70
    }
    return temp;
}
int menu()
{
    printf("1)Insert\n");
    printf("2)Delete\n");
    printf("3)Search\n");
    printf("4)In-order\n");
    printf("5)Pre-order\n");
    printf("6)Post-order\n");
    printf("0)Exit!\n");
    int choice;
    printf("Enter choice:");
    scanf("%d", &choice);
    return choice;
}