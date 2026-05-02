/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxRotateFunction(vector<int> &nums) {
    const int N = nums.size();
    int s = 0, f = 0;

    for (int i = 0; i < N; i++) {
      s += nums[i];
      f += i * nums[i];
    }

    int ans = f;

    for (int i = N - 1; i > 0; --i) {
      f += s - N * nums[i];
      ans = max(ans, f);
    }

    return ans;
  }
};
