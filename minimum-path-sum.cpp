#include <algorithm>
#include <vector>

class Solution {
public:
  int minPathSum(std::vector<std::vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();

    for (int j = 1; j < n; ++j)
      grid[0][j] += grid[0][j - 1];

    for (int i = 1; i < m; ++i)
      grid[i][0] += grid[i - 1][0];

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j)
        grid[i][j] += std::min(grid[i][j - 1], grid[i - 1][j]);
    }

    return grid[m - 1][n - 1];
  }
};
