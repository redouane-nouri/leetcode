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
    for (const auto &[_, v] : mp) {
      if (v.size() < 3)
        continue;

      bool isValid = true;
      int gap = v[1] - v[0];

      for (int i = 2; i < v.size(); ++i)
        if (v[i] - v[i - 1] != gap) {
          isValid = false;
          break;
        }

      if (isValid)
        ++ans;
    }

    return ans;
  }
};
