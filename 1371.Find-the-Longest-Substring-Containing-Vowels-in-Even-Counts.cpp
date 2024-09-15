#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int a = 1;
        int i = 2;
        int u = 4;
        int e = 8;
        int o = 16;
        int map[32];
        fill(map, map + 32, -999);
        map[0] = -1;

        int longest = 0;
        int bitmask = 0;

        for (int index = 0; index < s.length(); index++) {
            char c = s[index];
            switch (c) {
            case 'a': bitmask ^= a; break;
            case 'i': bitmask ^= i; break;
            case 'u': bitmask ^= u; break;
            case 'e': bitmask ^= e; break;
            case 'o': bitmask ^= o; break;
            }

            // cout << bitmask << endl;
            // cout << "Assigned: " << map[bitmask] << endl;
            if (map[bitmask] != -999) {
                longest = max(longest, index - map[bitmask]);
                // cout << "longest: " << longest << endl;
            }
            else {
                map[bitmask] = index;
            }
        }

        return longest;
    }
};

int main() {
    Solution sol;
    // string s = "eleetminicoworoep";
    string s = "leetcodeisgreat";
    // string s = "lllllllllle";

    int res = sol.findTheLongestSubstring(s);

    cout << res << endl;

    return 0;
}