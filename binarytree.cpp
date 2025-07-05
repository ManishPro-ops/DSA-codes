#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

node *buildtree(node *root)
{
    cout << " enter the data " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return nullptr;
    }
    cout << " enter the data for inserting in left of " << data << endl;
    root->left = buildtree(root->left);
    cout << " enter the data for inserting in right of " << data << endl;
    root->right = buildtree(root->right);

    return root;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
 

//morris traversal

void morrisInOrder(node* root) {
    node* current = root;

    while (current != nullptr) {
        if (current->left == nullptr) {
            // Visit the node
            cout << current->data << " ";
            // Move to the right subtree
            current = current->right;
        } else {
            // Find the in-order predecessor of the current node
            node* predecessor = current->left;
            while (predecessor->right != nullptr && predecessor->right != current) {
                predecessor = predecessor->right;
            }

            if (predecessor->right == nullptr) {
                // Establish a temporary link to the current node
                predecessor->right = current;
                current = current->left;
            } else {
                // Restore the original tree structure
                predecessor->right = nullptr;
                // Visit the node
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
}


void levelordertraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == nullptr)
        {
            cout << endl;

            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    node *root = nullptr;
    root = buildtree(root);

    cout << "printing the level order traversal :" << endl;

    levelordertraversal(root);
    cout << endl
         << "the inorder traversal is :";
    inorder(root);
    cout << endl
         << "the preorder traversal is :";
    preorder(root);
    cout << endl
         << "the postorder traversal is :";
    postorder(root);

    return 0;
}