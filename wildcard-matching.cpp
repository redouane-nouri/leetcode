#include <string>
#include <vector>

class Solution {
public:
  bool isMatch(std::string s, std::string p) {
    int sLength = s.length(), pLength = p.length();
    std::vector<std::vector<bool>> dp(sLength + 1,
                                      std::vector<bool>(pLength + 1, false));

    // empty string can match empty string
    dp[0][0] = true;

    //'*' can match only empty string
    for (int i = 1; i <= pLength; ++i) {
      if (p[i - 1] == '*')
        dp[0][i] = dp[0][i - 1];
    }

    for (int i = 1; i <= sLength; ++i) {
      for (int j = 1; j <= pLength; ++j) {
        if (p[j - 1] == '*') {
          // can be ignored or (||) match one char from previous match
          dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
        } else if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) {
          // true only if previous substring still true
          dp[i][j] = dp[i - 1][j - 1];
        }
      }
    }

    return dp[sLength][pLength];
  }
};
