/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maximumProduct(vector<int> &nums) {
    const int SZ = nums.size();
    sort(nums.begin(), nums.end());

    return max(nums[0] * nums[1] * nums[SZ - 1],
               nums[SZ - 1] * nums[SZ - 2] * nums[SZ - 3]);
  }
};
