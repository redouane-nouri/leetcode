#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool isTrionic(vector<int> &nums) {
    const int ENDIDX = nums.size() - 1;
    if (ENDIDX < 3)
      return false;
    int i = 0;
    while (i < ENDIDX && nums[i] < nums[i + 1])
      ++i;
    if (i == 0 || i == ENDIDX)
      return false;
    int p = i;
    while (i < ENDIDX && nums[i] > nums[i + 1])
      ++i;
    if (i == p || i == ENDIDX)
      return false;
    while (i < ENDIDX && nums[i] < nums[i + 1])
      ++i;
    return i == ENDIDX;
  }
};
