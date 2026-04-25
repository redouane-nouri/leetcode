/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

struct DSU {
  vector<int> parent, size;

  DSU(int n) : parent(n), size(n, 1) { iota(parent.begin(), parent.end(), 0); }

  int find(int u) {
    if (parent[u] == u)
      return u;

    return parent[u] = find(parent[u]);
  }

  void unite(int u, int v) {
    u = find(u), v = find(v);

    if (u != v) {
      if (size[u] < size[v])
        swap(u, v);

      parent[v] = u;
      size[u] += size[v];
    }
  }
};

class Solution {
public:
  int minimumHammingDistance(vector<int> &source, vector<int> &target,
                             vector<vector<int>> &allowedSwaps) {
    const int N = source.size();
    DSU dsu(N);

    for (auto &s : allowedSwaps)
      dsu.unite(s[0], s[1]);

    unordered_map<int, unordered_map<int, int>> mp;
    for (int i = 0; i < N; ++i)
      ++mp[dsu.find(i)][source[i]];

    int ans = 0;
    for (int i = 0; i < N; ++i) {
      int root = dsu.find(i);

      mp[root][target[i]] ? --mp[root][target[i]] : ++ans;
    }

    return ans;
  }
};
