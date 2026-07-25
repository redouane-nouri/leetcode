/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
  vector<int> gcdValues(vector<int> &nums, vector<ll> &queries) {
    int maxGCD = *max_element(nums.begin(), nums.end());
    vector<ll> cnt(maxGCD + 1);

    for (int &num : nums)
      cnt[num]++;

    for (int i = 1; i <= maxGCD; ++i)
      for (int j = i << 1; j <= maxGCD; j += i)
        cnt[i] += cnt[j];

    for (int i = 1; i <= maxGCD; ++i)
      cnt[i] = cnt[i] * (cnt[i] - 1) >> 1;

    for (int i = maxGCD; i >= 1; --i)
      for (int j = i << 1; j <= maxGCD; j += i)
        cnt[i] -= cnt[j];

    for (int i = 1; i <= maxGCD; ++i)
      cnt[i] += cnt[i - 1];

    vector<int> ans;
    for (ll q : queries) {
      ++q;
      int pos = lower_bound(cnt.begin(), cnt.end(), q) - cnt.begin();
      ans.push_back(pos);
    }

    return ans;
  }
};
