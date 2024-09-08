#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, size;
    cin >> n;

    for (size_t i = 0; i < n; i++) {
        cin >> size;
        string str;
        vector<int> output(size);

        for (size_t j = 0; j < size; j++) {
            cin >> str;
            output[size - 1 - j] = str.find('#');
        }

        for (size_t j = 0; j < size; j++) {
            cout << output[j] + 1;
            if (j != size - 1) {
                cout << " ";
            }
            else {
                cout << "\n";
            }
        }
    }

    return 0;
}