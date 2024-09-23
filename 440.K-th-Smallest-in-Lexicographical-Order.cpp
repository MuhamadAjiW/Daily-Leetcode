#include <iostream>

using namespace std;

// Not fast enough
class Solution {
public:
    int findKthNumber(int n, int k) {
        long long counter = 1;
        for (long long i = 1; i < k; i++) {
            if (counter * 10 > n) {
                if (counter == n) {
                    counter /= 10;
                }
                counter++;

                while (counter % 10 == 0) {
                    counter /= 10;
                }
            }
            else {
                counter *= 10;
            }
        }

        return counter;
    }
};

int main() {
    Solution sol;

    int res = sol.findKthNumber(719885387, 209989719);
    cout << res << endl;

    return 0;
}