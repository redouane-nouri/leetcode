/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int countSpecialIntegers(vector<int> &nums) {
    unordered_map<int, vector<int>> mp;
    const int N = nums.size();

    for (int i = 0; i < N; ++i)
      mp[nums[i]].push_back(i);

    int ans = 0;
    for (const auto &[_, v] : mp)
      if (v.size() == 3 && v[1] - v[0] == v[2] - v[1])
        ++ans;

    return ans;
  }
};
