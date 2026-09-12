/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int firstStableIndex(vector<int> &nums, int k) {
    const int N = nums.size();
    vector<int> mx(N), mn(N);

    mx[0] = nums[0];
    for (int i = 1; i < N; ++i)
      mx[i] = max(mx[i - 1], nums[i]);

    mn[N - 1] = nums[N - 1];
    for (int i = N - 2; i >= 0; --i)
      mn[i] = min(mn[i + 1], nums[i]);

    for (int i = 0; i < N; ++i)
      if (mx[i] - mn[i] <= k)
        return i;

    return -1;
  }
};
