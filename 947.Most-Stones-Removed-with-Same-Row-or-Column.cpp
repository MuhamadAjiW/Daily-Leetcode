#include <vector>
#include <map>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int removeStones(vector<vector<int>> &stones)
    {
        int sum = 0;
        map<int, vector<int>> hashmap_row;
        map<int, vector<int>> hashmap_col;

        for (auto stone : stones)
        {
            hashmap_row[stone[0]].push_back(stone[1]);
            hashmap_col[stone[1]].push_back(stone[0]);
        }

        map<pair<int, int>, int> hashmap_check;
        for (auto stone : stones)
        {
            pair<int, int> root = {stone[0], stone[1]};
            if (hashmap_check[root])
                continue;

            int local_sum = -1;
            stack<pair<int, int>> stack_check;
            stack_check.push(root);

            while (!stack_check.empty())
            {
                pair<int, int> dfs = stack_check.top();
                if (hashmap_check[dfs])
                {
                    stack_check.pop();
                    continue;
                }

                stack_check.pop();
                hashmap_check[dfs]++;
                local_sum++;

                int dfs_row = dfs.first;
                int dfs_col = dfs.second;

                for (auto col : hashmap_row[dfs_row])
                {
                    pair<int, int> dfs_next = {dfs_row, col};
                    if (hashmap_check[dfs_next])
                        continue;

                    stack_check.push(dfs_next);
                }
                for (auto row : hashmap_col[dfs_col])
                {
                    pair<int, int> dfs_next = {row, dfs_col};
                    if (hashmap_check[dfs_next])
                        continue;

                    stack_check.push(dfs_next);
                }
            }

            sum += local_sum;
        }

        return sum;
    }
};

int main()
{
    Solution sol;
    // vector<vector<int>> stones = {
    //     {0, 0},
    //     {0, 1},
    //     {1, 0},
    //     {1, 2},
    //     {2, 1},
    //     {2, 2},
    // };
    // vector<vector<int>> stones = {
    //     {0, 0},
    //     {0, 2},
    //     {1, 1},
    //     {2, 0},
    //     {2, 2},
    // };
    // vector<vector<int>> stones = {
    //     {0, 1},
    //     {1, 0},
    //     {1, 1},
    // };
    // vector<vector<int>> stones = {
    //     {0, 0},
    //     {0, 1},
    //     {1, 0},
    //     {1, 1},
    //     {2, 1},
    //     {2, 2},
    //     {3, 2},
    //     {3, 3},
    //     {3, 4},
    //     {4, 3},
    //     {4, 4}};
    vector<vector<int>> stones = {
        {0, 0},
        {0, 1},
        {4, 3},
        {4, 4}};

    int retval = sol.removeStones(stones);

    std::cout << retval << endl;

    return 0;
}