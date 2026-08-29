/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> resultArray(vector<int> &nums) {
    const int SZ = nums.size();
    int i = 0, j = SZ - 1;
    vector<int> res(SZ);

    res[i] = nums[0], res[j] = nums[1];

    for (int k = 2; k < SZ; ++k)
      if (res[i] > res[j])
        res[++i] = nums[k];
      else
        res[--j] = nums[k];

    reverse(res.begin() + j, res.end());
    return res;
  }
};
