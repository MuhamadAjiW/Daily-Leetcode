#include <iostream>
#include <vector>
#include <unordered_set>

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> num_set;
        for (int i : nums) {
            num_set.insert(i);
        }

        ListNode* pointer = head;
        ListNode* pointer_tail = nullptr;
        while (pointer != nullptr) {
            if (num_set.find(pointer->val) != num_set.end()) {
                if (pointer_tail != nullptr) {
                    pointer_tail->next = pointer->next;
                }
                else {
                    *head = *pointer->next;
                    continue;
                }
            }
            else {
                pointer_tail = pointer;
            }

            pointer = pointer->next;
        }


        return head;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {
        1,3,4,5
    };
    ListNode head5(5);
    ListNode head4(4, &head5);
    ListNode head3(3, &head4);
    ListNode head2(2, &head3);
    ListNode head1(1, &head2);

    ListNode* result = sol.modifiedList(nums, &head1);

    ListNode* pointer = result;
    while (pointer != nullptr)
    {
        cout << pointer->val << " ";
        pointer = pointer->next;
    }
    cout << endl;


    return 0;
}