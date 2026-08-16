/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int missingInteger(vector<int> &nums) {
    const int SZ = nums.size();
    int i = 1;

    while (i < SZ && nums[i] - 1 == nums[i - 1])
      ++i;

    int sum = ((nums[0] + nums[i - 1]) * i) >> 1;

    unordered_set<int> seen(nums.begin(), nums.end());
    while (seen.count(sum))
      ++sum;

    return sum;
  }
};
