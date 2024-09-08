#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x, y, k;
    cin >> n;

    for (size_t i = 0; i < n; i++) {
        cin >> x >> y >> k;
        int sum;

        int count_x = x / k;
        int mod_x = x % k;

        int count_y = y / k;
        int mod_y = y % k;

        if (mod_x > 0) count_x++;
        if (mod_y > 0) count_y++;

        int delta = abs(count_x - count_y);
        if (delta > 0 && count_y < count_x) delta--;

        cout << count_x + count_y + delta << "\n";
    }


    return 0;
}
