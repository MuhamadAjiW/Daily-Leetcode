#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minute_array;

        for (auto time : timePoints) {
            int minute_time = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
            minute_array.push_back(minute_time);
        }
        sort(minute_array.begin(), minute_array.end());
        int len = minute_array.size();

        int retval = abs(minute_array[len - 1] - (minute_array[0] + 24 * 60));
        for (size_t i = 0; i < len - 1; i++) {
            retval = min(retval, minute_array[i + 1] - minute_array[i]);
        }


        return retval;
    }
};

int main() {
    Solution sol;
    vector<string> timePoints = {
        "00:00",
        "23:59",
        "00:00"
    };
    int res = sol.findMinDifference(timePoints);

    cout << res << endl;

    return 0;
}