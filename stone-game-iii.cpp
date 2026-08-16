/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string stoneGameIII(vector<int> &stoneValue) {
    const int SZ = stoneValue.size();

    vector<int> dp(SZ + 1, INT_MIN);
    dp[SZ] = 0;

    for (int i = SZ - 1; i >= 0; --i) {
      int gain = 0;

      for (int stones = 1; stones <= 3 && i + stones <= SZ; ++stones) {
        gain += stoneValue[i + stones - 1];
        dp[i] = max(dp[i], gain - dp[i + stones]);
      }
    }

    if (dp[0] > 0)
      return "Alice";

    if (dp[0] < 0)
      return "Bob";

    return "Tie";
  }
};
