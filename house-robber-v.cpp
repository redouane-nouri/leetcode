/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
  ll rob(vector<int> &nums, vector<int> &colors) {
    const int N = nums.size();

    if (N == 1)
      return nums[0];

    ll best = nums[0];
    ll prev = nums[1] + (colors[0] != colors[1] ? nums[0] : 0);
    ll ans = max(prev, best);

    for (int i = 2; i < N; i++) {
      ll curr = best + nums[i];

      if (colors[i] != colors[i - 1])
        curr = max(curr, prev + nums[i]);

      ans = max(ans, curr);
      best = max(best, prev);
      prev = curr;
    }

    return ans;
  }
};
