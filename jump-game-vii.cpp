/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
      const int N = s.size();
      vector<int> dp(N, 1);

      for(int i = minJump; i < N; ++i){
        dp[i] = dp[i - 1];

        if(s[i] == '1') continue;

        int l = max(0, i - maxJump), r = i - minJump, w = dp[r] - (l == 0 ? 0 : dp[l - 1]);

        if(w > 0)
          ++dp[i];
      }

      return dp[N - 1] > dp[N - 2];
    }
};
