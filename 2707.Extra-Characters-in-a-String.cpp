#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int len = s.size();
        unordered_set<string> set(dictionary.begin(), dictionary.end());
        int sub_result[len + 1];
        sub_result[len] = 0;

        for (int i = len - 1; i >= 0; --i) {
            sub_result[i] = sub_result[i + 1] + 1;

            for (size_t j = i; j < len; ++j) {
                string check = s.substr(i, j - i + 1);
                // cout << "Checking: " << check << endl;
                if (set.find(check) != set.end()) {
                    // cout << "Found! " << check << endl;
                    sub_result[i] = min(sub_result[i], sub_result[j + 1]);
                    break;
                }
            }
        }

        return sub_result[0];
    }
};

int main() {
    Solution sol;
    // string s = "leetscode";5
    // vector<string> dictionary = { "leet", "code", "leetcode" };
    string s = "dwmodizxvvbosxxw";
    vector<string> dictionary = { "ox","lb","diz","gu","v","ksv","o","nuq","r","txhe","e","wmo","cehy","tskz","ds","kzbu" };

    int res = sol.minExtraChar(s, dictionary);

    cout << res << endl;

    return 0;
}