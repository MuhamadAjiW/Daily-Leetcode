#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string retval = s;
        int converge = 0;
        int len = s.size();
        vector<int> map(len, 0);
        int i = 0; int j = 0;

        for (i = 1; i < len; i++) {
            if (s[i] != s[j]) {
                j = (s[i] == s[0]);
            }
            else {
                j++;
            }
            map[i] = j;
        }
        i = j = 0;

        // for (int m : map) {
        //     cout << m << " ";
        // }
        // cout << endl;

        reverse(retval.begin(), retval.end());

        // cout << retval << endl;
        // cout << s << endl;
        while (i < retval.size()) {
            // cout << i << " " << j << endl;
            if (retval[i] == s[j]) {
                i++;
                j++;
                continue;
            }
            else {
                // cout << "Not match at " << i << endl;
                if (j == 0) {
                    i++;
                }
                else {
                    j = j == 0 ? 0 : map[j - 1];
                }
                converge = i - j;
            }
        }
        cout << converge << endl;

        if (converge != 0) {
            retval = retval.substr(0, converge).append(s);
        }

        return retval;
    }
};

int main() {
    Solution sol;
    string s = "abcd";

    string res = sol.shortestPalindrome(s);

    cout << res << endl;

    return 0;
}