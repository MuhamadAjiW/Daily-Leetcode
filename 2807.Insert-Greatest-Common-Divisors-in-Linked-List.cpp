#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* pointer = head;
        ListNode* next = pointer->next;

        while (next != nullptr) {
            int gcd = __gcd(pointer->val, next->val);
            ListNode* n = new ListNode(gcd, next);
            pointer->next = n;

            pointer = next;
            next = next->next;
        }


        return head;
    }
};


int main() {
    Solution sol;
    ListNode* head4 = new ListNode(3);
    ListNode* head3 = new ListNode(10, head4);
    ListNode* head2 = new ListNode(6, head3);
    ListNode* head = new ListNode(18, head2);

    // ListNode* res = head;
    ListNode* res = sol.insertGreatestCommonDivisors(head);
    ListNode* cleanup = res;

    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
        delete cleanup;
        cleanup = res;
    }
    cout << endl;


    return 0;
}