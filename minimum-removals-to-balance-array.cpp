#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minRemoval(vector<int> &nums, int k) {
    const int N = nums.size();

    sort(nums.begin(), nums.end());

    int l = 0, mx = 0;

    for (int r = 0; r < N; ++r) {
      while (nums[r] > (long long)k * nums[l])
        ++l;

      mx = max(mx, r - l);
    }

    return N - mx - 1;
  }
};
