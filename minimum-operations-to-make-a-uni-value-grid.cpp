/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minOperations(vector<vector<int>> &grid, int x) {
    const int N = grid.size() * grid[0].size();
    vector<int> nums;
    nums.reserve(N);

    for (const auto &g : grid)
      for (const int &v : g)
        nums.push_back(v);

    nth_element(nums.begin(), nums.begin() + N / 2, nums.end());
    const int MEDIAN = nums[N / 2];

    int ops = 0;
    for (const int &v : nums)
      if (v % x == MEDIAN % x)
        ops += abs(MEDIAN - v) / x;
      else
        return -1;

    return ops;
  }
};
