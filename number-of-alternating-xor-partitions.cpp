/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
  static constexpr int MOD = 1e9 + 7;

public:
  int alternatingXOR(vector<int> &nums, int target1, int target2) {
    unordered_map<int, int> endsWithT1, endsWithT2;
    endsWithT2[0] = 1;

    int pref = 0, dp1 = 0, dp2 = 0;

    for (const int &num : nums) {
      pref ^= num;

      int need1 = pref ^ target1, need2 = pref ^ target2;

      dp1 = endsWithT2.count(need1) ? endsWithT2[need1] : 0;
      dp2 = endsWithT1.count(need2) ? endsWithT1[need2] : 0;

      endsWithT1[pref] = (endsWithT1[pref] + dp1) % MOD;
      endsWithT2[pref] = (endsWithT2[pref] + dp2) % MOD;
    }

    return (dp1 + dp2) % MOD;
  }
};
