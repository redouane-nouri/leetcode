
/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int numDistinct(string s, string t) {
    const int SN = s.size(), TN = t.size();
    vector<unsigned long long> dp(TN + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < SN; ++i)
      for (int j = TN - 1; j >= 0; --j)
        if (t[j] == s[i])
          dp[j + 1] += dp[j];

    return dp[TN];
  }
};
