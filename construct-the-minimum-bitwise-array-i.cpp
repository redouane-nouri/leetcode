#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> minBitwiseArray(vector<int> &nums) {
    for (auto &num : nums) {
      int ans = -1, mask = 1;
      while ((mask & num) != 0) {
        ans = num - mask;
        mask <<= 1;
      }
      num = ans;
    }
    return nums;
  }
};
