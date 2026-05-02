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
  bool containsCycle(vector<vector<char>> &grid) {
    const int M = grid.size(), N = grid[0].size();
    DSU dsu(M * N);
    int dirs[2][2] = {{0, 1}, {1, 0}};

    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        for (auto &d : dirs) {
          int ni = i + d[0], nj = j + d[1];

          if ((ni >= M || nj >= N) || grid[ni][nj] != grid[i][j])
            continue;

          int u = i * N + j, v = ni * N + nj;

          if (dsu.find(u) == dsu.find(v))
            return true;

          dsu.unite(u, v);
        }
      }
    }

    return false;
  }
};
