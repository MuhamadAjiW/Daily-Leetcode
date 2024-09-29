#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class AllOne {
public:
    unordered_map<string, int> strmap;
    unordered_map<int, unordered_set<string>> valmap;
    int min_val = 0;
    int max_val = 0;

    AllOne() {}

    void inc(string key) {
        int prev = strmap[key];
        if (prev != 0) valmap[prev].erase(key);
        if (prev == min_val) {
            if (valmap[prev].empty()) {
                min_val++;
            }
        }

        int val = ++strmap[key];
        valmap[val].insert(key);
        max_val = max(val, max_val);
        min_val = min(val, min_val);
    }

    void dec(string key) {
        int prev = strmap[key];
        if (prev != 0) valmap[prev].erase(key);
        if (prev == min_val) {
            if (valmap[prev].empty()) {
                min_val--;
            }

            if (min_val == 0 && max_val != 1) {
                int i = 2;
                while (valmap[i].empty()) {
                    i++;
                }
                min_val = i;
            }
        }
        if (prev == max_val) {
            if (valmap[prev].empty()) {
                max_val--;
            }
        }

        int val = --strmap[key];
        if (val != 0) valmap[val].insert(key);
    }

    string getMaxKey() {
        if (!max_val) return "";
        return *valmap[max_val].begin();
    }

    string getMinKey() {
        if (!min_val) return "";
        return *valmap[min_val].begin();
    }

    void out() {
        cout << "min: " << min_val << " -> " << getMinKey() << endl;
        cout << "max: " << max_val << " -> " << getMaxKey() << endl;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

int main() {
    AllOne* obj = new AllOne;

    cout << obj->getMaxKey() << endl;
    cout << obj->getMinKey() << endl;
    obj->inc("hello");
    obj->inc("hello");
    cout << obj->getMaxKey() << endl;
    cout << obj->getMinKey() << endl;
    obj->inc("leet");
    obj->inc("leet");
    obj->inc("leet");
    obj->inc("leet");
    obj->inc("hello");
    obj->dec("hello");
    obj->dec("hello");
    obj->dec("hello");
    obj->dec("leet");
    obj->dec("leet");
    obj->dec("leet");
    obj->dec("leet");

    obj->out();
    cout << obj->getMaxKey() << endl;
    cout << obj->getMinKey() << endl;

    delete obj;
    return 0;
}