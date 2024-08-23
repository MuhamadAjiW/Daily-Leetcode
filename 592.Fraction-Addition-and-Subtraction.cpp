#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // Original answer
    // string fractionAddition(string expression)
    // {
    //     long long ten_fac = 3628800;
    //     long long len = expression.length();
    //     long long num = 1;
    //     long long denum = 1;
    //     long long index = 0;
    //     long long sum = 0;
    //     stringstream output_str;

    //     if (expression[index] == '-')
    //     {
    //         index++;
    //         num = -1;
    //     }

    //     num *= expression[index] - 48;
    //     index++;
    //     if (expression[index] == 48)
    //     {
    //         num *= 10;
    //         index++;
    //     }
    //     index++;

    //     denum *= expression[index] - 48;
    //     index++;
    //     if (expression[index] == 48)
    //     {
    //         denum *= 10;
    //         index++;
    //     }

    //     sum += ten_fac / denum * num;

    //     while (index < len)
    //     {
    //         num = 1;
    //         denum = 1;

    //         if (expression[index] == '-')
    //         {
    //             num = -1;
    //         }
    //         index++;

    //         num *= expression[index] - 48;
    //         index++;
    //         if (expression[index] == 48)
    //         {
    //             num *= 10;
    //             index++;
    //         }
    //         index++;

    //         denum *= expression[index] - 48;
    //         index++;
    //         if (expression[index] == 48)
    //         {
    //             denum *= 10;
    //             index++;
    //         }

    //         sum += ten_fac / denum * num;
    //     }

    //     num = sum;
    //     denum = ten_fac;
    //     for (int i = 0; i < 8; i++)
    //     {
    //         if (num % 2 == 0 && denum % 2 == 0)
    //         {
    //             num /= 2;
    //             denum /= 2;
    //         }
    //         else
    //             break;
    //     }
    //     for (int i = 0; i < 4; i++)
    //     {
    //         if (num % 3 == 0 && denum % 3 == 0)
    //         {
    //             num /= 3;
    //             denum /= 3;
    //         }
    //         else
    //             break;
    //     }
    //     for (int i = 0; i < 2; i++)
    //     {
    //         if (num % 5 == 0 && denum % 5 == 0)
    //         {
    //             num /= 5;
    //             denum /= 5;
    //         }
    //         else
    //             break;
    //     }
    //     for (int i = 0; i < 1; i++)
    //     {
    //         if (num % 7 == 0 && denum % 7 == 0)
    //         {
    //             num /= 7;
    //             denum /= 7;
    //         }
    //         else
    //             break;
    //     }
    //     __gcd(abs(1), abs(2));

    //     output_str << num << '/' << denum;
    //     return output_str.str();
    // }

    // Fast answer
    string fractionAddition(string expression)
    {
        stringstream ss(expression);
        char op;
        int a, b, c, d;
        int num, denum;
        ss >> a;
        ss >> op;
        ss >> b;

        while (ss >> c)
        {
            ss >> op;
            ss >> d;
            num = a * d + b * c;
            denum = b * d;

            a = num / __gcd(abs(num), abs(denum));
            b = denum / __gcd(abs(num), abs(denum));
        }
        c = __gcd(abs(a), abs(b));
        a = a / c;
        b = b / c;

        return to_string(a) + '/' + to_string(b);
    }
};

int main()
{
    string input;
    cin >> input;

    Solution solution;
    cout << solution.fractionAddition(input) << endl;

    return 0;
}