#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> retval(n);

        int counter = 1;
        for (int i = 0; i < n; i++) {
            retval[i] = counter;

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

        return retval;
    }
};

int main() {
    Solution sol;

    // vector<int> res = sol.lexicalOrder(12345);
    vector<int> res = sol.lexicalOrder(111);

    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;


    return 0;
}