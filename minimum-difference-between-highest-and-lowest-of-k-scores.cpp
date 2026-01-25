#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int minimumDifference(vector<int> &nums, int k) {
    const int N = nums.size();
    --k;
    sort(nums.begin(), nums.end());
    int ans = 1e6;
    for (int i = 0; i < N - k; ++i)
      ans = min(ans, nums[i + k] - nums[i]);
    return ans;
  }
};
