/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
  static constexpr int maxPeak = 1 << 15;

public:
  int maximumLength(vector<int> &nums) {
    unordered_map<int, int> mp;
    for (int &v : nums)
      ++mp[v];

    int ans = mp[1] % 2 == 0 ? mp[1] - 1 : mp[1];
    mp.erase(1);

    for (auto &[k, _] : mp) {
      int v = k, l = 0;
      while (v <= maxPeak && mp.count(v) && mp[v] > 1)
        l += 2, v *= v;

      ans = max(ans, l + (mp.count(v) ? 1 : -1));
    }

    return ans;
  }
};
