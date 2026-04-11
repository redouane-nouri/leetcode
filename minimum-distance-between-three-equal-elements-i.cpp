/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minimumDistance(vector<int> &nums) {
    unordered_map<int, vector<int>> mp;
    const int N = nums.size();

    for (int i = 0; i < N; ++i)
      mp[nums[i]].push_back(i);

    int ans = INT_MAX;

    for (auto &[k, v] : mp) {
      if (v.size() < 3)
        continue;

      const int SZ = v.size();

      for (int i = 0; i < SZ - 2; ++i)
        ans = min(ans, (v[i + 2] - v[i]) << 1);
    }

    return ans == INT_MAX ? -1 : ans;
  }
};
