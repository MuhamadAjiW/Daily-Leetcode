#include <iostream>
#include <vector>
#include <unordered_map>

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
    // Original answer
    // vector<ListNode*> splitListToParts(ListNode* head, int k) {
    //     vector<ListNode*> retval(k);
    //     unordered_map<int, ListNode*> map;

    //     ListNode* pointer = head;
    //     int len = 0;
    //     while (pointer != nullptr)
    //     {
    //         map[len] = pointer;
    //         len++;
    //         pointer = pointer->next;
    //     }

    //     int div = len / k;
    //     int mod = len % k;
    //     int index = 0;

    //     for (int i = 0; i < k; i++)
    //     {
    //         if (index >= len) {
    //             continue;
    //         }
    //         retval[i] = map[index];

    //         if (mod != 0) {
    //             index += div;
    //             mod--;
    //         }
    //         else {
    //             index += div - 1;
    //         }
    //         map[index]->next = nullptr;

    //         index++;
    //     }

    //     return retval;
    // }

    // Better answer
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> retval(k);

        ListNode* pointer = head;
        int len = 0;

        while (pointer != nullptr)
        {
            len++;
            pointer = pointer->next;
        }

        int div = len / k;
        int mod = len % k;

        pointer = head;
        int index = 0;
        if (k < len) {
            while (pointer != nullptr) {
                retval[index] = pointer;
                int sublen = 1;
                while (sublen < div && pointer != nullptr) {
                    sublen++;
                    pointer = pointer->next;
                }

                if (mod > 0) {
                    mod--;
                    pointer = pointer->next;
                }

                if (pointer == nullptr) {
                    break;
                }

                ListNode* next = pointer->next;
                pointer->next = nullptr;
                pointer = next;
                index++;
            }
        }
        else {
            while (pointer != nullptr)
            {
                retval[index] = pointer;
                ListNode* next = pointer->next;
                pointer->next = nullptr;
                pointer = next;
                index++;
            }
        }

        return retval;
    }
};

int main() {
    Solution sol;
    ListNode head10(10);
    ListNode head9(9, &head10);
    ListNode head8(8, &head9);
    ListNode head7(7, &head8);
    ListNode head6(6, &head7);
    ListNode head5(5, &head6);
    ListNode head4(4, &head5);
    ListNode head3(3, &head4);
    ListNode head2(2, &head3);
    ListNode head(1, &head2);

    vector<ListNode*> res = sol.splitListToParts(&head, 11);

    for (auto l : res) {
        cout << "[";

        ListNode* pointer = l;
        while (pointer != nullptr)
        {
            cout << pointer->val << ",";
            pointer = pointer->next;
        }

        cout << "]\n";
    }

    return 0;
}