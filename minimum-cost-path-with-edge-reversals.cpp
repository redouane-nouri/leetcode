#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int minCost(int n, vector<vector<int>> &edges) {
    vector<vector<pair<int, int>>> adj(n);
    for (auto &e : edges)
      adj[e[0]].push_back({e[1], e[2]}), adj[e[1]].push_back({e[0], e[2] << 1});
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push({0, 0});
    while (!pq.empty()) {
      int d = pq.top().first, i = pq.top().second;
      pq.pop();
      if (d > dist[i])
        continue;
      if (i == n - 1)
        return d;
      for (auto &e : adj[i]) {
        int newDist = d + e.second;
        if (newDist < dist[e.first])
          dist[e.first] = newDist, pq.push({newDist, e.first});
      }
    }
    return -1;
  }
};
