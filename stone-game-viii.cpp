/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int stoneGameVIII(vector<int> &stones) {
    const int SZ = stones.size();
    vector<int> preSum(SZ + 1);

    for (int i = 0; i < SZ; ++i)
      preSum[i + 1] = preSum[i] + stones[i];

    int ans = preSum[SZ];

    for (int i = SZ - 1; i >= 2; --i)
      ans = max(ans, preSum[i] - ans);

    return ans;
  }
};
