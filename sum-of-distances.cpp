/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
  vector<ll> distance(vector<int> &nums) {
    const int N = nums.size();
    unordered_map<int, vector<int>> mp;

    for (int i = 0; i < N; ++i)
      mp[nums[i]].push_back(i);

    vector<ll> ans(N);
    for (const auto &[x, grp] : mp) {
      ll tot = accumulate(grp.begin(), grp.end(), 0LL), pre = 0;
      const int M = grp.size();

      for (int i = 0; i < M; ++i)
        ans[grp[i]] =
            1LL * grp[i] * i - pre + tot - pre - 1LL * grp[i] * (M - i),
        pre += grp[i];
    }

    return ans;
  }
};
