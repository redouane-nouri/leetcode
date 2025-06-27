#include <string>
#include <vector>

class Solution {
public:
  bool isMatch(std::string s, std::string p) {
    int sSize = s.size(), pSize = p.size();
    std::vector<std::vector<bool>> dp(sSize + 1,
                                      std::vector<bool>(pSize + 1, false));
    // empty string matches empty pattern
    dp[0][0] = true;

    // only patterns of 1 char + '*' can match empty string (a* or a*b* etc..)
    for (int j = 2; j <= pSize; ++j) {
      if (p[j - 1] == '*' && dp[0][j - 2]) {
        dp[0][j] = true;
      }
    }

    for (int i = 1; i <= sSize; ++i) {
      for (int j = 1; j <= pSize; ++j) {
        // current pattern is '.' or equal to the current s char
        if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
          // true only if previous chars of s were true with the pattern till
          // now
          dp[i][j] = dp[i - 1][j - 1];
        } else if (p[j - 1] == '*') {
          // we assume for zero occurence, we check the previous char
          // example: ab* we assume (b*) is 0 occurence, we check for a
          dp[i][j] = dp[i][j - 2];

          // after handling zero occurence, we check for one or more occurences
          if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
            // look up to check if previous chars in s still match the *
            dp[i][j] = dp[i][j] || dp[i - 1][j];
          }
        }
      }
    }

    return dp[sSize][pSize];
  }
};
