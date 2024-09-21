#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        size_t retval = 0;
        size_t minlen = INT_MAX;
        size_t size = strs.size();
        for (string s : strs) {
            minlen = min(minlen, s.size());
        }
        char c;

        bool match = true;
        while (match && retval < minlen) {
            c = strs[0][retval];
            for (int i = 1; i < size; i++) {
                if (strs[i][retval] != c) {
                    match = false;
                    break;
                }
            }
            if (match) retval++;
        }

        return strs[0].substr(0, retval);
    }
};
int main() {
    Solution sol;
    vector<string> strs = {
        "flower",
        "flow",
        "flight"
    };


    string res = sol.longestCommonPrefix(strs);

    cout << res << endl;

    return 0;
}