#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
  vector<int> djikstra(int src, vector<vector<pair<int, int>>> &adjs) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    vector<int> costs(26, INT_MAX);
    costs[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
      int cost = pq.top().first, curr = pq.top().second;
      pq.pop();
      if (cost <= costs[curr]) {
        for (const auto &adj : adjs[curr]) {
          int s = cost + adj.first;
          if (s < costs[adj.second]) {
            costs[adj.second] = s;
            pq.push({s, adj.second});
          }
        }
      }
    }
    return costs;
  }

public:
  long long minimumCost(string source, string target, vector<char> &original,
                        vector<char> &changed, vector<int> &cost) {
    const int N = original.size(), M = source.size();
    vector<vector<pair<int, int>>> adjs(26);
    vector<int> costs[26];
    for (int i = 0; i < N; ++i)
      adjs[original[i] - 'a'].push_back({cost[i], changed[i] - 'a'});
    for (const auto &src : original) {
      int i = src - 'a';
      if (costs[i].empty())
        costs[i] = djikstra(i, adjs);
    }
    long long ans = 0;
    for (int i = 0; i < M; ++i) {
      if (source[i] != target[i]) {
        int src = source[i] - 'a', trgt = target[i] - 'a';
        if (costs[src].empty() || costs[src][trgt] == INT_MAX)
          return -1;
        ans += costs[src][trgt];
      }
    }
    return ans;
  }
};
