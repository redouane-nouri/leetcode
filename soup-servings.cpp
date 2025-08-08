#include <vector>
class Solution {
  std::vector<std::vector<double>> memo;

  double dfs(int a, int b) {
    if (a <= 0 && b > 0)
      return 1.0;

    if (a <= 0 && b <= 0)
      return 0.5;

    if (a > 0 && b <= 0)
      return 0.0;

    if (memo[a][b] != -1.0)
      return memo[a][b];

    return memo[a][b] = 0.25 * (dfs(a - 4, b) + dfs(a - 3, b - 1) +
                                dfs(a - 2, b - 2) + dfs(a - 1, b - 3));
  }

public:
  double soupServings(int n) {
    if (n > 4275)
      return 1;

    int newN = (n + 24) / 25;

    memo = std::vector<std::vector<double>>(
        newN + 1, std::vector<double>(newN + 1, -1.0));

    return dfs(newN, newN);
  }
};
