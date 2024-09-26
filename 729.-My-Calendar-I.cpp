#include <iostream>
#include <vector>

using namespace std;

class MyCalendar {
public:
    vector<pair<int, int>> schedules;
    MyCalendar() {}

    bool book(int start, int end) {
        int len = schedules.size();

        // Can be improved using binary search!
        int i = 0;
        // cout << "-----------------------------" << endl;
        // cout << start << " & " << end << endl;
        while (i < len) {
            pair<int, int> schedule = schedules[i];
            // cout << schedule.first << ":" << schedule.second << endl;
            if (start >= schedule.second) {
                // cout << start << ">=" << schedule.second << endl;
                i++;
                continue;
            }

            if (start < schedule.first && end <= schedule.first) {
                // cout << start << "<" << schedule.first << " & " << end << "<=" << schedule.first << " & " << endl;
                schedules.insert(schedules.begin() + i, { start, end });
                return true;
            }

            return false;
        }

        schedules.push_back({ start, end });
        return true;
    }

    void out() {
        for (auto i : schedules) {
            cout << "[" << i.first << " , " << i.second << "]";
        }
        cout << endl;
    }
};

int main() {
    MyCalendar* obj = new MyCalendar();
    // obj->book(47, 50);
    // obj->book(33, 41);
    // obj->book(39, 45);
    // obj->book(33, 42);
    // obj->book(25, 32);
    // obj->book(26, 35);
    // obj->book(19, 25);
    // obj->book(3, 8);
    // obj->book(8, 13);
    // obj->book(18, 27);

    cout << obj->book(10, 20) << endl;
    cout << obj->book(15, 25) << endl;
    cout << obj->book(20, 30) << endl;

    // obj->book(10, 20);
    // obj->book(15, 25);
    // obj->book(20, 30);
    obj->out();

    return 0;
}