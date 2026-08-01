/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool predictTheWinner(vector<int> &nums) {
    vector<int> dp(nums.begin(), nums.end());
    const int SZ = nums.size();

    for (int len = 2; len <= SZ; ++len) {
      for (int l = 0; l + len <= SZ; ++l) {
        int r = l + len - 1;

        dp[l] = max(nums[l] - dp[l + 1], nums[r] - dp[l]);
      }
    }

    return dp[0] >= 0;
  }
};
