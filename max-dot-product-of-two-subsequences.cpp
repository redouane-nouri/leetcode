#include <algorithm>
#include <climits>
#include <vector>

class Solution {
public:
  int maxDotProduct(std::vector<int> &nums1, std::vector<int> &nums2) {
    const int n = nums1.size(), m = nums2.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, INT_MIN));

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        int p = nums1[i - 1] * nums2[j - 1];
        dp[i][j] = std::max(
            {p, p + std::max(0, dp[i - 1][j - 1]), dp[i - 1][j], dp[i][j - 1]});
      }
    }

    return dp[n][m];
  }
};
