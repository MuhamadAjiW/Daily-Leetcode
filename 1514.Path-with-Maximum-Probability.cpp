#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
    {
        vector<vector<pair<int, double>>> adjacency(n);
        for (size_t i = 0; i < edges.size(); i++)
        {
            int n1 = edges[i][0];
            int n2 = edges[i][1];
            double prob = succProb[i];

            adjacency[n1].emplace_back(n2, prob);
            adjacency[n2].emplace_back(n1, prob);
        }

        vector<double> prob_list(n, {0});
        prob_list[start_node] = 1;

        priority_queue<pair<double, int>, vector<pair<double, int>>, less<>> prio_queue;
        prio_queue.push({1, start_node});

        while (!prio_queue.empty())
        {
            auto [prob, node] = prio_queue.top();
            // cout << "Checking: " << node << ", Prob: " << prob << endl;
            prio_queue.pop();

            if (prob < prob_list[node])
            {
                continue;
            }

            for (auto &adjacent : adjacency[node])
            {
                int adj_node = adjacent.first;
                double adj_prob = adjacent.second;

                // cout << "Adjacent: " << adj_node << ", Prob: " << adj_prob << endl;
                double new_prob = prob_list[node] == 0 ? adj_prob : prob_list[node] * adj_prob;
                // double new_prob = prob_list[node] * adj_prob;

                if (prob_list[adj_node] < new_prob)
                {
                    prob_list[adj_node] = new_prob;
                    prio_queue.push({prob_list[adj_node], adj_node});
                }
            }
        }

        return prob_list[end_node];
    }
};

int main()
{
    int n = 3;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {0, 2}};
    vector<double> succProb = {
        0.5,
        0.5,
        0.2};
    int start = 0;
    int end = 2;

    Solution sol;
    double res = sol.maxProbability(n, edges, succProb, start, end);

    cout << res << endl;

    return 0;
}