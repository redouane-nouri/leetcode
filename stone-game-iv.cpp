/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool winnerSquareGame(int n) {
    vector<int> dp(n + 1, false);

    for (int stones = 1; stones <= n; ++stones) {
      for (int root = 1; root * root <= stones; ++root) {
        if (!dp[stones - root * root]) {
          dp[stones] = true;
          break;
        }
      }
    }

    return dp[n];
  }
};
