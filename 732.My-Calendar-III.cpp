#include <iostream>
#include <vector>

using namespace std;

class MyCalendarThree {
public:
    vector<vector<pair<int, int>>> schedules_array;
    MyCalendarThree() {}

    int book(int start, int end) {


        return true;
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

    delete obj;
    return 0;
}