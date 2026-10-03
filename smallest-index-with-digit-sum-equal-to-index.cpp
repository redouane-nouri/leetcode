/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int smallestIndex(vector<int> &nums) {
    const auto sumDigits = [](int x) -> int {
      int res = 0;

      while (x) {
        res += x % 10;
        x /= 10;
      }

      return res;
    };

    const int N = nums.size();
    for (int i = 0; i < N; ++i) {
      if (sumDigits(nums[i]) == i)
        return i;
    }

    return -1;
  }
};
