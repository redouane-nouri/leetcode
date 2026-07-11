/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct DSU {
  vector<int> parent, size;

  DSU(const int N) : parent(N), size(N, 1) {
    iota(parent.begin(), parent.end(), 0);
  }

  int find(const int u) {
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
  int countCompleteComponents(int n, vector<vector<int>> &edges) {
    DSU dsu(n);

    for (auto &e : edges)
      dsu.unite(e[0], e[1]);

    unordered_map<int, int> edgeCnt;
    for (auto &e : edges)
      ++edgeCnt[dsu.find(e[0])];

    int ans = 0;
    for (int v = 0; v < n; ++v) {
      if (dsu.find(v) == v) {
        ll vertices = dsu.size[v], expEdgs = vertices * (vertices - 1) >> 1,
           actEdgs = edgeCnt.count(v) ? edgeCnt[v] : 0;

        if (actEdgs == expEdgs)
          ans++;
      }
    }

    return ans;
  }
};
