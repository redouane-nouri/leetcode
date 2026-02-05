#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int minimumCost(vector<int> &nums) {
    const int N = nums.size();
    int a = INT_MAX, b = INT_MAX;
    for (int i = 1; i < N; ++i)
      if (nums[i] < a)
        b = a, a = nums[i];
      else if (nums[i] < b)
        b = nums[i];
    return nums[0] + a + b;
  }
};
