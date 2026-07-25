/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
  static constexpr int MOD = 1e9 + 7;

public:
  int subsequencePairCount(vector<int> &nums) {
    const int MAX_GCD = *max_element(nums.begin(), nums.end());

    vector<vector<int>> dp(MAX_GCD + 1, vector<int>(MAX_GCD + 1));
    dp[0][0] = 1;

    for (const int &num : nums) {
      vector<vector<int>> ndp(MAX_GCD + 1, vector<int>(MAX_GCD + 1));

      for (int seq1GCD = 0; seq1GCD <= MAX_GCD; ++seq1GCD) {
        int nSeq1GCD = gcd(seq1GCD, num);

        for (int seq2GCD = 0; seq2GCD <= MAX_GCD; ++seq2GCD) {
          int freq = dp[seq1GCD][seq2GCD];

          if (freq == 0)
            continue;

          int nSeq2GCD = gcd(seq2GCD, num);
          ndp[seq1GCD][seq2GCD] = (ndp[seq1GCD][seq2GCD] + freq) % MOD;
          ndp[nSeq1GCD][seq2GCD] = (ndp[nSeq1GCD][seq2GCD] + freq) % MOD;
          ndp[seq1GCD][nSeq2GCD] = (ndp[seq1GCD][nSeq2GCD] + freq) % MOD;
        }
      }

      dp.swap(ndp);
    }

    int ans = 0;
    for (int seqGCD = 1; seqGCD <= MAX_GCD; ++seqGCD)
      ans = (ans + dp[seqGCD][seqGCD]) % MOD;

    return ans;
  }
};
