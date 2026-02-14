#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  long long rob(vector<int> &nums, vector<int> &colors) {
    const int N = nums.size();
    int i = 0;
    long long ans = 0;

    while (i < N) {
      int start = i;
      long long grp1 = nums[start], grp2 = 0;

      while (i + 1 < N && colors[i] == colors[i + 1]) {
        ++i;

        if ((i - start) % 2)
          grp2 += nums[i];
        else
          grp1 += nums[i];
      }

      ans += max(grp1, grp2);
      ++i;
    }

    return ans;
  }
};
