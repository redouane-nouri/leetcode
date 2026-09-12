/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int firstStableIndex(vector<int> &nums, int k) {
    const int N = nums.size();
    vector<int> mn(N);

    mn[N - 1] = nums[N - 1];
    for (int i = N - 2; i >= 0; --i)
      mn[i] = min(mn[i + 1], nums[i]);

    int mx = 0;
    for (int i = 0; i < N; ++i) {
      mx = max(mx, nums[i]);
      if (mx - mn[i] <= k)
        return i;
    }

    return -1;
  }
};
