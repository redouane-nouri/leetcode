#include <string>
#include <vector>

class Solution {
public:
  bool isInterleave(std::string s1, std::string s2, std::string s3) {
    int s1n = s1.size(), s2n = s2.size();

    if (s1n + s2n != s3.size())
      return false;

    std::vector<std::vector<bool>> dp(s1n + 1, std::vector<bool>(s2n + 1));
    dp[0][0] = true;

    for (int j = 1; j <= s2n; ++j)
      dp[0][j] = dp[0][j - 1] && (s3[j - 1] == s2[j - 1]);

    for (int i = 1; i <= s1n; ++i)
      dp[i][0] = dp[i - 1][0] && (s3[i - 1] == s1[i - 1]);

    for (int i = 1; i <= s1n; ++i)
      for (int j = 1; j <= s2n; ++j)
        dp[i][j] = (dp[i - 1][j] && (s3[i + j - 1] == s1[i - 1])) ||
                   (dp[i][j - 1] && (s3[i + j - 1] == s2[j - 1]));

    return dp[s1n][s2n];
  }
};
