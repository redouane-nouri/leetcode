/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minCost(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> mp;

    const int N = nums1.size();

    for (int i = 0; i < N; ++i) {
      ++mp[nums1[i]];
      --mp[nums2[i]];
    }

    int ans = 0;

    for (auto &[v, c] : mp) {
      if (c % 2 != 0)
        return -1;

      if (c > 0)
        ans += c / 2;
    }

    return ans;
  }
};
