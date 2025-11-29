#include <set>
#include <string>
#include <vector>

class Solution {
public:
  bool wordBreak(std::string s, std::vector<std::string> &wordDict) {
    const int N = s.size();
    std::set<std::string> dict(wordDict.begin(), wordDict.end());
    std::vector<bool> dp(N + 1, false);
    dp[0] = true;

    for (int i = 1; i <= N; ++i) {
      int j = 0;

      while (j < i && !dp[i]) {
        if (dp[j] && dict.count(s.substr(j, i - j)))
          dp[i] = true;

        ++j;
      }
    }

    return dp[N];
  }
};
