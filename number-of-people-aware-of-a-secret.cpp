class Solution {
public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    int dp[n], s = 0, res = 0;
    const int MOD = 1'000'000'007;
    dp[0] = 1;

    for (int d = 1; d < n; ++d) {
      if (d - delay >= 0) {
        s += dp[d - delay];

        if (s >= MOD)
          s -= MOD;
      }

      if (d - forget >= 0) {
        s -= dp[d - forget];
        if (s < 0)
          s += MOD;
      }

      dp[d] = s;
    }

    for (int i = n - forget; i < n; ++i) {
      res += dp[i];
      if (res >= MOD)
        res -= MOD;
    }

    return res;
  }
};
