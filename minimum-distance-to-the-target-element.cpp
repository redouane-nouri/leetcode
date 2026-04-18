
/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int getMinDistance(vector<int> &nums, int target, int start) {
    const int N = nums.size();
    int l = start - 1, r = start;

    while (l >= 0 || r < N) {
      if (r < N && nums[r] == target)
        return abs(start - r);

      if (l >= 0 && nums[l] == target)
        return abs(start - l);

      --l, ++r;
    }

    return -1;
  }
};
