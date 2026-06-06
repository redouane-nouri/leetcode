/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
      vector<int> ans;
      ans.reserve(nums.size());

      int tot = 0;
      for(int &num: nums)
        tot += num;

      int l = 0;
      for(int &num: nums)
        ans.push_back(abs(l - (tot - l - num))),
        l += num;

      return ans;
    }
};
