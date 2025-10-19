#include <iostream>
using namespace std;

// ------------------- Structures -------------------
struct Node
{
    int data;
    Node *left, *right;
};
typedef Node node;

// ------------------- Function Declarations -------------------
int menu();
node *insert_bst(node *root, node *nn);
node *delete_data(node *current, int key);
node *min_node(node *temp);
node *search_bst(node *temp, int n);
void in_order(node *root, int arr[], int &ind);
void pre_order(node *root);
void post_order(node *root);

// ------------------- Main Function -------------------
int main()
{
    node *root = NULL, *nn;
    int arr[100];
    int choice;

    do
    {
        choice = menu();
        switch (choice)
        {
        case 1: // Insert
        {
            nn = new node();
            nn->left = nn->right = NULL;
            cout << "Enter data: ";
            cin >> nn->data;
            root = insert_bst(root, nn);
            break;
        }

        case 2: // Delete
        {
            int key;
            cout << "Enter key to delete: ";
            cin >> key;
            root = delete_data(root, key);
            break;
        }

        case 3: // Search
        {
            int key;
            cout << "Enter key to search: ";
            cin >> key;
            if (search_bst(root, key))
                cout << "Found!\n";
            else
                cout << "Not Found!\n";
            break;
        }

        case 4: // In-order
        {
            cout << "In-order Traversal: ";
            int ind = 0;
            in_order(root, arr, ind);
            for (int i = 0; i < ind; i++)
                cout << arr[i] << " ";
            cout << endl;
            break;
        }

        case 5: // Pre-order
        {
            cout << "Pre-order Traversal: ";
            pre_order(root);
            cout << endl;
            break;
        }

        case 6: // Post-order
        {
            cout << "Post-order Traversal: ";
            post_order(root);
            cout << endl;
            break;
        }

        case 7: // Descending order divisible by 5
        {
            cout << "Descending order (divisible by 5): ";
            int ind = 0;              // Reset index
            in_order(root, arr, ind); // fill array (ascending)
            for (int i = ind - 1; i >= 0; i--)
            {
                if (arr[i] % 5 == 0)
                    cout << arr[i] << " ";
            }
            cout << endl;
            break;
        }

        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
            break;
        }
    } while (choice != 0);

    return 0;
}

// ------------------- BST Functions -------------------
node *insert_bst(node *root, node *nn)
{
    if (root == NULL)
        return nn;

    if (nn->data < root->data)
        root->left = insert_bst(root->left, nn);
    else
        root->right = insert_bst(root->right, nn);

    return root;
}

node *min_node(node *temp)
{
    while (temp && temp->left != NULL)
        temp = temp->left;
    return temp;
}

node *delete_data(node *current, int key)
{
    if (current == NULL)
        return current;

    if (key < current->data)
        current->left = delete_data(current->left, key);
    else if (key > current->data)
        current->right = delete_data(current->right, key);
    else
    {
        // Node found
        if (current->left == NULL)
        {
            node *temp = current->right;
            delete current;
            return temp;
        }
        else if (current->right == NULL)
        {
            node *temp = current->left;
            delete current;
            return temp;
        }

        node *minNode = min_node(current->right);
        current->data = minNode->data;
        current->right = delete_data(current->right, minNode->data);
    }
    return current;
}

node *search_bst(node *temp, int n)
{
    if (temp == NULL || temp->data == n)
        return temp;
    if (n < temp->data)
        return search_bst(temp->left, n);
    return search_bst(temp->right, n);
}

// ------------------- Traversal Functions -------------------
void in_order(node *root, int arr[], int &ind)
{
    if (root != NULL)
    {
        in_order(root->left, arr, ind);
        arr[ind++] = root->data; // store only, no print
        in_order(root->right, arr, ind);
    }
}

void pre_order(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        pre_order(root->left);
        pre_order(root->right);
    }
}

void post_order(node *root)
{
    if (root != NULL)
    {
        post_order(root->left);
        post_order(root->right);
        cout << root->data << " ";
    }
}

// ------------------- Menu Function -------------------
int menu()
{
    cout << "\n--- BST Menu ---\n";
    cout << "1) Insert\n";
    cout << "2) Delete\n";
    cout << "3) Search\n";
    cout << "4) In-order\n";
    cout << "5) Pre-order\n";
    cout << "6) Post-order\n";
    cout << "7) Descending (Divisible by 5)\n";
    cout << "0) Exit\n";
    cout << "Enter choice: ";
    int choice;
    cin >> choice;
    return choice;
}
