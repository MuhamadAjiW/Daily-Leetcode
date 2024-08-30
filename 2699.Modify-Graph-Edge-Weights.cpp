#include <vector>
#include <set>
#include <map>
#include <stack>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
// I sought help for this one
// Algorithm should've been done but performance still not good enough :(
// At least I've learnt something for today
// Better fuck up now than during an interview, I suppose

// class Solution
// {
// public:
//     vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges, int source, int destination, int target)
//     {
//         vector<vector<int>> result;
//         map<int, vector<int>> node_map;
//         map<pair<int, int>, int> price_map;
//         vector<pair<vector<int>, int>> paths;
//         vector<int> path;
//         int path_variable = INT_MAX;
//         int path_final = 0;
//         int min = INT_MIN;

//         for (auto edge : edges)
//         {
//             node_map[edge[0]].push_back(edge[1]);
//             node_map[edge[1]].push_back(edge[0]);

//             if (edge[0] > edge[1])
//             {
//                 price_map[{edge[0], edge[1]}] = edge[2];
//             }
//             else
//             {
//                 price_map[{edge[1], edge[0]}] = edge[2];
//             }
//         }

//         vector<vector<int>> node_stack;
//         node_stack.push_back({source});

//         // int i = 2;
//         while (!node_stack.empty())
//         // while (i-- > 0)
//         {
//             vector<int> current_path = node_stack.back();
//             int current_node = current_path.back();
//             node_stack.pop_back();

//             if (current_node == destination)
//             {
//                 cout << "---------" << endl;
//                 cout << "Destination found!: [";
//                 for (auto i : current_path)
//                 {
//                     cout << i << ",";
//                 }
//                 cout << "]" << endl;
//                 int limit = current_path.size() - 1;
//                 int target_calc = target;
//                 int variable = 0;

//                 for (int i = 0; i < limit; ++i)
//                 {
//                     pair<int, int> pair;
//                     if (current_path[i] > current_path[i + 1])
//                         pair = {current_path[i], current_path[i + 1]};
//                     else
//                         pair = {current_path[i + 1], current_path[i]};

//                     int price = price_map[pair];
//                     if (price < 0)
//                     {
//                         variable++;
//                         target_calc -= 1;
//                     }
//                     else
//                     {
//                         target_calc -= price;
//                     }
//                     cout << "Price: " << price << endl;
//                 }

//                 cout << "Target: " << target << endl;
//                 cout << "Target calc: " << target_calc << endl;
//                 cout << "Var count: " << variable << endl;
//                 cout << "---------" << endl;

//                 if (target_calc > 0 && variable == 0)
//                 {
//                     return result;
//                 }

//                 if ((target_calc >= 0 && variable > 0) || (target_calc == 0 && variable == 0))
//                 {
//                     if (variable < path_variable)
//                     {
//                         min = target_calc;
//                         path = current_path;
//                         path_variable = variable;
//                         path_final = target_calc;
//                     }
//                     else if (variable == path_variable && target_calc > min)
//                     {
//                         min = target_calc;
//                         path = current_path;
//                         path_variable = variable;
//                         path_final = target_calc;
//                     }
//                     paths.push_back({current_path, target_calc});
//                 }
//             }

//             for (auto node : node_map[current_node])
//             {
//                 if (find(current_path.begin(), current_path.end(), node) == current_path.end())
//                 {
//                     vector<int> new_path = current_path;
//                     new_path.push_back(node);
//                     node_stack.push_back(new_path);
//                 }
//             }
//         }

//         if (path.empty())
//         {
//             return result;
//         }

//         cout << "Shortest path: [";
//         for (auto i : path)
//         {
//             cout << i << ",";
//         }
//         cout << "]" << endl;

//         int limit = path.size() - 1;
//         int target_calc = target;

//         for (int i = 0; i < limit; ++i)
//         {
//             pair<int, int> pair;
//             if (path[i] > path[i + 1])
//                 pair = {path[i], path[i + 1]};
//             else
//                 pair = {path[i + 1], path[i]};

//             int price = price_map[pair];
//             if (price < 0)
//             {
//                 if (path_variable == 1)
//                 {
//                     price_map[pair] = 1 + path_final;
//                 }
//                 else
//                 {
//                     price_map[pair] = 1;
//                 }
//                 path_variable--;
//             }
//         }

//         for (auto v : edges)
//         {
//             pair<int, int> pair;
//             if (v[0] > v[1])
//                 pair = {v[0], v[1]};
//             else
//                 pair = {v[1], v[0]};

//             if (v[2] < 0)
//             {
//                 if (price_map[pair] < 0)
//                 {
//                     result.push_back({v[0], v[1], target});
//                 }
//                 else
//                 {
//                     result.push_back({v[0], v[1], price_map[pair]});
//                 }
//             }
//             else
//             {
//                 result.push_back({v[0], v[1], v[2]});
//             }
//         }

//         return result;
//     }
// };

class Solution
{
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges, int source, int destination, int target)
    {
        vector<vector<pair<int, int>>> adjacencyList(n);
        for (int i = 0; i < edges.size(); i++)
        {
            int nodeA = edges[i][0], nodeB = edges[i][1];
            adjacencyList[nodeA].emplace_back(nodeB, i);
            adjacencyList[nodeB].emplace_back(nodeA, i);
        }

        vector<vector<int>> distances(n, vector<int>(2, INT_MAX));
        distances[source][0] = distances[source][1] = 0;

        runDijkstra(adjacencyList, edges, distances, source, 0, 0);
        int difference = target - distances[destination][0];
        if (difference < 0)
            return {};
        runDijkstra(adjacencyList, edges, distances, source, difference, 1);
        if (distances[destination][1] < target)
            return {};

        for (auto &edge : edges)
        {
            if (edge[2] == -1)
                edge[2] = 1;
        }
        return edges;
    }

private:
    void runDijkstra(const vector<vector<pair<int, int>>> &adjacencyList, vector<vector<int>> &edges, vector<vector<int>> &distances, int source, int difference, int run)
    {
        int n = adjacencyList.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> priorityQueue;
        priorityQueue.push({0, source});
        distances[source][run] = 0;

        while (!priorityQueue.empty())
        {
            auto [currentDistance, currentNode] = priorityQueue.top();
            priorityQueue.pop();

            if (currentDistance > distances[currentNode][run])
                continue;

            for (auto &neighbor : adjacencyList[currentNode])
            {
                int nextNode = neighbor.first, edgeIndex = neighbor.second;
                int weight = edges[edgeIndex][2];

                if (weight == -1)
                    weight = 1;

                if (run == 1 && edges[edgeIndex][2] == -1)
                {
                    int newWeight = difference + distances[nextNode][0] - distances[currentNode][1];
                    if (newWeight > weight)
                    {
                        edges[edgeIndex][2] = weight = newWeight;
                    }
                }

                if (distances[nextNode][run] > distances[currentNode][run] + weight)
                {
                    distances[nextNode][run] = distances[currentNode][run] + weight;
                    priorityQueue.push({distances[nextNode][run], nextNode});
                }
            }
        }
    }
};

int main()
{
    int n = 5;
    vector<vector<int>> edges = {
        {4, 1, -1},
        {2, 0, -1},
        {0, 3, -1},
        {4, 3, -1}};
    int source = 0;
    int destination = 1;
    int target = 5;

    // int n = 13;
    // vector<vector<int>> edges = {
    //     {3, 9, 22},
    //     {4, 1, 87},
    //     {2, 1, -1},
    //     {11, 5, 24},
    //     {6, 10, 98},
    //     {7, 10, 97},
    //     {8, 10, 83},
    //     {10, 9, 88},
    //     {11, 2, 79},
    //     {10, 2, -1},
    //     {10, 0, -1},
    //     {12, 0, 97},
    //     {10, 5, 41}};
    // int source = 0;
    // int destination = 1;
    // int target = 169;

    Solution sol;
    vector<vector<int>> res = sol.modifiedGraphEdges(
        n,
        edges,
        source,
        destination,
        target);

    cout << "[" << endl;
    for (auto v : res)
    {
        cout << "[";
        for (auto i : v)
        {
            cout << i << ",";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;

    return 0;
}