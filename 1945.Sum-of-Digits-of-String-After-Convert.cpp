#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
    int getLucky(string s, int k)
    {
        stringstream stream;
        for (char c : s)
        {
            stream << c - 96;
        }

        int sum = 0;
        for (size_t i = 0; i < k; i++)
        {
            sum = 0;
            for (char c : stream.str())
            {
                sum += c - 48;
            }
            stream.str(to_string(sum));
        }

        return sum;
    }
};

int main()
{
    string s = "zbax";
    int k = 2;

    Solution sol;
    int result = sol.getLucky(s, k);

    cout << result << endl;

    return 0;
}