#include <bits/stdc++.h>
using namespace std;

// ==================== Binary Tree Node ====================
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}

    ~TreeNode()
    {
        delete left;
        delete right;
    }
};

// ==================== Top View ====================
vector<int> getTopView(TreeNode<int> *root)
{
    if (!root)
        return {};

    map<int, int> topNode; // horizontal distance -> node value
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        TreeNode<int> *node = temp.first;
        int hd = temp.second;
        // first node at this horizontal distance
        if (topNode.find(hd) == topNode.end())
            topNode[hd] = node->data;

        if (node->left)
            q.push({node->left, hd - 1});
        if (node->right)
            q.push({node->right, hd + 1});
    }

    vector<int> ans;
    for (auto &p : topNode)
        ans.push_back(p.second);

    return ans;
}

// ==================== Vertical Order Traversal ====================
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    if (!root)
        return {};

    // hd -> (level -> list of nodes)
    map<int, map<int, vector<int>>> nodes;
    queue<pair<TreeNode<int> *, pair<int, int>>> q;
    q.push({root, {0, 0}}); // hd=0, level=0

    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        TreeNode<int> *node = temp.first;
        int hd = temp.second.first;
        int level = temp.second.second;

        nodes[hd][level].push_back(node->data);

        if (node->left)
            q.push({node->left, {hd - 1, level + 1}});
        if (node->right)
            q.push({node->right, {hd + 1, level + 1}});
    }

    vector<int> ans;
    for (auto &p : nodes)
        for (auto &q : p.second)
            ans.insert(ans.end(), q.second.begin(), q.second.end());

    return ans;
}

// ==================== Left View ====================
template <typename T>
void leftViewHelper(TreeNode<T> *root, vector<int> &result, int level)
{
    if (!root)
        return;

    if (result.size() == level)
        result.push_back(root->data);

    leftViewHelper(root->left, result, level + 1);
    leftViewHelper(root->right, result, level + 1);
}

vector<int> printLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    leftViewHelper(root, ans, 0);
    return ans;
}

// ==================== Main ====================
int main()
{
    /* Example Tree:
             1
            / \
           2   3
          / \  / \
         4  5 6   7
    */
    TreeNode<int> *root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
    root->right->left = new TreeNode<int>(6);
    root->right->right = new TreeNode<int>(7);

    // Vertical order
    vector<int> vertical = verticalOrderTraversal(root);
    cout << "Vertical Order Traversal: ";
    for (int x : vertical)
        cout << x << " ";
    cout << "\n";

    // Top view
    vector<int> top = getTopView(root);
    cout << "Top View: ";
    for (int x : top)
        cout << x << " ";
    cout << "\n";

    // Left view
    vector<int> leftView = printLeftView(root);
    cout << "Left View: ";
    for (int x : leftView)
        cout << x << " ";
    cout << "\n";

    delete root;
    return 0;
}
