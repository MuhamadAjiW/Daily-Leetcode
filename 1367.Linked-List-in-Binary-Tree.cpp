#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool check(ListNode* head, TreeNode* root) {
        ListNode* next = head->next;
        if (next == nullptr) return true;

        bool left = false;
        bool right = false;
        if (root->left != nullptr && next->val == root->left->val) {
            left = check(next, root->left);
        }
        if (root->right != nullptr && next->val == root->right->val) {
            right = check(next, root->right);
        }

        return (left || right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if (head->val == root->val) {
            if (check(head, root)) return true;
        }

        if (root->left != nullptr && isSubPath(head, root->left)) return true;
        if (root->right != nullptr && isSubPath(head, root->right)) return true;

        return false;
    }
};

int main() {
    Solution sol;
    ListNode head3(8);
    ListNode head2(2, &head3);
    ListNode head(4, &head2);

    TreeNode root10(3);
    TreeNode root9(1);
    TreeNode root8(8, &root9, &root10);
    TreeNode root7(6);
    TreeNode root6(1);
    TreeNode root5(2, &root7, &root8);
    TreeNode root4(2, &root6, nullptr);
    TreeNode root3(4, &root5, nullptr);
    TreeNode root2(4, nullptr, &root4);
    TreeNode root(1, &root2, &root3);

    bool res = sol.isSubPath(&head, &root);

    cout << res << endl;

    return 0;
}