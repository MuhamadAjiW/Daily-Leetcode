#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> retval;
        for (size_t i = 0; i < expression.size(); i++) {
            char c = expression[i];
            if (c == '+' || c == '-' | c == '*') {
                string left = expression.substr(0, i);
                string right = expression.substr(i + 1);
                vector<int> leftList = diffWaysToCompute(left);
                vector<int> rightList = diffWaysToCompute(right);

                for (int l : leftList) {
                    for (int r : rightList) {
                        switch (c) {
                        case '+':
                            retval.push_back(l + r);
                            break;
                        case '-':
                            retval.push_back(l - r);
                            break;
                        default:
                            retval.push_back(l * r);
                            break;
                        }
                    }
                }
            }
        }
        if (retval.size() == 0) retval.push_back(stoi(expression));

        return retval;
    }
};

int main() {
    Solution sol;
    // string expression = "2-1";
    string expression = "2*3-4*5";

    vector<int> res = sol.diffWaysToCompute(expression);

    for (int i : res) {
        cout << i << endl;
    }

    return 0;
}