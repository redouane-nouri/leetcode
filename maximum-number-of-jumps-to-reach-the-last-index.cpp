/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maximumJumps(vector<int> &nums, int target) {
    const int N = nums.size();
    vector<int> dp(N, -1);
    dp[0] = 0;

    for (int i = 0; i < N; ++i) {
      if (dp[i] == -1)
        continue;

      for (int j = i + 1; j < N; ++j) {
        if (abs(nums[j] - nums[i]) <= target)
          dp[j] = max(dp[j], dp[i] + 1);
      }
    }

    return dp[N - 1];
  }
};
