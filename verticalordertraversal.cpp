#include <iostream>
using namespace std;
#include<vector>
#include<queue>
#include<map>

// Binary Tree Node class
template <typename T = int>
class TreeNode {
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val) {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if (left != NULL) {
            delete left;
        }
        if (right != NULL) {
            delete right;
        }
    }
};

vector<int> getTopView(TreeNode<int> *root)
{
    if (!root) return {}; // Handle empty tree case

    map<int, int> Node; // Map to store horizontal distance and the first node at that distance
    queue<pair<TreeNode<int>*, int>> todo; // Queue to store nodes with their horizontal distances

    todo.push({root, 0}); // Start with root at horizontal distance 0

    while (!todo.empty()) {
        auto p = todo.front();
        todo.pop();

        TreeNode<int>* node = p.first;
        int horizontal_distance = p.second;

        // If this horizontal distance is encountered for the first time, add it to the map
        if (Node.find(horizontal_distance) == Node.end()) {
            Node[horizontal_distance] = node->data;
        }

        // Add left child to the queue with updated horizontal distance
        if (node->left) {
            todo.push({node->left, horizontal_distance - 1});
        }

        // Add right child to the queue with updated horizontal distance
        if (node->right) {
            todo.push({node->right, horizontal_distance + 1});
        }
    }

    // Extract the top view from the map
    vector<int> ans;
    for (auto& p : Node) {
        ans.push_back(p.second);
    }

    return ans;
}


// Vertical Order Traversal Function
vector<int> verticalOrderTraversal(TreeNode<int>* root) {
    if (!root) return {}; // Handle empty tree case

    // Map: Horizontal distance -> (Level -> Nodes at that level)
    map<int, map<int, vector<int>>> Node; 

    // Queue for BFS: Each element stores a node and its coordinates
    queue<pair<TreeNode<int>*, pair<int, int>>> todo;  
    todo.push({root, {0, 0}}); // Start with root at (0, 0)

    while (!todo.empty()) {
        auto p = todo.front();
        todo.pop();

        TreeNode<int>* node = p.first;
        int horizontal_distance = p.second.first;
        int level = p.second.second;

        // Add the node's value to the corresponding vector in the map
        Node[horizontal_distance][level].push_back(node->data);

        // Add left child to queue with updated coordinates
        if (node->left) {
            todo.push({node->left, {horizontal_distance - 1, level + 1}});
        }

        // Add right child to queue with updated coordinates
        if (node->right) {
            todo.push({node->right, {horizontal_distance + 1, level + 1}});
        }
    }

    // Construct the result vector
    vector<int> ans;
    for (auto& p : Node) { // Iterate over horizontal distances
        for (auto& q : p.second) { // Iterate over levels
            ans.insert(ans.end(), q.second.begin(), q.second.end());
        }
    }

    return ans;
}

// Main Function
int main() {
    // Construct the example tree
    TreeNode<int>* root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
    root->right->left = new TreeNode<int>(6);
    root->right->right = new TreeNode<int>(7);

    // Perform vertical order traversal
    vector<int> result = verticalOrderTraversal(root);

    // Print the result
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    // Clean up memory
    delete root;

    return 0;
}

void solve(BinaryTreeNode<int>* root,vector<int>& result, int level){
    if(!root) return ;
    if( result.size()== level){
        result.push_back(root->data);
    }
    solve(root->left,result,level+1);
    solve(root->right,result,level+1);
}

vector<int> printLeftView(BinaryTreeNode<int>* root) {

    vector<int> ans;

    solve(root, ans, 0);

    return ans;

}