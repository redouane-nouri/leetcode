#include <algorithm>
#include <queue>
#include <vector>

struct Cell {
  int x, y, h;
  Cell(int _x, int _y, int _h) : x(_x), y(_y), h(_h) {}
};

struct Compare {
  bool operator()(const Cell &a, const Cell &b) const { return a.h > b.h; }
};

class Solution {
public:
  int trapRainWater(std::vector<std::vector<int>> &heightMap) {
    int m = heightMap.size(), n = heightMap[0].size();
    if (m < 3 || n < 3)
      return 0;

    std::priority_queue<Cell, std::vector<Cell>, Compare> pq;
    std::vector<std::vector<bool>> v(m, std::vector<bool>(n, false));

    for (int i = 0; i < m; ++i) {
      pq.push(Cell(i, 0, heightMap[i][0]));
      pq.push(Cell(i, n - 1, heightMap[i][n - 1]));
      v[i][0] = v[i][n - 1] = true;
    }

    for (int j = 1; j < n - 1; ++j) {
      pq.push(Cell(0, j, heightMap[0][j]));
      pq.push(Cell(m - 1, j, heightMap[m - 1][j]));
      v[0][j] = v[m - 1][j] = true;
    }

    int res = 0, dir[5] = {-1, 0, 1, 0, -1},
        numVisited = (m << 1) + ((n - 2) << 1), total = m * n;

    while (numVisited < total) {
      Cell t = pq.top();
      pq.pop();

      for (int i = 0; i < 4; ++i) {
        int nx = t.x + dir[i], ny = t.y + dir[i + 1];

        if (nx >= 0 && nx < m && ny >= 0 && ny < n && !v[nx][ny]) {
          v[nx][ny] = true;
          ++numVisited;
          res += std::max(0, t.h - heightMap[nx][ny]);
          pq.push(Cell(nx, ny, std::max(t.h, heightMap[nx][ny])));
        }
      }
    }

    return res;
  }
};
