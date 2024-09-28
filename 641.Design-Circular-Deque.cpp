#include <deque>
#include <iostream>

using namespace std;

class MyCircularDeque {
public:
    deque<int> deq;
    int size;

    MyCircularDeque(int k) {
        size = k;
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        deq.emplace_front(value);
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        deq.emplace_back(value);
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        deq.pop_front();
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        deq.pop_back();
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return deq.front();
    }

    int getRear() {
        if (isEmpty()) return -1;
        return deq.back();
    }

    bool isEmpty() {
        return deq.empty();
    }

    bool isFull() {
        return deq.size() == size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

int main() {
    MyCircularDeque* obj = new MyCircularDeque(3);

    cout << obj->insertLast(1) << endl;

    delete obj;
    return 0;
}