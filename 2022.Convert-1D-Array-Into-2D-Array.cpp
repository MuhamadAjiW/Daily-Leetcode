#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int len = original.size();
        if (len != m * n) {
            return {};
        }
        vector<vector<int>> retval(m, vector<int>(n));

        int k = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                retval[i][j] = original[k++];
            }
        }

        return retval;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> res;
    vector<int> original = {
        1, 2, 3 };
    int m = 1;
    int n = 3;

    res = sol.construct2DArray(original, m, n);

    cout << "[" << endl;
    for (auto v : res) {
        cout << "[";
        for (auto i : v) {
            cout << i << ",";
        }
        cout << "]," << endl;
    }
    cout << "]" << endl;

    return 0;
}