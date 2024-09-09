#include <iostream>
#include <vector>

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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> retval(m, vector<int>(n, -1));


        ListNode* pointer = head;

        int x = 0;
        int y = 0;
        int direction = 0;
        int limiter = 0;
        while (pointer != nullptr) {
            retval[y][x] = pointer->val;
            pointer = pointer->next;

            switch (direction) {
            case 0: if (x == n - limiter - 1) { direction = (direction + 1) & 3; } break;
            case 1: if (y == m - limiter - 1) { direction = (direction + 1) & 3; } break;
            case 2: if (x == limiter) { direction = (direction + 1) & 3; limiter++; } break;
            case 3: if (y == limiter) { direction = (direction + 1) & 3; } break;
            }

            switch (direction) {
            case 0: x++; break;
            case 1: y++; break;
            case 2: x--; break;
            case 3: y--; break;
            }
        }

        return retval;
    }
};

int main() {
    Solution sol;
    // int m = 3;
    // int n = 5;
    // ListNode head13(0);
    // ListNode head12(5, &head13);
    // ListNode head11(5, &head12);
    // ListNode head10(2, &head11);
    // ListNode head9(4, &head10);
    // ListNode head8(9, &head9);
    // ListNode head7(7, &head8);
    // ListNode head6(1, &head7);
    // ListNode head5(8, &head6);
    // ListNode head4(6, &head5);
    // ListNode head3(2, &head4);
    // ListNode head2(0, &head3);
    // ListNode head(3, &head2);
    int m = 4;
    int n = 5;
    ListNode head18(732);
    ListNode head17(909, &head18);
    ListNode head16(252, &head17);
    ListNode head15(224, &head16);
    ListNode head14(124, &head15);
    ListNode head13(12, &head14);
    ListNode head12(956, &head13);
    ListNode head11(734, &head12);
    ListNode head10(320, &head11);
    ListNode head9(474, &head10);
    ListNode head8(999, &head9);
    ListNode head7(868, &head8);
    ListNode head6(159, &head7);
    ListNode head5(20, &head6);
    ListNode head4(483, &head5);
    ListNode head3(528, &head4);
    ListNode head2(942, &head3);
    ListNode head(515, &head2);

    vector<vector<int>> res = sol.spiralMatrix(m, n, &head);

    cout << "[\n";
    for (auto v : res) {
        cout << "[";
        for (auto i : v) {
            cout << i << ",";
        }
        cout << "]\n";
    }
    cout << "]\n";


    return 0;
}