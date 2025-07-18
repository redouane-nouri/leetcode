#include <vector>

class Solution {
public:
  int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();

    return -discover(m - 1, n - 1, obstacleGrid);
  }

private:
  int discover(int m, int n, std::vector<std::vector<int>> &obstacleGrid) {
    if (m < 0 || n < 0 || obstacleGrid[m][n] == 1)
      return 0;

    if (obstacleGrid[m][n] != 0)
      return obstacleGrid[m][n];

    if (m == 0 && n == 0)
      return -1;

    return obstacleGrid[m][n] = discover(m - 1, n, obstacleGrid) +
                                discover(m, n - 1, obstacleGrid);
  }
};
