
/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
  int minMirrorPairDistance(vector<int> &nums) {
    const auto rev = [](int x) -> int {
      int res = 0;

      while (x) {
        res = res * 10 + x % 10;
        x /= 10;
      }

      return res;
    };

    const int N = nums.size();
    int ans = INT_MAX;
    unordered_map<int, int> mp;

    for (int i = 0; i < N; ++i) {
      if (mp.contains(nums[i]))
        ans = min(ans, i - mp[nums[i]]);

      mp[rev(nums[i])] = i;
    }

    return ans == INT_MAX ? -1 : ans;
  }
};
