#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int chalkReplacer(vector<int> &chalk, int k)
    {
        long long sum = 0;
        for (int i : chalk)
        {
            sum += i;
        }

        long long remainder = k % sum;

        long long i = 0;
        while (remainder >= 0)
        {
            remainder -= chalk[i];
            i++;
        }
        i--;

        return i;
    }
};

int main()
{
    vector<int> chalk = {3, 4, 1, 2};
    int k = 25;

    Solution sol;
    int res = sol.chalkReplacer(chalk, k);

    cout << res << endl;

    return 0;
}