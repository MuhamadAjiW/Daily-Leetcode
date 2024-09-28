#include <iostream>
#include <vector>

using namespace std;

// Original submission
// class MyCalendarTwo {
// public:
//     vector<pair<int, int>> schedules_array;
//     MyCalendarTwo() {}

//     bool book(int start, int end) {
//         vector<pair<int, int>> intersections_array;

//         cout << "----Checking----" << endl;
//         cout << start << ";" << end << endl;
//         for (auto schedule : schedules_array) {
//             if (start < schedule.second && end > schedule.first) {
//                 cout << "--Intersection--" << endl;
//                 cout << schedule.first << ";" << schedule.second << endl;
//                 pair<int, int> new_intersection = { max(schedule.first, start) , min(schedule.second, end) };
//                 cout << new_intersection.first << ";" << new_intersection.second << endl;
//                 for (auto intersection : intersections_array) {
//                     if (new_intersection.first < intersection.second && new_intersection.second > intersection.first) {
//                         return false;
//                     }
//                 }
//                 intersections_array.push_back(new_intersection);
//             }
//         }

//         schedules_array.push_back({ start, end });
//         return true;
//     }

//     void out() {
//         for (auto i : schedules_array) {
//             cout << "[" << i.first << " , " << i.second << "]";
//         }
//         cout << endl;
//     }
// };

// Fast
class MyCalendarTwo {
public:
    vector<pair<int, int>> schedules_array;
    vector<pair<int, int>> intersections_array;
    MyCalendarTwo() {}

    bool book(int start, int end) {
        for (auto intersection : intersections_array) {
            if (start < intersection.second && end > intersection.first) {
                return false;
            }
        }
        for (auto schedule : schedules_array) {
            if (start < schedule.second && end > schedule.first) {
                intersections_array.push_back({ max(schedule.first, start), min(schedule.second, end) });
            }
        }
        schedules_array.push_back({ start, end });

        return true;
    }

    void out() {
        for (auto i : schedules_array) {
            cout << "[" << i.first << " , " << i.second << "]";
        }
        cout << endl;
    }
};

int main() {
    MyCalendarTwo* obj = new MyCalendarTwo();
    // cout << obj->book(10, 20) << endl;
    // cout << obj->book(50, 60) << endl;
    // cout << obj->book(10, 40) << endl;
    // cout << obj->book(5, 15) << endl;
    // cout << obj->book(5, 10) << endl;
    // cout << obj->book(25, 55) << endl;

    cout << obj->book(26, 35) << endl;
    cout << obj->book(26, 32) << endl;
    cout << obj->book(25, 32) << endl;
    cout << obj->book(18, 26) << endl;
    cout << obj->book(40, 45) << endl;
    cout << obj->book(19, 26) << endl;

    obj->out();

    delete obj;
    return 0;
}