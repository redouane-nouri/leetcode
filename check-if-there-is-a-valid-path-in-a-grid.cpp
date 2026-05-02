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
  bool hasValidPath(vector<vector<int>> &grid) {
    const int M = grid.size(), N = grid[0].size();
    DSU dsu(N * M);

    auto opensRight = [](int s) { return s == 1 || s == 4 || s == 6; };
    auto opensLeft = [](int s) { return s == 1 || s == 3 || s == 5; };
    auto opensDown = [](int s) { return s == 2 || s == 3 || s == 4; };
    auto opensUp = [](int s) { return s == 2 || s == 5 || s == 6; };

    auto id = [&N](int i, int j) { return i * N + j; };

    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        if (j + 1 < N && opensRight(grid[i][j]) && opensLeft(grid[i][j + 1]))
          dsu.unite(id(i, j), id(i, j + 1));

        if (i + 1 < M && opensDown(grid[i][j]) && opensUp(grid[i + 1][j]))
          dsu.unite(id(i, j), id(i + 1, j));
      }
    }

    return dsu.find(0) == dsu.find(M * N - 1);
  }
};
