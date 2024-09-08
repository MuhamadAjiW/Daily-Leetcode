#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Slow answer
// int main() {
//     int n, x, y;
//     cin >> n;

//     for (size_t i = 0; i < n; i++) {
//         int t;
//         cin >> t;

//         vector<pair<int, int>> points(t);
//         for (size_t j = 0; j < t; j++) {
//             cin >> x >> y;
//             points[j] = { x, y };
//         }

//         int sum = 0;
//         for (size_t a = 0; a < t; a++) {
//             for (size_t b = a + 1; b < t; b++) {
//                 for (size_t c = b + 1; c < t; c++) {
//                     pair<int, int> p_a = points[a];
//                     pair<int, int> p_b = points[b];
//                     pair<int, int> p_c = points[c];

//                     int delta_x1 = p_b.first - p_a.first;
//                     int delta_y1 = p_b.second - p_a.second;

//                     int delta_x2 = p_c.first - p_a.first;
//                     int delta_y2 = p_c.second - p_a.second;

//                     if (delta_x1 * delta_x2 + delta_y1 * delta_y2 == 0) sum++;

//                     delta_x1 = p_a.first - p_b.first;
//                     delta_y1 = p_a.second - p_b.second;

//                     delta_x2 = p_c.first - p_b.first;
//                     delta_y2 = p_c.second - p_b.second;

//                     if (delta_x1 * delta_x2 + delta_y1 * delta_y2 == 0) sum++;

//                     delta_x1 = p_b.first - p_c.first;
//                     delta_y1 = p_b.second - p_c.second;

//                     delta_x2 = p_a.first - p_c.first;
//                     delta_y2 = p_a.second - p_c.second;

//                     if (delta_x1 * delta_x2 + delta_y1 * delta_y2 == 0) sum++;
//                 }
//             }
//         }

//         cout << sum << "\n";
//     }


//     return 0;
// }

// Still not fast enough
int main() {
    int n, x, y;
    cin >> n;

    for (size_t i = 0; i < n; i++) {
        int t;
        cin >> t;

        vector<pair<int, int>> points(t);
        for (size_t j = 0; j < t; j++) {
            cin >> x >> y;
            points[j] = { x, y };
        }

        vector<pair<int, int>> vectors;
        int sum = 0;
        for (size_t a = 0; a < t; a++) {
            for (size_t b = 0; b < t; b++) {
                if (a == b) continue;

                vectors.push_back({
                    points[b].first - points[a].first,
                    points[b].second - points[a].second
                    });
            }

            int len = vectors.size();
            for (size_t d1 = 0; d1 < len; d1++) {
                for (size_t d2 = d1 + 1; d2 < len; d2++) {
                    if (vectors[d1].first * vectors[d2].first + vectors[d1].second * vectors[d2].second == 0) sum++;
                }
            }

            vectors.clear();
        }


        cout << sum << "\n";
    }


    return 0;
}