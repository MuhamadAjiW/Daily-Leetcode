#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> retval;
        unordered_map<string, int> map;
        istringstream stream(s1);
        string word;

        while (stream >> word) {
            map[word]++;
        }

        stream.clear();
        stream.str(s2);
        while (stream >> word) {
            map[word]++;
        }

        for (const auto& pair : map) {
            if (pair.second == 1) {
                retval.push_back(pair.first);
            }
        }

        return retval;
    }
};

int main() {
    Solution sol;
    string s1 = "this apple is sweet";
    string s2 = "this apple is sour";

    vector<string> res = sol.uncommonFromSentences(s1, s2);

    for (string word : res) {
        cout << word << endl;
    }

    return 0;
}