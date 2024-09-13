#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int size = queries.size();
        vector<int> retval(size);
        for (size_t i = 0; i < size; i++) {
            int a, b, val;
            a = queries[i][0];
            b = queries[i][1];
            val = arr[a];

            for (size_t j = a + 1; j <= b; j++)
            {
                val ^= arr[j];
            }
            retval[i] = val;
        }

        return retval;
    }
};

int main() {
    Solution sol;
    // vector<int> arr = {
    //     1,3,4,8
    // };
    // vector<vector<int>> queries = {
    //     {0,1},
    //     {1,2},
    //     {0,3},
    //     {3,3}
    // };
    vector<int> arr = {
        4,8,2,10
    };
    vector<vector<int>> queries = {
        {2,3},
        {1,3},
        {0,0},
        {0,3}
    };


    vector<int> res = sol.xorQueries(arr, queries);

    for (int i : res) {
        cout << i << " ";
    }

    return 0;
}