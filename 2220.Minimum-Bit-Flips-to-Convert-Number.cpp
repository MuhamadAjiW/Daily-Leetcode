#include <iostream>

using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        unsigned int flips = start ^ goal;
        int flip_count = 0;

        for (size_t i = 0; i < 31; i++)
        {
            flip_count += (flips & 1);
            flips >>= 1;
        }

        return flip_count;
    }
};

int main() {
    Solution sol;
    int start = 10;
    int goal = 3;

    int res = sol.minBitFlips(start, goal);

    cout << res << endl;


    return 0;
}