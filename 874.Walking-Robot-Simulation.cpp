#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

enum Direction {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

class Solution {
private:
    long long encode(int x, int y) {
        return (((long long)x << 32) | (y & 0xffffffff));
    }

public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        Direction direction = NORTH;
        pair<int, int> location = { 0, 0 };
        unordered_set<long long> obstacle_set;
        int distance = 0;

        for (vector<int> obs : obstacles) {
            obstacle_set.insert(encode(obs[0], obs[1]));
        }

        for (int comm : commands) {
            cout << "-----" << endl;
            cout << "Start Location: " << location.first << "," << location.second << endl;
            cout << "Direction: " << direction << endl;
            cout << "Directive: " << comm << endl;
            switch (comm) {
            case -2:
                switch (direction) {
                case NORTH: direction = WEST; break;
                case EAST: direction = NORTH; break;
                case SOUTH: direction = EAST; break;
                case WEST: direction = SOUTH; break;
                }

                break;
            case -1:
                switch (direction) {
                case NORTH: direction = EAST; break;
                case EAST: direction = SOUTH; break;
                case SOUTH: direction = WEST; break;
                case WEST: direction = NORTH; break;
                }
                break;

            default:
                int i;
                switch (direction) {
                case NORTH:
                    for (i = location.second + 1; i <= location.second + comm; i++) {
                        if (obstacle_set.find(encode(location.first, i)) != obstacle_set.end()) {
                            break;
                        }
                    }
                    i--;
                    location.second = i;
                    break;
                case EAST:
                    for (i = location.first + 1; i <= location.first + comm; i++) {
                        if (obstacle_set.find(encode(i, location.second)) != obstacle_set.end()) {
                            break;
                        }
                    }
                    i--;
                    location.first = i;
                    break;
                case SOUTH:
                    for (i = location.second - 1; i >= location.second - comm; i--) {
                        if (obstacle_set.find(encode(location.first, i)) != obstacle_set.end()) {
                            cout << "break!!" << endl;
                            break;
                        }
                    }
                    i++;
                    location.second = i;
                    break;
                case WEST:
                    for (i = location.first - 1; i >= location.first - comm; i--) {
                        if (obstacle_set.find(encode(i, location.second)) != obstacle_set.end()) {
                            break;
                        }
                    }
                    i++;
                    location.first = i;
                    break;
                }

                int new_distance = (location.first * location.first + location.second * location.second);
                if (new_distance > distance) {
                    distance = new_distance;
                }
                break;
            }
            cout << "Final Location: " << location.first << "," << location.second << endl;
            cout << "-----" << endl;
        }

        return distance;
    }
};

int main() {
    vector<int> commands = {
        2,-1,8,-1,6
    };
    vector<vector<int>> obstacles = {
{1,5},
{-5,-5},
{0,4},
{-1,-1},
{4,5},
{-5,-3},
{-2,1},
{-2,-5},
{0,5},
{0,-1}
    };

    Solution sol;

    cout << sol.robotSim(commands, obstacles) << endl;

    return 0;
}