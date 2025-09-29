#include <algorithm>
#include <climits>
#include <vector>

class Solution {
public:
  int minScoreTriangulation(std::vector<int> &values) {
    int n = values.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    for (int l = 3; l <= n; ++l) {
      for (int i = 0; i + l <= n; ++i) {
        int j = i + l - 1;
        dp[i][j] = INT_MAX;
        for (int k = i + 1; k < j; ++k)
          dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j] +
                                            values[i] * values[k] * values[j]);
      }
    }

    return dp[0][n - 1];
  }
};
