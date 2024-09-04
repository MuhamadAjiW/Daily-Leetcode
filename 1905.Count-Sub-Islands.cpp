#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> directions = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vector<vector<int>> checkGrid(grid1.size(), vector<int>(grid1[0].size(), 0));
        stack<pair<int, int>> checkStack;

        int sum = 0;
        for (int row = 0; row < grid2.size(); row++) {
            for (int col = 0; col < grid2[0].size(); col++) {
                cout << "row: " << row << "; col: " << col << endl;
                if (!grid2[row][col] || checkGrid[row][col])
                    continue;

                checkGrid[row][col] = 1;
                checkStack.push({ row, col });

                vector<pair<int, int>> islands;
                while (!checkStack.empty()) {
                    pair<int, int> current = checkStack.top();
                    checkStack.pop();

                    checkGrid[current.first][current.second] = 1;
                    islands.push_back(current);

                    for (pair<int, int> dir : directions) {
                        pair<int, int> next = { current.first + dir.first, current.second + dir.second };
                        if (
                            next.first < 0 ||
                            next.first >= grid2.size() ||
                            next.second < 0 ||
                            next.second >= grid2[0].size() ||
                            checkGrid[next.first][next.second] ||
                            !grid2[next.first][next.second])
                        {
                            continue;
                        }
                        checkStack.push(next);
                    }
                }

                bool valid = 1;
                for (pair<int, int> p : islands) {
                    if (!grid1[p.first][p.second]) {
                        valid = 0;
                        break;
                    }
                }

                sum += valid;
            }
        }

        return sum;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid1 = {
        {1, 1, 1, 1, 0, 0},
        {1, 1, 0, 1, 0, 0},
        {1, 0, 0, 1, 1, 1},
        {1, 1, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 0},
        {1, 0, 1, 0, 1, 0},
        {0, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 1, 1},
        {1, 0, 0, 0, 1, 0},
        {1, 1, 1, 1, 1, 0} };
    vector<vector<int>> grid2 = {
        {1, 1, 1, 1, 0, 1},
        {0, 0, 1, 0, 1, 0},
        {1, 1, 1, 1, 1, 1},
        {0, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 1, 0},
        {0, 1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1, 1},
        {1, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0, 0} };
    // vector<vector<int>> grid1 = {
    //     {1, 0, 1, 0, 1},
    //     {1, 1, 1, 1, 1},
    //     {0, 0, 0, 0, 0},
    //     {1, 1, 1, 1, 1},
    //     {1, 0, 1, 0, 1},
    // };
    // vector<vector<int>> grid2 = {
    //     {0, 0, 0, 0, 0},
    //     {1, 1, 1, 1, 1},
    //     {0, 1, 0, 1, 0},
    //     {0, 1, 0, 1, 0},
    //     {1, 0, 0, 0, 1},
    // };
    // vector<vector<int>> grid1 = {
    //     {1, 1, 1, 0, 0},
    //     {0, 1, 1, 1, 1},
    //     {0, 0, 0, 0, 0},
    //     {1, 0, 0, 0, 0},
    //     {1, 1, 0, 1, 1},
    // };
    // vector<vector<int>> grid2 = {
    //     {1, 1, 1, 0, 0},
    //     {0, 0, 1, 1, 1},
    //     {0, 1, 0, 0, 0},
    //     {1, 0, 1, 1, 0},
    //     {0, 1, 0, 1, 0},
    // };
    int subIslands = sol.countSubIslands(grid1, grid2);

    std::cout << subIslands << endl;

    return 0;
}