/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int firstUniqueEven(vector<int> &nums) {
    unordered_map<int, int> mp;

    for (const auto &num : nums)
      if (!(num % 2))
        ++mp[num];

    for (const auto &num : nums)
      if (!(num % 2) && mp[num] == 1)
        return num;

    return -1;
  }
};
