/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
  static constexpr int MX = 2000;

public:
  int maxPalindromes(string s, int k) {
    const int N = s.size();
    vector<bitset<MX>> isPalindrome(MX);

    for (int len = 1; len <= N; ++len) {
      for (int l = 0; l + len <= N; ++l) {
        int r = l + len - 1;
        isPalindrome[l].set(r, s[l] == s[r] &&
                                   (len <= 2 || isPalindrome[l + 1][r - 1]));
      }
    }

    vector<int> dp(N + 1, 0);

    for (int len = 1; len <= N; ++len) {
      dp[len] = dp[len - 1];

      for (int l = 0; l + k <= len; ++l)
        if (isPalindrome[l][len - 1])
          dp[len] = max(dp[len], dp[l] + 1);
    }

    return dp[N];
  }
};
