/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

struct DSU {
  vector<int> parent, size;

  DSU(const int n) : parent(n), size(n, 1) {
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
  vector<bool> pathExistenceQueries(int n, vector<int> &nums, int maxDiff,
                                    vector<vector<int>> &queries) {
    DSU dsu(n);
    for (int i = 1; i < n; ++i)
      if (nums[i] - nums[i - 1] <= maxDiff)
        dsu.unite(i - 1, i);

    vector<bool> res;
    res.reserve(queries.size());

    for (auto &q : queries)
      res.push_back(dsu.find(q[0]) == dsu.find(q[1]));

    return res;
  }
};
