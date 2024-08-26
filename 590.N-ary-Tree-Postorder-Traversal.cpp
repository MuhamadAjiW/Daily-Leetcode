#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<int> postorder(Node *root)
    {
        vector<int> v;
        if (root == nullptr)
        {
            return v;
        }
        if (root->children.empty())
        {
            v.push_back(root->val);
            return v;
        }
        for (Node *n : root->children)
        {
            vector<int> l = postorder(n);
            v.insert(v.end(), l.begin(), l.end());
        }
        v.push_back(root->val);

        return v;
    }
};

int main()
{
    Node a(5);
    Node b(6);
    Node c(3, {&a, &b});
    Node d(2, {});
    Node e(4, {});
    Node f(1, {&c, &d, &e});

    Solution sol;
    vector<int> res = sol.postorder(&f);

    for (int i : res)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}