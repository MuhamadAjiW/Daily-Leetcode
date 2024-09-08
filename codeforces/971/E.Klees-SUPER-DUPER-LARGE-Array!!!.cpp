#include <iostream>
#include <vector>

using namespace std;

// Not finished
int main() {
    int n;
    cin >> n;

    while (n--) {
        int i, n, k;
        cin >> n >> k;

        i = (n * n) + (2 * n * k) - (4 * k);

        cout << i << "\n";
    }


    return 0;
}
