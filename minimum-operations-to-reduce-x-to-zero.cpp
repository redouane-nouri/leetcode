/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minOperations(vector<int> &nums, int x) {
    const int N = nums.size();
    int tot = accumulate(nums.begin(), nums.end(), 0), target = tot - x;

    if (target < 0)
      return -1;

    if (target == 0)
      return N;

    int l = 0, sum = 0, len = -1;
    for (int r = 0; r < N; ++r) {
      sum += nums[r];

      while (sum > target && l <= r)
        sum -= nums[l++];

      if (sum == target)
        len = max(len, r - l + 1);
    }

    return len == -1 ? -1 : N - len;
  }
};
