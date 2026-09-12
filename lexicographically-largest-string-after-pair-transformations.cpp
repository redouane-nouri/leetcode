/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<string> largestString(vector<int> &nums) {
    vector<string> ans;
    ans.reserve(nums.size());

    for (const int &x : nums) {
      string s;
      s.append(x >> 25, 'z');

      for (int p = 24; p >= 0; --p)
        if (x & (1 << p))
          s += 'a' + p;

      ans.push_back(s);
    }

    return ans;
  }
};
