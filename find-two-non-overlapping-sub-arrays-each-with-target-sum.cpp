/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minSumOfLengths(vector<int> &arr, int target) {
    const int N = arr.size();
    vector<int> dp(N + 1, N + 1);

    int ans = N + 1;
    for (int l = 0, r = 0, s = 0; r < N; ++r) {
      dp[r + 1] = dp[r];
      s += arr[r];

      while (s > target)
        s -= arr[l++];

      if (s == target) {
        ans = min(ans, r - l + 1 + dp[l]);
        dp[r + 1] = min(dp[r], r - l + 1);
      }
    }

    return ans == N + 1 ? -1 : ans;
  }
};
