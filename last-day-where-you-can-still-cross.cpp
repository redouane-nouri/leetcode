#include <numeric>
#include <utility>
#include <vector>

class DSU {
  std::vector<int> parent, treeHeight;

public:
  DSU(int n) {
    parent.resize(n);
    treeHeight.assign(n, 0);
    std::iota(parent.begin(), parent.end(), 0);
  }

  int find(int v) {
    if (parent[v] != v)
      parent[v] = find(parent[v]);

    return parent[v];
  }

  void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (treeHeight[a] < treeHeight[b])
      std::swap(a, b);

    parent[b] = a;

    if (treeHeight[a] == treeHeight[b])
      ++treeHeight[a];
  }
};

class Solution {
public:
  int latestDayToCross(int row, int col, std::vector<std::vector<int>> &cells) {
    const int N = row * col;
    auto dsu = DSU(N + 2);
    std::vector<std::vector<bool>> land(row, std::vector(col, false));

    const auto flatten = [&col](int r, int c) -> int {
      return (r - 1) * col + c;
    };

    int dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, 1, -1};

    for (int day = N - 1; day >= 0; --day) {
      int r = cells[day][0], c = cells[day][1];
      land[r - 1][c - 1] = true;
      int currIdx = flatten(r, c);

      if (r == 1)
        dsu.unite(0, currIdx);
      else if (r == row)
        dsu.unite(N + 1, currIdx);

      for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i], nc = c + dc[i];
        if (nr > 0 && nc > 0 && nr <= row && nc <= col && land[nr - 1][nc - 1])
          dsu.unite(currIdx, flatten(nr, nc));
      }

      if (dsu.find(0) == dsu.find(N + 1))
        return day;
    }

    return -1;
  }
};
