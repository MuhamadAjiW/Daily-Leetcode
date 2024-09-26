#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// class Solution {
// public:
//     vector<int> sumPrefixScores(vector<string>& words) {
//         int len = words.size();
//         vector<int> retval(len);
//         unordered_map<string, int> map;

//         for (string word : words){
//             for (size_t j = 1; j <= word.size(); j++){
//                 map[word.substr(0, j)]++;
//                 // cout << subw << endl;
//             }  
//         }


//         for (size_t i = 0; i < len; i++){
//             string word = words[i];
//             int score = 0;

//             for (size_t j = 1; j <= word.size(); j++){
//                 score += map[word.substr(0, j)];
//                 // cout << subw << endl;
//             }            
//             retval[i] = score;
//         }

//         return retval;
//     }
// };

class Trie {
public:
    int val;
    unordered_map<char, Trie> map;

    Trie() {
        this->val = 0;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int len = words.size();
        vector<int> retval(len);

        Trie root;
        for (string word : words) {
            Trie* tree = &root;
            for (size_t i = 0; i < word.size(); i++) {
                char c = word[i];
                tree = &(tree->map[c]);
                tree->val++;
            }
        }

        for (size_t i = 0; i < len; i++) {
            string word = words[i];
            Trie* tree = &root;
            int score = 0;
            for (size_t i = 0; i < word.size(); i++) {
                char c = word[i];
                tree = &(tree->map[c]);
                score += tree->val;
            }

            retval[i] = score;
        }

        return retval;
    }
};

int main() {
    Solution sol;
    vector<string> words = {
        "abc","ab","bc","b"
    };

    vector<int> res = sol.sumPrefixScores(words);

    for (int i : res) {
        cout << i << " ";
    }

    return 0;
}