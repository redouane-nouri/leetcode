#include <vector>

class Solution {
public:
  int minimumArea(std::vector<std::vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size(), t = -1, b, l = n, r = -1;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          b = i;

          if (t == -1)
            t = i;

          if (j < l)
            l = j;

          if (j > r)
            r = j;
        }
      }
    }

    return (b - t + 1) * (r - l + 1);
  }
};
