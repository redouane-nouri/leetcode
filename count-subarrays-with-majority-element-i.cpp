/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int countMajoritySubarrays(vector<int> &nums, int target) {
    int ans = 0;
    const int N = nums.size();

    for (int i = 0; i < N; ++i) {
      int count = 0;
      for (int j = i; j < N; ++j) {
        count += (nums[j] == target ? 1 : -1);

        if (count > 0)
          ++ans;
      }
    }

    return ans;
  }
};
