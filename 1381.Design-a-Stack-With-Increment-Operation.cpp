#include <iostream>
#include <vector>

using namespace std;

class CustomStack {
public:
    // Original answer
    // vector<int> v_stack;
    // int size = 0;
    // int c_size = 0;

    // CustomStack(int maxSize) {
    //     size = maxSize;
    // }

    // void push(int x) {
    //     if (c_size < size) {
    //         v_stack.push_back(x);
    //         c_size++;
    //     }
    // }

    // int pop() {
    //     if (c_size > 0) {
    //         int last = v_stack.back();
    //         v_stack.pop_back();
    //         c_size--;
    //         return last;
    //     }

    //     return -1;
    // }

    // void increment(int k, int val) {
    //     for (size_t i = 0; i < min(c_size, k); i++) {
    //         v_stack[i] += val;
    //     }
    // }

    // Optimized
    int v_stack[750];
    int size = 0;
    int c_size = 0;

    CustomStack(int maxSize) {
        size = maxSize;
    }

    void push(int x) {
        if (c_size < size) {
            v_stack[c_size] = x;
            c_size++;
        }
    }

    int pop() {
        if (c_size > 0) {
            c_size--;
            return v_stack[c_size];
        }

        return -1;
    }

    void increment(int k, int val) {
        for (size_t i = 0; i < min(c_size, k); i++) {
            v_stack[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

int main() {
    CustomStack* obj = new CustomStack(2);
    obj->push(34);
    obj->pop();
    obj->increment(8, 100);
    obj->pop();
    obj->increment(9, 91);
    obj->push(63);
    obj->pop();
    obj->push(84);
    obj->increment(10, 93);
    obj->increment(6, 45);
    obj->increment(10, 4);

    return 0;
}