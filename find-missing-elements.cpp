/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> findMissingElements(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    const int SZ = nums.size();
    vector<int> ans;
    int i = 0;

    for (int x = nums[0]; x <= nums[SZ - 1]; ++x)
      if (x == nums[i])
        ++i;
      else
        ans.push_back(x);

    return ans;
  }
};
