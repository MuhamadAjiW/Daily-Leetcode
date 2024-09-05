#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {

        int sum = 0;
        int count = n + rolls.size();
        int total = mean * count;
        for (int i : rolls) {
            sum += i;
        }

        int delta = total - sum;
        if (total - sum  < 0
            || delta > n * 6
            || delta < n)return {};

        int div = delta / n;
        int mod = delta % n;

        vector<int> retval(n, div);
        for (int i = 0; i < mod; i++) {
            retval[i]++;
        }

        return retval;
    }
};

int main() {
    Solution sol;

    vector<int> rolls = {
        6, 3, 4, 3, 5, 3
    };
    int mean = 1;
    int n = 6;

    vector<int> result = sol.missingRolls(rolls, mean, n);

    for (int r : result) {
        cout << r << " ";
    }
    cout << endl;

    cout << "Done" << endl;

    return 0;
}