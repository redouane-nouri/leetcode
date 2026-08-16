/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxSubarrayLength(vector<int> &nums, int k) {
    unordered_map<int, int> freq;
    const int SZ = nums.size();
    int start = 0, ans = 0;

    for (int end = 0; end < SZ; ++end) {
      ++freq[nums[end]];

      while (freq[nums[end]] > k)
        --freq[nums[start]], ++start;

      ans = max(ans, end - start + 1);
    }

    return ans;
  }
};
