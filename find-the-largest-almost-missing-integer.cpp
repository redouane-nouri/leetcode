/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int largestInteger(vector<int> &nums, int k) {
    const int SZ = nums.size();

    if (k == SZ)
      return *max_element(nums.begin(), nums.end());

    int freq[51] = {0};

    for (int &x : nums)
      ++freq[x];

    if (k == 1)
      for (int i = 50; i >= 0; --i)
        if (freq[i] == 1)
          return i;

    if (nums[SZ - 1] < nums[0])
      swap(nums[SZ - 1], nums[0]);

    if (freq[nums[SZ - 1]] == 1)
      return nums[SZ - 1];

    if (freq[nums[0]] == 1)
      return nums[0];

    return -1;
  }
};
