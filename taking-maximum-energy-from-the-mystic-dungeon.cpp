#include <algorithm>
#include <climits>
#include <vector>

class Solution {
public:
  int maximumEnergy(std::vector<int> &energy, int k) {
    int n = energy.size(), res = INT_MIN;
    std::vector<int> dp(k, 0);

    int iMod = (n - 1) % k;
    for (int i = n - 1; i >= 0; --i) {
      dp[iMod] += energy[i];
      res = std::max(res, dp[iMod]);
      if (--iMod < 0) {
        iMod = k - 1;
      }
    }

    return res;
  }
};
