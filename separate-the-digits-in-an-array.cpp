/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> separateDigits(vector<int> &nums) {
    vector<int> ans;
    ans.reserve(nums.size());

    for (int i = nums.size(); i >= 0; --i)
      while (nums[i])
        ans.push_back(nums[i] % 10), nums[i] /= 10;

    reverse(ans.begin(), ans.end());
    return ans;
  }
};
