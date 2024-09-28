#include <iostream>
#include <vector>
#include <set>

using namespace std;

class MyCalendarThree {
public:
    vector<set<pair<int, int>>> schedules_array = { {} };
    int last = 0;
    int max_schedule = 0;

    MyCalendarThree() {}

    int book(int start, int end) {
        int counter = last;
        int retval = 0;

        while (retval == 0 && counter >= 0) {
            for (auto schedule : schedules_array[counter]) {
                if (start < schedule.second && end > schedule.first) {
                    retval = counter + 2;
                    if (retval > last) {
                        schedules_array.push_back({});
                        last = retval - 1;

                        // cout << "Expanding array: " << retval << endl;
                        // cout << "Expanding array: " << counter << endl;
                    }

                    for (int i = counter; i >= 0; i--) {
                        for (auto intersect : schedules_array[i]) {
                            if (start < intersect.second && end > intersect.first) {
                                schedules_array[i + 1].insert({ max(start, intersect.first), min(end, intersect.second) });
                            }
                        }
                    }
                    schedules_array[0].insert({ start, end });

                    break;
                }
            }
            counter--;
        }

        if (retval == 0) {
            // cout << "Empty schedule" << endl;
            retval = 1;
            schedules_array[0].insert({ start, end });
        }

        max_schedule = max(retval, max_schedule);

        // out();
        return max_schedule;
    }

    void out() {
        for (auto schedules : schedules_array) {
            for (auto schedule : schedules) {
                cout << "[" << schedule.first << " , " << schedule.second << "]";
            }
            cout << endl;
        }
    }
};

int main() {
    MyCalendarThree* obj = new MyCalendarThree();
    // cout << obj->book(10, 20) << endl;
    // cout << obj->book(50, 60) << endl;
    // cout << obj->book(10, 40) << endl;
    // cout << obj->book(5, 15) << endl;
    // cout << obj->book(5, 10) << endl;
    // cout << obj->book(25, 55) << endl;

    cout << obj->book(10, 20) << endl;
    cout << obj->book(50, 60) << endl;
    cout << obj->book(10, 40) << endl;
    cout << obj->book(5, 15) << endl;
    cout << obj->book(5, 10) << endl;
    cout << obj->book(25, 55) << endl;

    obj->out();

    delete obj;
    return 0;
}