#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int sum(int num1, int num2) {
        return num1 + num2;
    }
};

int main() {
    Solution sol;

    int res = sol.sum(1, 1);

    cout << res << endl;

    return 0;
}