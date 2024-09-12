#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> charmap(26, 0);
        int retval = 0;

        for (char i : allowed) {
            charmap[i - 'a'] = 1;
        }

        for (string word : words) {
            bool valid = 1;

            for (char c : word) {
                if (charmap[c - 'a'] == 0) {
                    valid = 0;
                    break;
                }
            }

            if (valid) retval++;
        }

        return retval;
    }
};

int main() {
    Solution sol;
    string allowed = "ab";
    vector<string> words = {
        "ad", "bd", "aaab", "baa", "badab"
    };


    int res = sol.countConsistentStrings(allowed, words);

    cout << res << endl;

    return 0;
}