#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int len = nums.size();
        vector<int> retval(len);
        vector<int> partial_sum(len);

        int sum = 0;
        for (size_t i = 0; i < len; i++) {
            sum += nums[i];
            partial_sum[i] = sum;
        }

        for (size_t i = 0; i < len; i++) {
            // cout << "---------" << endl;
            // cout << "num: " << nums[i] << endl;
            // cout << "partial sum: " << partial_sum[i] << endl;

            // int left = (i + 1) * nums[i] - partial_sum[i];
            // int right = sum - partial_sum[i] - (nums[i] * (len - 1 - i));
            // retval[i] = left + right;

            // Optimize the math equation
            retval[i] = sum - (nums[i] * (len - 2 - (i << 1))) - (partial_sum[i] << 1);

            // cout << "val: " << retval[i] << endl;
        }

        return retval;
    }
};

int main() {
    Solution sol;
    // vector<int> nums = { 2,3,5 };
    vector<int> nums = { 1,4,6,8,10 };

    vector<int> res = sol.getSumAbsoluteDifferences(nums);

    for (int i : res) {
        cout << i << " ";
    }


    return 0;
}