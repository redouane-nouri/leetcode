#include <algorithm>
#include <vector>

class Solution {
public:
  int maxSumDivThree(std::vector<int> &nums) {
    std::vector<int> dp = {0, 0, 0}, newDp(3);

    for (int num : nums) {
      newDp = dp;

      for (int r = 0; r < 3; ++r) {
        int nr = (dp[r] + num) % 3;
        newDp[nr] = std::max(newDp[nr], dp[r] + num);
      }

      dp = newDp;
    }

    return dp[0];
  }
};
