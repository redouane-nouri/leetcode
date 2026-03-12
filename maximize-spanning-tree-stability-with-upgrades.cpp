
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

bool isValidTree(int &n, vector<vector<int>> &edges, int k, int mid) {
  DSU dsu(n);
  vector<array<int, 2>> toUpgrade;

  for (auto &e : edges) {
    int &u = e[0], v = e[1], s = e[2], m = e[3];

    if (m) {
      if (s < mid)
        return false;

      dsu.unite(u, v);
    } else {
      if (s >= mid)
        dsu.unite(u, v);
      else if (s << 1 >= mid)
        toUpgrade.push_back({u, v});
    }
  }

  for (auto &[u, v] : toUpgrade) {
    if (dsu.find(u) != dsu.find(v)) {
      if (k-- <= 0)
        return false;

      dsu.unite(u, v);
    }
  }

  int root = dsu.find(0);

  for (int u = 1; u < n; ++u)
    if (dsu.find(u) != root)
      return false;

  return true;
}

class Solution {
public:
  int maxStability(int n, vector<vector<int>> &edges, int k) {
    DSU dsu(n);

    for (auto &e : edges) {
      int &u = e[0], v = e[1], s = e[2], m = e[3];

      if (m) {
        if (dsu.find(u) == dsu.find(v))
          return -1;

        dsu.unite(u, v);
      }
    }

    int ans = -1, l = 1, r = 1e5;

    while (l <= r) {
      int m = l + (r - l >> 1);

      isValidTree(n, edges, k, m) ? (ans = m, l = m + 1) : r = m - 1;
    }

    return ans;
  }
};
