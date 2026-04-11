/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
  static const int MOD = 1e9 + 7;

public:
  int xorAfterQueries(vector<int> &nums, vector<vector<int>> &queries) {
    int N = nums.size();

    for (auto &q : queries)
      for (int i = q[0]; i <= q[1]; i += q[2])
        nums[i] = 1ll * nums[i] * q[3] % MOD;

    int ans = 0;

    for (auto &x : nums)
      ans ^= x;

    return ans;
  }
};
