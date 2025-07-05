#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

bool searchBST(TreeNode* root, int key) {
    if (root == nullptr) return false;  // Key not found
    if (root->data == key) return true; // Key found
    if (root->data > key) 
        return searchBST(root->left, key); // Search in the left subtree
    else 
        return searchBST(root->right, key); // Search in the right subtree
}

TreeNode* insertintoBST(TreeNode* root, int val) {
    if (root == nullptr) {
        TreeNode* temp = new TreeNode(val);
        return temp;
    }
    if (root->data > val) {
        root->left = insertintoBST(root->left, val);
    } else {
        root->right = insertintoBST(root->right, val);
    }
    return root;
}

TreeNode* maxvalue(TreeNode* root) {
    TreeNode* temp = root;
    while (temp->right != nullptr) {
        temp = temp->right;
    }
    return temp;
}

TreeNode* deletefromBST(TreeNode* root, int val) {
    if (root == nullptr) {
        return root;
    }
    if (root->data == val) {
        // 0 child
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        // 1 child (right child only)
        else if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        // 1 child (left child only)
        else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        // 2 children
        else {
            int maxOfPredecessor = maxvalue(root->left)->data;
            root->data = maxOfPredecessor;
            root->left = deletefromBST(root->left, maxOfPredecessor);
        }
    } else if (root->data > val) {
        root->left = deletefromBST(root->left, val);
    } else {
        root->right = deletefromBST(root->right, val);
    }
    return root;
}

void levelordertraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        if (temp == nullptr) {
            cout << endl;
            if (!q.empty()) {
                q.push(nullptr);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

TreeNode* takeinput() {
    TreeNode* root = nullptr;
    int data;
    cout << "Enter elements to insert into BST (-1 to stop):" << endl;
    cin >> data;
    while (data != -1) {
        root = insertintoBST(root, data);
        cin >> data;
    }
    return root;
}

int main() {
    TreeNode* root = takeinput();

    cout << "Level Order Traversal:" << endl;
    levelordertraversal(root);

    int searchKey, deleteKey;

    // Search in BST
    cout << "Enter value to search in BST: ";
    cin >> searchKey;

    if (searchBST(root, searchKey)) {
        cout << searchKey << " is found in the BST." << endl;
    } else {
        cout << searchKey << " is not found in the BST." << endl;
    }

    // Delete from BST
    cout << "Enter node to delete: ";
    cin >> deleteKey;
    root = deletefromBST(root, deleteKey);

    cout << "Level Order Traversal after Deletion:" << endl;
    levelordertraversal(root);

    // Search again in BST
    cout << "Enter value to search in BST: ";
    cin >> searchKey;

    if (searchBST(root, searchKey)) {
        cout << searchKey << " is found in the BST." << endl;
    } else {
        cout << searchKey << " is not found in the BST." << endl;
    }

    return 0;
}
