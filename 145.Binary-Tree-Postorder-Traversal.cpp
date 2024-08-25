#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> v;
        if (root == nullptr)
        {
            return v;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            v.push_back(root->val);
            return v;
        }
        if (root->left != nullptr)
        {
            vector<int> l = postorderTraversal(root->left);
            v.insert(v.end(), l.begin(), l.end());
        }
        if (root->right != nullptr)
        {
            vector<int> r = postorderTraversal(root->right);
            v.insert(v.end(), r.begin(), r.end());
        }
        v.push_back(root->val);

        return v;
    }
};

int main()
{
    TreeNode a(3);
    TreeNode b(2, &a, nullptr);
    TreeNode c(1, nullptr, &b);

    Solution sol;
    vector<int> res = sol.postorderTraversal(&c);

    for (int i : res)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}