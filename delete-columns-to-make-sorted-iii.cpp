#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  int minDeletionSize(std::vector<std::string> &strs) {
    const int N = strs.size(), M = strs[0].size();
    std::vector<int> dp(M, 1);

    auto keep = [&N, &strs](int &pc, int &c) -> bool {
      for (int r = 0; r < N; ++r)
        if (strs[r][pc] > strs[r][c])
          return false;

      return true;
    };

    for (int c = 0; c < M; ++c)
      for (int pc = 0; pc < c; ++pc)
        if (keep(pc, c))
          dp[c] = std::max(dp[c], dp[pc] + 1);

    return M - *std::max_element(dp.begin(), dp.end());
  }
};
