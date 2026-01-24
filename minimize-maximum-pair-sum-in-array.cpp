#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int minPairSum(vector<int> &nums) {
    const int N = nums.size();
    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int i = 0; i < (N >> 1); ++i) {
      ans = max(ans, nums[i] + nums[N - i - 1]);
    }
    return ans;
  }
};
