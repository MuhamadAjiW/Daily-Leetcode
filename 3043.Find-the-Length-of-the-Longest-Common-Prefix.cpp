#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int prefix = 0;
        unordered_set<int> arr1_set;

        for (int i : arr1) {
            int div = i;
            while (div != 0) {
                arr1_set.emplace(div);
                div /= 10;
            }
        }

        for (int i : arr2) {
            int div = i;
            while (div != 0) {
                if (arr1_set.find(div) != arr1_set.end()) {
                    prefix = max(prefix, div);
                    break;
                }
                div /= 10;
            }
        }

        int counter = 0;
        int div = prefix;
        while (div != 0) {
            div /= 10;
            counter++;
        }

        return counter;
    }
};

int main() {
    Solution sol;
    // vector<int> arr1 = { 1,10,100 };
    // vector<int> arr2 = { 1000 };
    vector<int> arr1 = { 1,10,100 };
    vector<int> arr2 = { 1000 };

    int res = sol.longestCommonPrefix(arr1, arr2);

    cout << res << endl;

    return 0;
}