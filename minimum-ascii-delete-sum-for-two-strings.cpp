#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  int minimumDeleteSum(std::string s1, std::string s2) {
    const int n = s1.size(), m = s2.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));

    dp[0][0] = 0;

    for (int i = 0; i < n; ++i)
      dp[i + 1][0] = dp[i][0] + s1[i];

    for (int j = 0; j < m; ++j)
      dp[0][j + 1] = dp[0][j] + s2[j];

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (s1[i - 1] == s2[j - 1])
          dp[i][j] = dp[i - 1][j - 1];
        else
          dp[i][j] =
              std::min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
      }
    }

    return dp[n][m];
  }
};
