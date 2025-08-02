#include <vector>

class Solution {
public:
  int islandPerimeter(std::vector<std::vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size(), res = 0;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 0)
          continue;

        res += 4;

        if (i + 1 < n && grid[i + 1][j] == 1)
          res -= 2;

        if (j + 1 < m && grid[i][j + 1] == 1)
          res -= 2;
      }
    }

    return res;
  }
};
