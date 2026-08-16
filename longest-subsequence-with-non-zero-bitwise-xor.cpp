/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int longestSubsequence(vector<int> &nums) {
    bool isAllZeroes = true;
    int xr = 0;

    for (const int &x : nums) {
      if (x)
        isAllZeroes = false;

      xr ^= x;
    }

    if (xr)
      return nums.size();

    return isAllZeroes ? 0 : nums.size() - 1;
  }
};
