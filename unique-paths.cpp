#include <vector>

class Solution {
public:
  int uniquePaths(int m, int n) {
    std::vector<std::vector<int>> memo(m + 1, std::vector<int>(n + 1, -1));
    return discover(m, n, memo);
  }

private:
  int discover(int m, int n, std::vector<std::vector<int>> &memo) {
    if (m == 1 && n == 1)
      return 1;

    if (m < 1 || n < 1)
      return 0;

    if (memo[m][n] != -1)
      return memo[m][n];

    return memo[m][n] = discover(m - 1, n, memo) + discover(m, n - 1, memo);
  }
};
